#include "StdAfx.h"
#include "OgreGraphics.h"

using namespace Graphics;

//-----------------------------------------------------------------------------

OgreGraphics::OgreGraphics(void)
{
	m_root = NULL;
	m_renderWindow = NULL;
	m_camera = NULL;
	m_sceneManager = NULL;
	m_viewport = NULL;
	m_frameListener = NULL;
}

//-----------------------------------------------------------------------------

OgreGraphics::~OgreGraphics(void)
{
	Ogre::deletePtr( m_root );
}

//-----------------------------------------------------------------------------

bool OgreGraphics::initialise()
{
	m_root = new Ogre::Root( "plugins_d.cfg" );

	if( !( m_root->restoreConfig() || m_root->showConfigDialog() ) )
	{
		return false;
	}

	m_renderWindow = m_root->initialise( true, WINDOWTITLE );

	m_sceneManager = m_root->createSceneManager( Ogre::ST_GENERIC );

	m_camera = m_sceneManager->createCamera( "Camera" );
	//m_camera->setPosition( Ogre::Vector3(0, 0, 50) );
	//m_camera->lookAt( Ogre::Vector3(0, 0, 0) );
	m_camera->setNearClipDistance( 5 );

	m_viewport = m_renderWindow->addViewport( m_camera );
	m_viewport->setBackgroundColour( Ogre::ColourValue::Black );

	//m_camera->setAspectRatio( Ogre::Real( m_viewport->getActualWidth() ) /
		//						Ogre::Real( m_viewport->getActualHeight() ) );

	m_frameListener = new FrameListener();
	m_root->addFrameListener( m_frameListener );

	loadResources();
	//createScene();

	return true;
}

//-----------------------------------------------------------------------------

void OgreGraphics::loadResources()
{
	// Use config file to load in resources
	Ogre::ConfigFile cf;
	cf.load("resources_d.cfg");

	// get the iterator to go through the config file
	Ogre::ConfigFile::SectionIterator sectionIter = cf.getSectionIterator();

	Ogre::String sectionName, typeName, dataName;
	while( sectionIter.hasMoreElements() )
	{
		sectionName = sectionIter.peekNextKey();

		Ogre::ConfigFile::SettingsMultiMap* settings = sectionIter.getNext();

		Ogre::ConfigFile::SettingsMultiMap::iterator i;

		for( i = settings->begin(); i != settings->end(); ++i )
		{
			typeName = i->first;
			dataName = i->second;

			Ogre::ResourceGroupManager::getSingleton().
				addResourceLocation( dataName, typeName, sectionName );
		}
	}

	// index all resources
	Ogre::ResourceGroupManager::getSingleton().
		initialiseAllResourceGroups();
}

//-----------------------------------------------------------------------------

void OgreGraphics::renderOneFrame()
{
	Ogre::WindowEventUtilities::messagePump();
	m_root->renderOneFrame();
}

//-----------------------------------------------------------------------------

void OgreGraphics::cameraSetPosition( float posX, float posY, float posZ )
{
	m_camera->setPosition( Ogre::Vector3( posX, posY, posZ ) );
}

//-----------------------------------------------------------------------------

void OgreGraphics::cameraSetLookAt( float lookAtX, float lookAtY, float lookAtZ )
{
	m_camera->lookAt( Ogre::Vector3( lookAtX, lookAtY, lookAtZ ) );
}

//-----------------------------------------------------------------------------

void OgreGraphics::cameraSetAspectRatio( float ratio )
{
	m_camera->setAspectRatio( ratio );
}

//-----------------------------------------------------------------------------

void OgreGraphics::cameraMoveRelative( Ogre::Vector3& movement )
{
	m_camera->moveRelative( movement );
}

//-----------------------------------------------------------------------------

void OgreGraphics::cameraYaw( Ogre::Radian& angle )
{
	m_camera->yaw( angle );
}

//-----------------------------------------------------------------------------

