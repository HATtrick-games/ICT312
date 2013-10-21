#pragma once

#include "PhysicsEngine.h"
#include "IObject.h"
//#include "GenericObject.h"
#include "Force.h"
//#include "Contact.h"
//#include "CollisionObject.h"

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

		void setAngularVelocity(Ogre::Vector3 axis, float angle);

		void applyForce(Ogre::Vector3 force);
		void applyForce(Physics::Force force);

		void setVelocity(Ogre::Vector3 vel) { m_velocity = vel; }
		Ogre::Vector3 getVelocity() { return m_velocity; }

		float getMass() { return m_mass; }
		void setMass(float mass);
	protected:
		Ogre::Vector3 m_force;

		float m_mass;
		Ogre::Matrix3 m_momentOfInertia;

		Ogre::Vector3 m_acceleration;
		Ogre::Vector3 m_velocity;

		Ogre::Vector3 m_lastAcceleration;

		std::vector<Physics::Force> m_forces;
//		std::vector<Physics::Contact> m_contacts;

//		CollisionObject* m_collisionObject;
	};
}