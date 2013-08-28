#include "StdAfx.h"
#include "TestObject.h"

using namespace Objects;

TestObject::TestObject(void)
{
	m_position = Ogre::Vector3( 0, 0, 0 );
	m_entity = "sinbad";
	m_filename = "Sinbad.mesh";
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