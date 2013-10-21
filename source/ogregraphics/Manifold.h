#pragma once

#include "RigidBodyObject.h"
#include "Contact.h"

namespace Objects
{
	class RigidBodyObject;
};

namespace Physics
{
	struct Manifold
	{
		Objects::RigidBodyObject* A;
		Objects::RigidBodyObject* B;
		
		Ogre::Vector3 normal; // the normal to the collision
		float penetration;
	};
}