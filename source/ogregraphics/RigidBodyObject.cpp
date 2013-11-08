#include "StdAfx.h"
#include "RigidBodyObject.h"

using namespace Objects;

RigidBodyObject::RigidBodyObject(std::string meshFile)
{
	setID();
	m_filename = meshFile;
	loadMesh();
	getEntity()->setUserAny((Ogre::Any)(GenericObject*)this);
	Type = "RigidBodyObject";
	getEntity()->setQueryFlags(Targetable);

	m_force = Ogre::Vector3(0.0f, 0.0f, 0.0f);
	m_mass = 1.0f;

	m_acceleration = Ogre::Vector3(0.0f, 0.0f, 0.0f);
	m_velocity = Ogre::Vector3(0.0f, 0.0f, 0.0f);
	m_position = Ogre::Vector3(0.0f, 0.0f, 0.0f);

	m_inertiaTensor = Ogre::Matrix3::ZERO;
	m_invInertiaTensor = Ogre::Matrix3::ZERO;

	m_angularVelocity = Ogre::Vector3(0.0f, 0.0f, 0.0f);
}


RigidBodyObject::~RigidBodyObject(void)
{
}

void RigidBodyObject::initialise()
{
	
}

void RigidBodyObject::update( float deltaTime )
{
	// velocity vertlet
	m_lastAcceleration = m_acceleration;
	m_position += m_velocity * deltaTime + (0.5 * m_lastAcceleration * deltaTime * deltaTime);
	
	if( m_mass > 0.0f )
		m_acceleration = m_force / m_mass;
	
	Ogre::Vector3 avgAcceleration = (( m_lastAcceleration - m_acceleration ) / 2.0f) + Physics::PhysicsEngine::GRAVITY;

	m_velocity += avgAcceleration * deltaTime;

	m_force = Ogre::Vector3::ZERO;

	if(m_position.y < 0) m_velocity.y *= -0.8; // bouncing

	//rotateByVector(m_angularVelocity, Core::Game::getGraphics()->getDeltaTime());
	
	GenericObject::update( deltaTime ); // must always be the last part

	calculateTransformMatrix(m_transformMatrix, getPosition(), getOrientation());
	transformInertiaTensor(m_invInertiaTensorWorld, getOrientation(), m_invInertiaTensor, m_transformMatrix);
}

void RigidBodyObject::applyForce(Ogre::Vector3 force)
{
	m_force = force;
}

void RigidBodyObject::setMass(float mass)
{
	m_mass = mass;
	m_invMass = 1.0f / mass;
}

void RigidBodyObject::addVelocity(Ogre::Vector3& velocity)
{
	m_velocity += velocity;
}

void RigidBodyObject::addRotation(Ogre::Vector3& rotation)
{
	m_angularVelocity += rotation;
}

Ogre::Matrix3 RigidBodyObject::InertiaTensorSolidSphere(float radius, float mass)
{
	Ogre::Matrix3 tensor = Ogre::Matrix3::ZERO;

	tensor[0][0] = (2.0f/5.0f) * mass * radius * radius;
	tensor[1][1] = (2.0f/5.0f) * mass * radius * radius;
	tensor[2][2] = (2.0f/5.0f) * mass * radius * radius;

	return tensor;
}

Ogre::Matrix3 RigidBodyObject::InertiaTensorSphereShell(float radius, float mass)
{
	Ogre::Matrix3 tensor = Ogre::Matrix3::ZERO;

	tensor[0][0] = (2.0f/3.0f) * mass * radius * radius;
	tensor[1][1] = (2.0f/3.0f) * mass * radius * radius;
	tensor[2][2] = (2.0f/3.0f) * mass * radius * radius;

	return tensor;
}

Ogre::Matrix3 RigidBodyObject::InertiaTensorCuboid(float width, float height, float depth, float mass)
{
	Ogre::Matrix3 tensor = Ogre::Matrix3::ZERO;

	tensor[0][0] = (1.0f/12.0f) * mass * (height * height + depth * depth);
	tensor[1][1] = (1.0f/12.0f) * mass * (height * height + depth * depth);
	tensor[2][2] = (1.0f/12.0f) * mass * (height * height + depth * depth);

	return tensor;
}

Ogre::Matrix3 RigidBodyObject::InertiaTensorSolidCylinder(float radius, float height, float mass)
{
	Ogre::Matrix3 tensor = Ogre::Matrix3::ZERO;

	tensor[0][0] = (1.0f/12.0f) * mass * (3 * radius * radius + height * height);
	tensor[1][1] = (1.0f/12.0f) * mass * (3 * radius * radius + height * height);
	tensor[2][2] = (1.0f/12.0f) * mass * (3 * radius * radius + height * height);

	return tensor;
}

