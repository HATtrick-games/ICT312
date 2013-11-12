#include "StdAfx.h"
#include "GenericObject.h"

using namespace Objects;

GenericObject::GenericObject()
{
	isDynamic = false;
	setID();
	AI = -1;

}

GenericObject::GenericObject(Ogre::Vector3 pos, Ogre::Vector3 rot, std::string meshFile)
{
	isDynamic = false;
	setID();
	m_position = pos;
	m_filename = meshFile;
	AI = -1;
	loadMesh();

	setRoll(rot.x);
	setYaw(rot.y);
	setPitch(rot.z);
	MakeCollisionObject();
	Type = "RigidBodyObject";
	getEntity()->setQueryFlags(Targetable);
	getEntity()->setUserAny((Ogre::Any)(GenericObject*)this);
}

GenericObject::GenericObject(Ogre::Vector3 pos, Ogre::Quaternion rot, Ogre::Vector3 scale, std::string meshFile)
{
	isDynamic = false;
	AI = -1;
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
		
	Type = "RigidBodyObject";
	getEntity()->setQueryFlags(Targetable);
	getEntity()->setUserAny((Ogre::Any)(GenericObject*)this);
	
}


GenericObject::~GenericObject(void)
{
}

void GenericObject::initialise()
{
	Generic = true;
	Affordances["UseComputer"] = 0;
	Affordances["Sit"] = 0;
}

void GenericObject::update( float deltaTime )
{
	
	IObject::update( deltaTime ); // must always be the last part
	
}