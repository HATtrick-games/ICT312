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

	return true;
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
	return Ogre::Vector3();
}

Ogre::Quaternion SceneLoader::parseQuaternion(rapidxml::xml_node<>* XMLnode)
{
	return Ogre::Quaternion();
}

