#include "StdAfx.h"
#include "RigidBodyObject.h"

using namespace Objects;

RigidBodyObject::RigidBodyObject(void)
{
	m_force = Ogre::Vector3();
	m_mass = 10.0f; // 10.0kg

	m_position = Ogre::Vector3();
	m_acceleration = Ogre::Vector3();
	m_velocity = Ogre::Vector3();
}


RigidBodyObject::~RigidBodyObject(void)
{
}

void RigidBodyObject::initialise()
{

}

void RigidBodyObject::update( float deltaTime )
{
	m_acceleration = m_force * m_mass;

	Ogre::Vector3 deltaVel = Core::Game::getGraphics()->getDeltaTime() * m_acceleration;
	m_velocity += deltaVel;

	changePosition( Core::Game::getGraphics()->getDeltaTime() * m_velocity);

	checkPosition();
	
	IObject::update( deltaTime ); // must always be the last part
}

void RigidBodyObject::checkPosition()
{
	//Physics::Constants::clamp(m_position.x, Physics::Constants::MIN_X, Physics::Constants::MAX_X);
	//Physics::Constants::clamp(m_position.y, Physics::Constants::MIN_Y, Physics::Constants::MAX_Y);
	//Physics::Constants::clamp(m_position.z, Physics::Constants::MIN_Z, Physics::Constants::MAX_Z);
}