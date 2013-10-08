#pragma once

#include "GenericObject.h"

namespace Physics
{
	struct Manifold
	{
		Objects::GenericObject* A;
		Objects::GenericObject* B;
		Ogre::Vector3 normal; // the normal to the collision
		float penetration;
	};
}