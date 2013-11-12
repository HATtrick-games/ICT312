#include "StdAfx.h"
#include "IObject.h"

using namespace Objects;

int IObject::m_objCount = 0;

void IObject::update( float deltaTime )
{
	Core::Game::getGraphics()->setEntityPosition( m_entity, 
		m_position.x, m_position.y, m_position.z );
}

void IObject::setMeshFile( std::string filename )
{
	m_filename = filename;
	if(!m_filename.empty()) loadMesh();
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

void IObject::setOrientation( Ogre::Quaternion rot )
{
	Core::Game::getGraphics()->setEntityOrientation( m_entity, rot );
}

void IObject::rotateByVector( Ogre::Vector3& rot, float scale )
{
	Ogre::Quaternion q(0, rot.x * scale, rot.y * scale, rot.z * scale);
	
	setOrientation(getOrientation() * q);
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

void IObject::setScale( float x, float y, float z )
{
	Core::Game::getGraphics()->setEntityScale( m_entity, Ogre::Vector3(x, y, z) );
}

void IObject::setScale( Ogre::Vector3 scale )
{
	Core::Game::getGraphics()->setEntityScale( m_entity, scale );
}

void IObject::setID()
{
	m_id = m_objCount;
	m_objCount++;

	std::ostringstream idString;
	idString << m_id;
	
	m_entity = "entity" + idString.str();
}

Ogre::Vector3 IObject::getScale()
{
	return(Core::Game::getGraphics()->getEntityScale(m_entity));
}

Ogre::Quaternion IObject::getOrientation()
{
	return(Core::Game::getGraphics()->getEntityOrientation(m_entity));
}

void IObject::MakeSphereCollisionObject()
{

	ColObj = new CollisionObject();
	ColObj->AddSphereShape(getEntity());
	ColObj->SetUserPointer(this);
	//ColObj->SetScale(2,2,2);
}



void IObject::MakeCollisionObject()
{

	std::cout<<"Building COllision Object\n";
	ColObj = new CollisionObject();
	ColObj->AddMeshShape(getEntity());
	ColObj->SetUserPointer(this);
	ColObj->SetPosition(getPosition());
	//ColObj->SetScale(0.5,0.5,0.5);
	
}

void IObject::MakeBoxCollisionObject()
{
	ColObj = new CollisionObject();
	{
		ColObj->AddBoxMesh(getEntity());
	}
	//Ogre::Vector3 boundingBox = getEntity()->getBoundingBox().getSize();

	//ColObj = new CollisionObject();
	//ColObj->AddBoxShape(boundingBox.x, boundingBox.y, boundingBox.z);
	ColObj->SetUserPointer(this);
	ColObj->SetPosition(getPosition());
	ColObj->SetScale(0.5,0.5,0.5);
}

std::string IObject::getEntityName()
{
	return m_entity;
}

Ogre::Entity* IObject::getEntity()
{
	return Core::Game::getGraphics()->getEntity(m_entity);
}


Ogre::Vector3 IObject::getRotation() const
{
	return Ogre::Vector3(getOrientation().getRoll().valueDegrees(),
							getOrientation().getPitch().valueDegrees(),
							getOrientation().getYaw().valueDegrees());
}

std::map<std::string,int>* IObject::GetMap()
{
	return &Affordances;
}

int IObject::GetAffodance(std::string affordance)
{
	return Affordances.find(affordance)->second;
}


bool IObject::IsInteractable()
{
	return Interactable;
}