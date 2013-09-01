#pragma once

namespace Collision
{
	struct AABB
	{
		Ogre::Vector3 min;
		Ogre::Vector3 max;

		AABB(void) { min = Ogre::Vector3(); max = Ogre::Vector3(); }
		AABB( Ogre::Vector3 min, float dx, float dy, float dz )
		{
			this->min = min;
			this->max = min + Ogre::Vector3(dx, dy, dz);
		}
	};
}
