#include "StdAfx.h"
#include "TargetObject.h"

using namespace Objects;

TargetObject::TargetObject(void) : RigidBodyObject("Target.mesh")
{
	MakeBoxCollisionObject();
} 


TargetObject::~TargetObject(void)
{
}

void TargetObject::initialise()
{
	m_mass = 2.0f;
	m_force = Ogre::Vector3(0.0f, 0.0f, 0.0f);
	setInertiaTensor(InertiaTensorCuboid(20.0f, 30.0f, 2.0f, 2.0f));
	//setYaw(0.84f);
}

void TargetObject::update( float deltaTime )
{
	RigidBodyObject::update(deltaTime);
	//ColObj->SetPosition(m_position.x,m_position.y,m_position.z);
	ColObj->SetPosition(getPosition().x,getPosition().y + 15,getPosition().z); 
	
	//ColObj->SetObjectOrientation(getOrientation());
	//ColObj->SetObjectOrientation(Math::Vector3(0,0,1),90);
	//cout<<"///////////////////////////////////////"<<getPosition().y<<"/////////////////////////////\n";
}