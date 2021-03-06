#pragma once

#include "RigidBodyObject.h"

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

		int numContacts;
		Ogre::Vector3 contacts[2];
	};
}