#include "StdAfx.h"
#include "TargetObject.h"

using namespace Objects;

TargetObject::TargetObject(void)
{
	setID();
	m_position = Ogre::Vector3(0.0f, 0.0f, 0.0f);
	m_filename = "Target.mesh";
	loadMesh();
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