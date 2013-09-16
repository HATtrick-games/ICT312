#include "StdAfx.h"
#include "IObject.h"

using namespace Objects;

int IObject::m_objCount = 0;

void IObject::update( float deltaTime )
{
	Core::Game::getGraphics()->setEntityPosition( m_entity, 
		m_position.x, m_position.y, m_position.z );
}

Ogre::Vector3 IObject::getPosition()
{
	return m_position;
}

void IObject::setPosition( Ogre::Vector3 pos )
{
	m_position = pos;
}

void IObject::changePosition( Ogre::Vector3 pos )
{
	m_position += pos;
}

Ogre::Quaternion IObject::getOrientation() const
{
	return Core::Game::getGraphics()->getEntityOrientation( m_entity );
}

void IObject::loadMesh() const
{
	Core::Game::getGraphics()->createMeshEntity( m_entity, m_filename );
}

void IObject::setYaw( float angle )
{
	Core::Game::getGraphics()->setEntityYaw( m_entity, angle );
}

void IObject::setPitch( float angle )
{
	Core::Game::getGraphics()->setEntityPitch( m_entity, angle );
}

void IObject::setRoll( float angle )
{
	Core::Game::getGraphics()->setEntityRoll( m_entity, angle );
}

void IObject::setID()
{
	m_id = m_objCount;
	m_objCount++;

	std::ostringstream idString;
	idString << m_id;
	
	m_entity = "entity" + idString.str();
}

std::string IObject::getEntity()
{
	return m_entity;
}