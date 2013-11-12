#pragma once

#include "IObject.h"

namespace Objects
{
	class IObject;
};

namespace Objects
{
	class GenericObject :
		public IObject
	{
	public:
		GenericObject();
		GenericObject(Ogre::Vector3 pos, Ogre::Vector3 rot, std::string meshFile);
		GenericObject(Ogre::Vector3 pos, Ogre::Quaternion rot, Ogre::Vector3 scale, std::string meshFile);
		~GenericObject(void);
		//bool Generic;
		virtual void initialise();
		virtual void update( float deltaTime );
	};
}