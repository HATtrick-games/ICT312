#pragma once

#include "IObject.h"

namespace Objects
{
	class GenericObject :
		public IObject
	{
	public:
		GenericObject(Ogre::Vector3 pos, Ogre::Vector3 rot, std::string meshFile);
		~GenericObject(void);

		virtual void initialise();
		virtual void update( float deltaTime );
	};
}