void RigidBodyObject::setInertiaTensor(Ogre::Matrix3 tensor)
{
	m_inertiaTensor = tensor;
	m_invInertiaTensor = m_inertiaTensor.Transpose();
}

void RigidBodyObject::calculateTransformMatrix(Ogre::Matrix4& transform, const Ogre::Vector3 &pos, const Ogre::Quaternion &orientation)
{
	// i = x, j = y, k = z, r = w 
	transform[0][0] = 1 - 2 * orientation.y * orientation.y - 2 * orientation.z * orientation.z;
	transform[0][1] = 2 * orientation.x * orientation.y - 2 * orientation.w * orientation.z;
	transform[0][2] = 2 * orientation.x * orientation.z - 2 * orientation.w * orientation.y;
	transform[0][3] = pos.x;

	transform[0][0] = 2 * orientation.x * orientation.y - 2 * orientation.w * orientation.z;
	transform[0][1] = 1 - 2 * orientation.x * orientation.x - 2 * orientation.z * orientation.z;
	transform[0][2] = 2 * orientation.y * orientation.z - 2 * orientation.w * orientation.x;
	transform[0][3] = pos.y;

	transform[0][0] = 2 * orientation.x * orientation.z - 2 * orientation.w * orientation.y;
	transform[0][1] = 2 * orientation.y * orientation.z - 2 * orientation.w * orientation.x;
	transform[0][2] = 1 - 2 * orientation.x * orientation.x - 2 * orientation.y * orientation.y;
	transform[0][3] = pos.z;
}

void RigidBodyObject::transformInertiaTensor(Ogre::Matrix3& iitWorld, const Ogre::Quaternion& quat, const Ogre::Matrix3& iitBody, const Ogre::Matrix4& rotMat)
{
	float t4 = rotMat[0][0] * iitBody[0][0] + rotMat[0][1] * iitBody[1][0] + rotMat[0][2] * iitBody[2][0];
	float t9 = rotMat[0][0] * iitBody[0][1] + rotMat[0][1] * iitBody[1][1] + rotMat[0][2] * iitBody[2][1];
	float t14 = rotMat[0][0] * iitBody[0][2] + rotMat[0][1] * iitBody[1][2] + rotMat[0][2] * iitBody[2][2];

	float t28 = rotMat[1][0] * iitBody[0][0] + rotMat[1][1] * iitBody[1][0] + rotMat[1][2] * iitBody[2][0];
	float t33 = rotMat[1][0] * iitBody[0][1] + rotMat[1][1] * iitBody[1][1] + rotMat[1][2] * iitBody[2][1];
	float t38 = rotMat[1][0] * iitBody[0][2] + rotMat[1][1] * iitBody[1][2] + rotMat[1][2] * iitBody[2][2];

	float t52 = rotMat[2][0] * iitBody[0][0] + rotMat[2][1] * iitBody[1][0] + rotMat[2][2] * iitBody[2][0];
	float t57 = rotMat[2][0] * iitBody[0][1] + rotMat[2][1] * iitBody[1][1] + rotMat[2][2] * iitBody[2][1];
	float t62 = rotMat[2][0] * iitBody[0][2] + rotMat[2][1] * iitBody[1][2] + rotMat[2][2] * iitBody[2][2];

	iitWorld[0][0] = t4 * rotMat[0][0] + t9 * rotMat[0][1] + t14 * rotMat[0][2];
	iitWorld[0][1] = t4 * rotMat[0][0] + t9 * rotMat[0][1] + t14 * rotMat[0][2];
	iitWorld[0][2] = t4 * rotMat[0][0] + t9 * rotMat[0][1] + t14 * rotMat[0][2];
	iitWorld[1][0] = t28 * rotMat[0][0] + t33 * rotMat[0][1] + t38 * rotMat[0][2];
	iitWorld[1][1] = t28 * rotMat[0][0] + t33 * rotMat[0][1] + t38 * rotMat[0][2];
	iitWorld[1][2] = t28 * rotMat[0][0] + t33 * rotMat[0][1] + t38 * rotMat[0][2];
	iitWorld[2][0] = t52 * rotMat[0][0] + t57 * rotMat[0][1] + t62 * rotMat[0][2];
	iitWorld[2][1] = t52 * rotMat[0][0] + t57 * rotMat[0][1] + t62 * rotMat[0][2];
	iitWorld[2][2] = t52 * rotMat[0][0] + t57 * rotMat[0][1] + t62 * rotMat[0][2];
}