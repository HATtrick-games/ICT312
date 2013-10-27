#include "StdAfx.h"
#include "ProjectileObject.h"

using namespace Objects;

ProjectileObject::ProjectileObject(Ogre::Vector3 pos) : RigidBodyObject("Projectile.mesh")
{
	m_position = pos;
	MakeBoxCollisionObject();
}


ProjectileObject::~ProjectileObject(void)
{
}

void ProjectileObject::initialise()
{
	m_mass = 0.1f;
	m_force = Ogre::Vector3(0.0f, 0.0f, 0.0f);
	setInertiaTensor(InertiaTensorSolidSphere(3.0f, 0.1f));
}

void ProjectileObject::update(float deltaTime)
{
	//std::cout << getPosition() << std::endl;
	std::cout << m_velocity << std::endl;

	RigidBodyObject::update(deltaTime);
	ColObj->SetPosition(m_position.x,m_position.y,m_position.z);
}