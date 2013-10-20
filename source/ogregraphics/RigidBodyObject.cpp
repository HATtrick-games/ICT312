#include "StdAfx.h"
#include "RigidBodyObject.h"

using namespace Objects;

RigidBodyObject::RigidBodyObject(std::string meshFile)
{
	setID();
	m_filename = meshFile;
	loadMesh();

	m_force = Ogre::Vector3(0.0f, 0.0f, 0.0f);
	m_mass = 1.0f;

	m_acceleration = Ogre::Vector3(0.0f, 0.0f, 0.0f);
	m_velocity = Ogre::Vector3(0.0f, 0.0f, 0.0f);
	m_position = Ogre::Vector3(0.0f, 0.0f, 0.0f);
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

	//checkPosition();
	
	GenericObject::update( deltaTime ); // must always be the last part
}

void RigidBodyObject::applyForce(Ogre::Vector3 force)
{
	m_force = force;
}