#pragma once

#include "PhysicsEngine.h"
#include "IObject.h"

namespace Objects
{
	class RigidBodyObject :
		public GenericObject
	{
	public:
		RigidBodyObject(std::string meshFile);
		~RigidBodyObject(void);

		virtual void		initialise();
		virtual void		update( float deltaTime );

		void applyForce(Ogre::Vector3 force);

	protected:
		Ogre::Vector3 m_force;

		float m_mass;
		Ogre::Matrix3 m_momentOfInertia;

		Ogre::Vector3 m_acceleration;
		Ogre::Vector3 m_velocity;

		Ogre::Vector3 m_lastAcceleration;

		CollisionObject* m_collisionObject;
	};
}