#include "StdAfx.h"
#include "TargetObject.h"

using namespace Objects;

TargetObject::TargetObject(void) : RigidBodyObject("Target.mesh")
{
	//m_collisionObject = new CollisionObject();
	//m_collisionObject->AddMeshShape(getEntity());
	MakeCollisionObject();
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
	ColObj->SetPosition(m_position.x,m_position.y+30,m_position.z);
	//ColObj->SetObjectOrientation(0,0,1,90);
	//ColObj->SetObjectOrientation(Math::Vector3(0,0,1),90);
	//ColObj->SetPosition(getPosition().x,getPosition().y,getPosition().z); 
	//cout<<"///////////////////////////////////////"<<getPosition().y<<"/////////////////////////////\n";
}