#pragma once
#include "Masks.h"
#include "PhysicsEngine.h"
//#include "IObject.h"
#include "GenericObject.h"
//#include "Force.h"
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
		//void applyForce(Physics::Force force);

		void setVelocity(Ogre::Vector3 vel) { m_velocity = vel; }
		Ogre::Vector3 getVelocity() { return m_velocity; }

		Ogre::Vector3 getLastAcceleration() { return m_lastAcceleration; }

		float getMass() { return m_mass; }
		void setMass(float mass);
		float getInverseMass() { return m_invMass; }

		void addVelocity(Ogre::Vector3& velocity);
		void addRotation(Ogre::Vector3& rotation);

		Ogre::Matrix3 getInverseInertiaTensorWorld() { return m_invInertiaTensorWorld; }

		void setInertiaTensor(Ogre::Matrix3 tensor);

		static Ogre::Matrix3 InertiaTensorSolidSphere(float radius, float mass);
		static Ogre::Matrix3 InertiaTensorSphereShell(float radius, float mass);
		// width in x, height in y, depth in z
		static Ogre::Matrix3 InertiaTensorCuboid(float width, float height, float depth, float mass);
		static Ogre::Matrix3 InertiaTensorSolidCylinder(float radius, float height, float mass);

		static void calculateTransformMatrix(Ogre::Matrix4& transform, const Ogre::Vector3 &pos, const Ogre::Quaternion &orientation);
		static void transformInertiaTensor(Ogre::Matrix3& iitWorld, const Ogre::Quaternion& quat, const Ogre::Matrix3& iitBody, const Ogre::Matrix4& transMat);
	protected:
		Ogre::Vector3 m_force;

		float m_mass;
		float m_invMass;
		Ogre::Matrix3 m_inertiaTensor;
		Ogre::Matrix3 m_invInertiaTensor;
		Ogre::Matrix3 m_invInertiaTensorWorld;

		Ogre::Matrix4 m_transformMatrix;

		Ogre::Vector3 m_angularVelocity;

		Ogre::Vector3 m_acceleration;
		Ogre::Vector3 m_velocity;

		Ogre::Vector3 m_lastAcceleration;
		
		
	};
}