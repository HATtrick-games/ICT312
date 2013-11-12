#include "StdAfx.h"
#include "SceneLoader.h"

using namespace Scenes;

bool SceneLoader::loadScene(std::string sceneFile)
{
	rapidxml::xml_document<> XMLdoc;
	rapidxml::xml_node<>* XMLroot;
	rapidxml::file<> xmlFile(sceneFile.c_str());
	
	XMLdoc.parse<0>(xmlFile.data());

	// get the root scene node
	XMLroot = XMLdoc.first_node("scene");

	if( getAttrib(XMLroot, "formatVersion", "") == "" )
	{
		Ogre::LogManager::getSingleton().logMessage("[SceneLoader] Error: Invalid .scene File. Missing <scene>");
		return false;
	}

	processScene(XMLroot);

	return true;
}

void SceneLoader::processScene(rapidxml::xml_node<>* XMLroot)
{
	std::string version = getAttrib(XMLroot, "formatVersion", "unknown");

	std::string message = "[SceneLoader] Parsing .scene file with version " + version;
	if(XMLroot->first_attribute("ID"))
		message += ", id " + Ogre::String(XMLroot->first_attribute("ID")->value());
	if(XMLroot->first_attribute("sceneManager"))
		message += ", scene manager " + Ogre::String(XMLroot->first_attribute("sceneManager")->value());
	if(XMLroot->first_attribute("minOgreVersion"))
		message += ", min. Ogre version " + Ogre::String(XMLroot->first_attribute("minOgreVersion")->value());
	if(XMLroot->first_attribute("author"))
		message += ", author " + Ogre::String(XMLroot->first_attribute("author")->value());

	Ogre::LogManager::getSingleton().logMessage(message);

	rapidxml::xml_node<>* element;

	// process nodes
	element = XMLroot->first_node("nodes");
	if(element)
		processNodes(element);
}

void SceneLoader::processNodes(rapidxml::xml_node<>* XMLnode)
{
	rapidxml::xml_node<>* element;

	element = XMLnode->first_node("node");
	while(element)
	{
		processNode(element);
		element = element->next_sibling("node");
	}

	element = XMLnode->first_node("position");
	if(element)
	{
		std::cout << "[SceneLoader] " << parseVector3(element) << std::endl; 
	}

	element = XMLnode->first_node("rotation");
	if(element)
	{
		std::cout << "[SceneLoader] " << parseQuaternion(element) << std::endl; 
	}

	element = XMLnode->first_node("scale");
	if(element)
	{
		std::cout << "[SceneLoader] " << parseVector3(element) << std::endl; 
	}
}

void SceneLoader::processNode(rapidxml::xml_node<>* XMLnode)
{
	Ogre::Vector3 position, scale;
	Ogre::Quaternion rotation;
	std::string meshFile;

	std::string name = getAttrib(XMLnode, "name", "") + getAttrib(XMLnode, "id", "");
	if(name.empty())
	{
		return;
	}

	bool isTarget = getAttribBool(XMLnode, "isTarget", false);

	rapidxml::xml_node<>* element;

	element = XMLnode->first_node("position");
	if(element)
	{
		position = parseVector3(element);
	}

	element = XMLnode->first_node("rotation");
	if(element)
	{
		rotation = parseQuaternion(element);
	}

	element = XMLnode->first_node("scale");
	if(element)
	{
		scale = parseVector3(element);
	}

	element = XMLnode->first_node("entity");
	if(element)
	{
		processEntity(element, name, position, rotation, scale);

		element = element->next_sibling("entity");
	}
}

void SceneLoader::processEntity(rapidxml::xml_node<>* XMLnode, std::string entityName, Ogre::Vector3 pos, Ogre::Quaternion rot, Ogre::Vector3 scale)
{
	// process attributes
	std::string name = getAttrib(XMLnode, "name", "");
	std::string id = getAttrib(XMLnode, "id", "");
	std::string meshFile = getAttrib(XMLnode, "meshFile", "");
	std::string materialFile = getAttrib(XMLnode, "materialFile", "");

	if(!meshFile.empty())
	{
		try
		{
			m_scene->addObject(entityName, new Objects::RigidBodyObject(pos, rot, scale, meshFile));
		}
		catch (Ogre::Exception &)
		{
			Ogre::LogManager::getSingleton().logMessage("[SceneLoader] Error loading an entity!");
		}
	}
}

std::string SceneLoader::getAttrib(rapidxml::xml_node<>* XMLnode, const std::string &attrib, const std::string default)
{
	if(XMLnode->first_attribute(attrib.c_str()))
		return XMLnode->first_attribute(attrib.c_str())->value();
	else
		return default;
}

float SceneLoader::getAttribFloat(rapidxml::xml_node<>* XMLnode, const std::string &attrib, const float default)
{
	if(XMLnode->first_attribute(attrib.c_str()))
		return Ogre::StringConverter::parseReal(XMLnode->first_attribute(attrib.c_str())->value());
	else
		return default;
}

bool SceneLoader::getAttribBool(rapidxml::xml_node<>* XMLnode, const std::string &attrib, const bool default)
{
	if(!XMLnode->first_attribute(attrib.c_str()))
		return default;

	if(Ogre::String(XMLnode->first_attribute(attrib.c_str())->value()) == "true")
		return true;

	return false;
}

Ogre::Vector3 SceneLoader::parseVector3(rapidxml::xml_node<>* XMLnode)
{
	return Ogre::Vector3(
		Ogre::StringConverter::parseReal(XMLnode->first_attribute("x")->value()),
		Ogre::StringConverter::parseReal(XMLnode->first_attribute("y")->value()),
		Ogre::StringConverter::parseReal(XMLnode->first_attribute("z")->value())
		);
}

Ogre::Quaternion SceneLoader::parseQuaternion(rapidxml::xml_node<>* XMLnode)
{
	Ogre::Quaternion orientation;

	if(XMLnode->first_attribute("qx"))
	{
		orientation.x = Ogre::StringConverter::parseReal(XMLnode->first_attribute("qx")->value());
		orientation.y = Ogre::StringConverter::parseReal(XMLnode->first_attribute("qy")->value());
		orientation.z = Ogre::StringConverter::parseReal(XMLnode->first_attribute("qz")->value());
		orientation.w = Ogre::StringConverter::parseReal(XMLnode->first_attribute("qw")->value());
	}

	return orientation;
}

