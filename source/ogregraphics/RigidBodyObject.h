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

		Ogre::Vector3 getLastAcceleration() { return m_lastAcceleration; }

		float getMass() { return m_mass; }
		void setMass(float mass);
		float getInverseMass() { return m_invMass; }

		void addVelocity(Ogre::Vector3& velocity);
		void addRotation(Ogre::Vector3& rotation);

		Ogre::Matrix3 getInverseInertiaTensorWorld();
	protected:
		Ogre::Vector3 m_force;

		float m_mass;
		float m_invMass;
		Ogre::Matrix3 m_momentOfInertia;
		Ogre::Matrix3 m_invInertiaTensor;
		Ogre::Matrix3 m_invInertiaTensorWorld;

		float m_angularVelocityAngle;
		Ogre::Vector3 m_angularVelocityAxis;

		Ogre::Vector3 m_acceleration;
		Ogre::Vector3 m_velocity;

		Ogre::Vector3 m_lastAcceleration;
		
		
	};
}