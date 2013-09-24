#pragma once

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>

namespace Scenes
{
	class SceneLoader
	{
	public:
		SceneLoader() {};
		bool loadScene(std::string sceneFile);

	private:
		void processScene(rapidxml::xml_node<>* XMLroot);

		void processNodes(rapidxml::xml_node<>* XMLnode);

		std::string getAttrib(rapidxml::xml_node<>* XMLnode, const std::string &attrib, const std::string default);
		float getAttribFloat(rapidxml::xml_node<>* XMLnode, const std::string &attrib, const float default);
		bool getAttribBool(rapidxml::xml_node<>* XMLnode, const std::string &attrib, const bool default);

		Ogre::Vector3 parseVector3(rapidxml::xml_node<>* XMLnode);
		Ogre::Quaternion parseQuaternion(rapidxml::xml_node<>* XMLnode);
	};
}