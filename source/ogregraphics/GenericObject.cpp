#include "StdAfx.h"
#include "GenericObject.h"

using namespace Objects;

GenericObject::GenericObject()
{
	setID();
}

GenericObject::GenericObject(Ogre::Vector3 pos, Ogre::Vector3 rot, std::string meshFile)
{
	setID();
	m_position = pos;
	m_filename = meshFile;

	loadMesh();

	setRoll(rot.x);
	setYaw(rot.y);
	setPitch(rot.z);
}

GenericObject::GenericObject(Ogre::Vector3 pos, Ogre::Quaternion rot, Ogre::Vector3 scale, std::string meshFile)
{
	setID();
	m_position = pos;
	m_filename = meshFile;

	loadMesh();

	setOrientation(rot);
	setScale(scale);
}


GenericObject::~GenericObject(void)
{
}

void GenericObject::initialise()
{

}

void GenericObject::update( float deltaTime )
{
	IObject::update( deltaTime ); // must always be the last part
}