#pragma once

#include "RigidBodyObject.h"
#include "Manifold.h"

namespace Physics
{
	class PhysicsEngine
	{
	public:
		static Ogre::Vector3 GRAVITY;

		static void ResolveCollision(Physics::Manifold& manifold);
		static void ApplyImpulse(Physics::Manifold& manifold);

		static bool AABBvsAABB(Physics::Manifold& manifold);
	};
}