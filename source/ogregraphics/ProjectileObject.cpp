#include "StdAfx.h"
#include "ProjectileObject.h"

using namespace Objects;

ProjectileObject::ProjectileObject(Ogre::Vector3 pos)
{
	setID();
	m_filename = "Projectile.mesh";
	m_position = pos;
	loadMesh();
	//MakeCollisionObject();
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