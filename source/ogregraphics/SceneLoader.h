#pragma once

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include "GenericObject.h"
#include "IScene.h"

namespace Objects
{
	class GenericObject;
};

namespace Scenes
{
	class IScene;

	class SceneLoader
	{
	public:
		SceneLoader() {}
		SceneLoader(Scenes::IScene* scene) { m_scene = scene; }
		bool loadScene(std::string sceneFile);

	private:
		Scenes::IScene* m_scene;

		void processScene(rapidxml::xml_node<>* XMLroot);

		void processNodes(rapidxml::xml_node<>* XMLnode);
		void processNode(rapidxml::xml_node<>* XMLnode);
		void processEntity(rapidxml::xml_node<>* XMLnode);

		std::string getAttrib(rapidxml::xml_node<>* XMLnode, const std::string &attrib, const std::string default);
		float getAttribFloat(rapidxml::xml_node<>* XMLnode, const std::string &attrib, const float default);
		bool getAttribBool(rapidxml::xml_node<>* XMLnode, const std::string &attrib, const bool default);

		Ogre::Vector3 parseVector3(rapidxml::xml_node<>* XMLnode);
		Ogre::Quaternion parseQuaternion(rapidxml::xml_node<>* XMLnode);
	};
}