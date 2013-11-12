/**
 * \file	RigidBodyObject.h
 *
 * \brief	Declares the rigid body object class.
 */

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
	/**
	 * \class	RigidBodyObject
	 *
	 * \brief	Rigid body object.
	 */

	class RigidBodyObject :
		public GenericObject
	{
	public:

		/**
		 * \fn	RigidBodyObject::RigidBodyObject(std::string meshFile);
		 *
		 * \brief	Constructor.
		 *
		 * \param	meshFile	The mesh file.
		 */

		RigidBodyObject(std::string meshFile);

		/**
		 * \fn	RigidBodyObject::RigidBodyObject(Ogre::Vector3 pos, Ogre::Quaternion rot,
		 *  Ogre::Vector3 scale, std::string meshFile);
		 *
		 * \brief	Constructor.
		 *
		 * \param	pos			The position.
		 * \param	rot			The rot.
		 * \param	scale   	The scale.
		 * \param	meshFile	The mesh file.
		 */

		RigidBodyObject(Ogre::Vector3 pos, Ogre::Quaternion rot, Ogre::Vector3 scale, std::string meshFile);

		/**
		 * \fn	RigidBodyObject::~RigidBodyObject(void);
		 *
		 * \brief	Destructor.
		 */

		~RigidBodyObject(void);

		/**
		 * \fn	virtual void RigidBodyObject::initialise();
		 *
		 * \brief	Initialises this object.
		 */

		virtual void		initialise();

		/**
		 * \fn	virtual void RigidBodyObject::update( float deltaTime );
		 *
		 * \brief	Updates the given deltaTime.
		 *
		 * \param	deltaTime	Time of the delta.
		 */

		virtual void		update( float deltaTime );

		/**
		 * \fn	void RigidBodyObject::setAngularVelocity(Ogre::Vector3 axis, float angle);
		 *
		 * \brief	Sets angular velocity.
		 *
		 * \param	axis 	The axis.
		 * \param	angle	The angle.
		 */

		void setAngularVelocity(Ogre::Vector3 axis, float angle);

		/**
		 * \fn	void RigidBodyObject::applyForce(Ogre::Vector3 force);
		 *
		 * \brief	Applies the force described by force.
		 *
		 * \param	force	The force.
		 */

		void applyForce(Ogre::Vector3 force);

		/**
		 * \fn	void RigidBodyObject::setVelocity(Ogre::Vector3 vel)
		 *
		 * \brief	void applyForce(Physics::Force force);
		 *
		 * \param	vel	The velocity.
		 */

		void setVelocity(Ogre::Vector3 vel) { m_velocity = vel; }

		/**
		 * \fn	Ogre::Vector3 RigidBodyObject::getVelocity()
		 *
		 * \brief	Gets the velocity.
		 *
		 * \return	The velocity.
		 */

		Ogre::Vector3 getVelocity() { return m_velocity; }

		/**
		 * \fn	Ogre::Vector3 RigidBodyObject::getLastAcceleration()
		 *
		 * \brief	Gets the last acceleration.
		 *
		 * \return	The last acceleration.
		 */

		Ogre::Vector3 getLastAcceleration() { return m_lastAcceleration; }

		/**
		 * \fn	float RigidBodyObject::getMass()
		 *
		 * \brief	Gets the mass.
		 *
		 * \return	The mass.
		 */

		float getMass() { return m_mass; }

		/**
		 * \fn	void RigidBodyObject::setMass(float mass);
		 *
		 * \brief	Sets the mass.
		 *
		 * \param	mass	The mass.
		 */

		void setMass(float mass);

		/**
		 * \fn	float RigidBodyObject::getInverseMass()
		 *
		 * \brief	Gets inverse mass.
		 *
		 * \return	The inverse mass.
		 */

		float getInverseMass() { return m_invMass; }

		/**
		 * \fn	void RigidBodyObject::addVelocity(Ogre::Vector3& velocity);
		 *
		 * \brief	Adds a velocity.
		 *
		 * \param [in,out]	velocity	The velocity.
		 */

		void addVelocity(Ogre::Vector3& velocity);

		/**
		 * \fn	void RigidBodyObject::addRotation(Ogre::Vector3& rotation);
		 *
		 * \brief	Adds a rotation.
		 *
		 * \param [in,out]	rotation	The rotation.
		 */

		void addRotation(Ogre::Vector3& rotation);

		/**
		 * \fn	Ogre::Matrix3 RigidBodyObject::getInverseInertiaTensorWorld()
		 *
		 * \brief	Gets inverse inertia tensor world.
		 *
		 * \return	The inverse inertia tensor world.
		 */

		Ogre::Matrix3 getInverseInertiaTensorWorld() { return m_invInertiaTensorWorld; }

		/**
		 * \fn	void RigidBodyObject::setInertiaTensor(Ogre::Matrix3 tensor);
		 *
		 * \brief	Sets inertia tensor.
		 *
		 * \param	tensor	The tensor.
		 */

		void setInertiaTensor(Ogre::Matrix3 tensor);

		/**
		 * \fn	static Ogre::Matrix3 RigidBodyObject::InertiaTensorSolidSphere(float radius, float mass);
		 *
		 * \brief	Inertia tensor solid sphere.
		 *
		 * \param	radius	The radius.
		 * \param	mass  	The mass.
		 *
		 * \return	.
		 */

		static Ogre::Matrix3 InertiaTensorSolidSphere(float radius, float mass);

		/**
		 * \fn	static Ogre::Matrix3 RigidBodyObject::InertiaTensorSphereShell(float radius, float mass);
		 *
		 * \brief	Inertia tensor sphere shell.
		 *
		 * \param	radius	The radius.
		 * \param	mass  	The mass.
		 *
		 * \return	.
		 */

		static Ogre::Matrix3 InertiaTensorSphereShell(float radius, float mass);

		/**
		 * \fn	static Ogre::Matrix3 RigidBodyObject::InertiaTensorCuboid(float width, float height,
		 *  float depth, float mass);
		 *
		 * \brief	width in x, height in y, depth in z.
		 *
		 * \param	width 	The width.
		 * \param	height	The height.
		 * \param	depth 	The depth.
		 * \param	mass  	The mass.
		 *
		 * \return	.
		 */

		static Ogre::Matrix3 InertiaTensorCuboid(float width, float height, float depth, float mass);

		/**
		 * \fn	static Ogre::Matrix3 RigidBodyObject::InertiaTensorSolidCylinder(float radius,
		 *  float height, float mass);
		 *
		 * \brief	Inertia tensor solid cylinder.
		 *
		 * \param	radius	The radius.
		 * \param	height	The height.
		 * \param	mass  	The mass.
		 *
		 * \return	.
		 */

		static Ogre::Matrix3 InertiaTensorSolidCylinder(float radius, float height, float mass);

		/**
		 * \fn	static void RigidBodyObject::calculateTransformMatrix(Ogre::Matrix4& transform,
		 *  const Ogre::Vector3 &pos, const Ogre::Quaternion &orientation);
		 *
		 * \brief	Calculates the transform matrix.
		 *
		 * \param [in,out]	transform	The transform.
		 * \param	pos				 	The position.
		 * \param	orientation		 	The orientation.
		 */

		static void calculateTransformMatrix(Ogre::Matrix4& transform, const Ogre::Vector3 &pos, const Ogre::Quaternion &orientation);

		/**
		 * \fn	static void RigidBodyObject::transformInertiaTensor(Ogre::Matrix3& iitWorld,
		 *  const Ogre::Quaternion& quat, const Ogre::Matrix3& iitBody, const Ogre::Matrix4& transMat);
		 *
		 * \brief	Transform inertia tensor.
		 *
		 * \param [in,out]	iitWorld	The iit world.
		 * \param	quat				The quaternion.
		 * \param	iitBody				The iit body.
		 * \param	transMat			The trans matrix.
		 */

		static void transformInertiaTensor(Ogre::Matrix3& iitWorld, const Ogre::Quaternion& quat, const Ogre::Matrix3& iitBody, const Ogre::Matrix4& transMat);
	protected:

		/**
		 * \brief	The force.
		 */

		Ogre::Vector3 m_force;

		/**
		 * \brief	The mass.
		 */

		float m_mass;

		/**
		 * \brief	The inverse mass.
		 */

		float m_invMass;

		/**
		 * \brief	The inertia tensor.
		 */

		Ogre::Matrix3 m_inertiaTensor;

		/**
		 * \brief	The inverse inertia tensor.
		 */

		Ogre::Matrix3 m_invInertiaTensor;

		/**
		 * \brief	The inverse inertia tensor world.
		 */

		Ogre::Matrix3 m_invInertiaTensorWorld;

		/**
		 * \brief	The transform matrix.
		 */

		Ogre::Matrix4 m_transformMatrix;

		/**
		 * \brief	The angular velocity.
		 */

		Ogre::Vector3 m_angularVelocity;

		/**
		 * \brief	The acceleration.
		 */

		Ogre::Vector3 m_acceleration;

		/**
		 * \brief	The velocity.
		 */

		Ogre::Vector3 m_velocity;

		/**
		 * \brief	The last acceleration.
		 */

		Ogre::Vector3 m_lastAcceleration;
		
		
	};
}