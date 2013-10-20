#include "StdAfx.h"
#include "TargetObject.h"

using namespace Objects;

TargetObject::TargetObject(void) : RigidBodyObject("Target.mesh")
{
	m_collisionObject = new CollisionObject();
	m_collisionObject->AddMeshShape(getEntity());
	Core::Game::getGraphics()->getDebugDrawer()->drawSphere(Ogre::Vector3(0, 0, 0), 3, Ogre::ColourValue::Red, true);
}


TargetObject::~TargetObject(void)
{
}

void TargetObject::initialise()
{
	
	m_mass = 2.0f;
	m_force = Ogre::Vector3(0.0f, 0.0f, 0.0f);
}

void TargetObject::update( float deltaTime )
{
	

	RigidBodyObject::update(deltaTime);
}