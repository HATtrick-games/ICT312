#include "StdAfx.h"
#include "TestScene.h"
#include "ProjectileObject.h"

using namespace Scenes;

void TestScene::initialise()
{
	m_cameraType = CAM_FIRSTPERSON;
	m_projectileKeyDown = false;
	m_numProjectiles = 0;

	Core::Game::getGraphics()->cameraSetPosition( 0, 0, 50 );
	Core::Game::getGraphics()->cameraSetLookAt( 0, 0, 0 );

	if( Core::Game::getGraphics()->getWindowHeight() > 0 )
		Core::Game::getGraphics()->cameraSetAspectRatio( (float)(Core::Game::getGraphics()->getWindowWidth()) / (float)(Core::Game::getGraphics()->getWindowHeight()) );
	else
		Core::Game::getGraphics()->cameraSetAspectRatio( 1.0f );

	Core::Game::getGraphics()->createPlaneEntity( "LightPlaneEntity", "plane", Ogre::Vector3::UNIT_Y, -5, 1500, 1500, 200, 200, 5, 5, "Examples/BeachStones" );

	Core::Game::getGraphics()->createDirectionalLight( "Light1", 0, 0, 0, 1, -1, 0 );

	addObject( "Camera", new Objects::TestObject() );
	addObject( "Target", new Objects::TargetObject() );
	//addObject( "Projectile", new Objects::ProjectileObject() );
}

void TestScene::update( float deltaTime )
{


	// close the window if ESC is pressed
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_ESCAPE ) )
	{
		Core::Game::setRunning( false );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_1 ) )
	{
		m_cameraType = CAM_FREE;
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_2 ) )
	{
		m_cameraType = CAM_FIRSTPERSON;
	}

	switch( m_cameraType )
	{
	case CAM_FREE:
		freeCamera( deltaTime );
		break;
	case CAM_FIRSTPERSON:
		firstPersonCamera( deltaTime );
		break;
	}

	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_SPACE ) && !m_projectileKeyDown )
	{
		createProjectile();
		m_projectileKeyDown = true;
	}

	if( !Core::Game::getKeyboard()->isKeyDown( OIS::KC_SPACE ))
	{
		m_projectileKeyDown = false;
	}

	IScene::update( deltaTime ); // make sure this is always last
}

void TestScene::onExit()
{

}

void TestScene::freeCamera( float deltaTime )
{
	float movementSpeed = 100.0f;	

	Ogre::Vector3 translate( 0, 0, 0 );
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_W ) )
	{
		translate += Ogre::Vector3( 0, 0, -1 );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_S ) )
	{
		translate += Ogre::Vector3( 0, 0, 1 );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_A ) )
	{
		translate += Ogre::Vector3( -1, 0, 0 );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_D ) )
	{
		translate += Ogre::Vector3( 1, 0, 0 );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_Q ) )
	{
		translate += Ogre::Vector3( 0, -1, 0 );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_E ) )
	{
		translate += Ogre::Vector3( 0, 1, 0 );
	}
	
	Core::Game::getGraphics()->cameraMoveRelative( translate * deltaTime * movementSpeed );

	float rotX = Core::Game::getMouse()->getMouseState().X.rel * deltaTime * -0.3;
	float rotY = Core::Game::getMouse()->getMouseState().Y.rel * deltaTime * -0.3;
	Core::Game::getGraphics()->cameraYaw( Ogre::Radian( rotX ) );
	Core::Game::getGraphics()->cameraPitch( Ogre::Radian( rotY ) );

	getObject( "Camera" )->setYaw( rotX );
}

void TestScene::firstPersonCamera( float deltaTime )
{
	float movementSpeed = 100.0f;	

	Ogre::Vector3 translate( 0, 0, 0 );
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_W ) )
	{
		translate += Ogre::Vector3( 0, 0, -1 );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_S ) )
	{
		translate += Ogre::Vector3( 0, 0, 1 );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_A ) )
	{
		translate += Ogre::Vector3( -1, 0, 0 );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_D ) )
	{
		translate += Ogre::Vector3( 1, 0, 0 );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_Q ) )
	{
		translate += Ogre::Vector3( 0, -1, 0 );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_E ) )
	{
		translate += Ogre::Vector3( 0, 1, 0 );
	}

	float rotX = Core::Game::getMouse()->getMouseState().X.rel * deltaTime * -0.3;
	float rotY = Core::Game::getMouse()->getMouseState().Y.rel * deltaTime * -0.3;
	Core::Game::getGraphics()->cameraYaw( Ogre::Radian( rotX ) );
	Core::Game::getGraphics()->cameraPitch( Ogre::Radian( rotY ) );

	getObject( "Camera" )->setYaw( rotX );

	Core::Game::getGraphics()->cameraSetPosition( getObject( "Camera" )->getPosition().x, 
		getObject( "Camera" )->getPosition().y, getObject( "Camera" )->getPosition().z );
	translate = translate * deltaTime * movementSpeed;

	//std::cout << translate * getObject( "Player" )->getForwardVector() << std::endl;
	getObject( "Camera" )->changePosition( getObject( "Camera" )->getOrientation() * translate );
}

void TestScene::createProjectile()
{
	Objects::ProjectileObject* projectile = new Objects::ProjectileObject(getObject("Camera")->getPosition());
	projectile->applyForce(1000 * Core::Game::getGraphics()->cameraDirection() );

	std::ostringstream idString;
	idString << m_numProjectiles;

	addObject("projectile" + idString.str() , projectile );

	// for some reason the projectiles will only fire properly when this is in there
	std::cout << 1000 * Core::Game::getGraphics()->cameraDirection() << std::endl;

	m_numProjectiles++;
}