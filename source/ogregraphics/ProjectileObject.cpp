#include "StdAfx.h"
#include "ProjectileObject.h"

using namespace Objects;

ProjectileObject::ProjectileObject(Ogre::Vector3 pos) : RigidBodyObject("Projectile.mesh")
{
	m_collisionObject = new CollisionObject();
	m_collisionObject->AddMeshShape(getEntity());
	m_position = pos;
}


ProjectileObject::~ProjectileObject(void)
{
}

void ProjectileObject::initialise()
{
	m_mass = 0.1f;
}

void ProjectileObject::update(float deltaTime)
{
	//std::cout << getPosition() << std::endl;
	//std::cout << m_velocity << std::endl;

	RigidBodyObject::update(deltaTime);
}