void OgreGraphics::cameraPitch( Ogre::Radian& angle )
{
	m_camera->pitch( angle );
}

//-----------------------------------------------------------------------------

void OgreGraphics::createMeshEntity( std::string identifier, std::string filename )
{
	Ogre::Entity* ent = m_sceneManager->createEntity( identifier, filename );
	m_sceneNodes[identifier] = m_sceneManager->getRootSceneNode()->createChildSceneNode();
	m_sceneNodes[identifier]->attachObject( ent );
}

//-----------------------------------------------------------------------------

void OgreGraphics::createPlaneEntity( std::string identifier, std::string meshName, Ogre::Vector3 normal, float changeAlongNormal, 
	float width, float height, int xSegments, int ySegments, float uTile, float vTile, std::string material )
{
	Ogre::Plane plane( normal, changeAlongNormal );

	Ogre::MeshManager::getSingleton().createPlane( meshName,
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane,
		width, height, xSegments, ySegments, true, 1, uTile, vTile, Ogre::Vector3::UNIT_Z );

	Ogre::Entity* ground = m_sceneManager->createEntity( identifier, meshName );

	m_sceneNodes[identifier] = m_sceneManager->getRootSceneNode()->createChildSceneNode();
	m_sceneNodes[identifier]->attachObject( ground );

	if( !material.empty() )
	{
		ground->setMaterialName( material );
	}
}

//-----------------------------------------------------------------------------

void OgreGraphics::createDirectionalLight( std::string name, float posX, float posY, float posZ,
	float dirX, float dirY, float dirZ )
{
	Ogre::Light* light = m_sceneManager->createLight( name );
	light->setType( Ogre::Light::LT_DIRECTIONAL );
	light->setPosition( Ogre::Vector3( posX, posY, posZ ) );
	light->setDirection( Ogre::Vector3( dirX, dirY, dirZ ) );
}

//-----------------------------------------------------------------------------

void OgreGraphics::translateEntity( std::string identifier, float x, float y, float z )
{
	m_sceneNodes[identifier]->translate( x, y, z, Ogre::Node::TS_LOCAL );
}

void OgreGraphics::translateEntity( std::string identifier, Ogre::Vector3 translateVector )
{
	m_sceneNodes[identifier]->translate( translateVector, Ogre::Node::TS_LOCAL );
}

void OgreGraphics::setEntityYaw( std::string identifier, float angle )
{
	m_sceneNodes[identifier]->yaw( Ogre::Radian(angle) );
}

void OgreGraphics::setEntityPitch( std::string identfier, float angle )
{
	m_sceneNodes[identfier]->pitch( Ogre::Radian(angle) );
}

void OgreGraphics::setEntityRoll( std::string identifier, float angle )
{
	m_sceneNodes[identifier]->roll( Ogre::Radian(angle) );
}

//-----------------------------------------------------------------------------

void OgreGraphics::setEntityPosition( std::string identifier, float x, float y, float z )
{
	m_sceneNodes[identifier]->setPosition( x, y, z );
}

//-----------------------------------------------------------------------------

void OgreGraphics::createEmptyEntity( std::string identifier )
{
	m_sceneNodes[identifier] = m_sceneManager->getRootSceneNode()->createChildSceneNode();
}

//-----------------------------------------------------------------------------

void OgreGraphics::createChildEntity( std::string parentID, std::string childID )
{
	m_sceneNodes[childID] = m_sceneNodes[parentID]->createChildSceneNode();
}

//-----------------------------------------------------------------------------

Ogre::Quaternion OgreGraphics::getEntityOrientation( std::string identifier )
{
	return m_sceneNodes[identifier]->getOrientation();
}

void OgreGraphics::setEntityOrientation( std::string identifier, Ogre::Quaternion quat )
{
	if(!identifier.empty())
		m_sceneNodes[identifier]->setOrientation( quat );
}

void OgreGraphics::setEntityScale( std::string identifier, Ogre::Vector3 scale )
{
	m_sceneNodes[identifier]->setScale( scale );
}