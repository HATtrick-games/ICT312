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
	MakeCollisionObject();
}

GenericObject::GenericObject(Ogre::Vector3 pos, Ogre::Quaternion rot, Ogre::Vector3 scale, std::string meshFile)
{
	setID();
	m_position = pos;
	m_filename = meshFile;

	loadMesh();

	setOrientation(rot);
	setScale(scale);
	MakeCollisionObject();
	/*if(meshFile == "SofaGreen.mesh")
	{
	std::cout<<meshFile;
		Sleep(1000);
	MakeCollisionObject();
	}
	if(meshFile == "CornerTable.mesh")
	{
	std::cout<<meshFile;
		Sleep(1000);
	MakeCollisionObject();
	}
	if(meshFile == "CornerTable_1.mesh")
	{
	std::cout<<meshFile;
		Sleep(1000);
	MakeCollisionObject();
	}*/
	//	std::cout<<"TABLE IS MADE HERE \n\n\n\n";
		
	
	
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