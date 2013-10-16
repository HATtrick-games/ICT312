#include "StdAfx.h"
#include "TargetObject.h"

using namespace Objects;

TargetObject::TargetObject(void) : RigidBodyObject("Target.mesh")
{
	/*setID();
	m_position = Ogre::Vector3(0.0f, 0.0f, 0.0f);
	m_filename = "Target.mesh";
	loadMesh();*/

	//RigidBodyObject("Target.mesh");

	//MakeCollisionObject();
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