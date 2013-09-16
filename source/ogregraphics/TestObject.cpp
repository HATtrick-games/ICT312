#include "StdAfx.h"
#include "TestObject.h"

using namespace Objects;

TestObject::TestObject(void)
{
	m_position = Ogre::Vector3( 0, 200, 0 );
	m_filename = "models/boxmesh.mesh";
	setID();
}


TestObject::~TestObject(void)
{
}

void TestObject::initialise()
{
	loadMesh();
}

void TestObject::update( float deltaTime )
{
	//Core::Game::getGraphics()->setEntityPosition( m_entity, 50.0f, 0.0f, 0.0f );
	// nothing here..yet

	IObject::update( deltaTime ); // must always be the last part
}