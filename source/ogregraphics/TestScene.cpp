#include "StdAfx.h"
#include "TestScene.h"

using namespace Scenes;

void TestScene::initialise()
{
	m_cameraType = CAM_FIRSTPERSON;

	Core::Game::getGraphics()->cameraSetPosition( 0, 0, 50 );
	Core::Game::getGraphics()->cameraSetLookAt( 0, 0, 0 );

	if( Core::Game::getGraphics()->getWindowHeight() > 0 )
		Core::Game::getGraphics()->cameraSetAspectRatio( (float)(Core::Game::getGraphics()->getWindowWidth()) / (float)(Core::Game::getGraphics()->getWindowHeight()) );
	else
		Core::Game::getGraphics()->cameraSetAspectRatio( 1.0f );

	Core::Game::getGraphics()->createPlaneEntity( "LightPlaneEntity", "plane", Ogre::Vector3::UNIT_Y, -5, 1500, 1500, 200, 200, 5, 5, "Examples/BeachStones" );

	Core::Game::getGraphics()->createDirectionalLight( "Light1", 0, 0, 0, 1, -1, 0 );

	addObject( "Player", new Objects::TestObject() );
	//addObject( "WallSection", new Objects::GenericObject( Ogre::Vector3(100, 0, 0), Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	//addObject( "Cabinet", new Objects::GenericObject( Ogre::Vector3(200, 0, 0), Ogre::Vector3(0, 0, 0), "models/Cabinet.mesh" ) );
	//addObject( "ComputerTable", new Objects::GenericObject( Ogre::Vector3(300, 0, 0), Ogre::Vector3(0, 0, 0), "models/ComputerTable.mesh" ) );
	//addObject( "DoorClosed", new Objects::GenericObject( Ogre::Vector3(400, 0, 0), Ogre::Vector3(0, 0, 0), "models/DoorClosed.mesh" ) );
	//addObject( "DoorOpen", new Objects::GenericObject( Ogre::Vector3(500, 0, 0), Ogre::Vector3(0, 0, 0), "models/DoorOpen.mesh" ) );
	//addObject( "FloorCarpet1", new Objects::GenericObject( Ogre::Vector3(600, 0, 0), Ogre::Vector3(0, 0, 0), "models/FloorCarpet1.mesh" ) );
	//addObject( "FloorCarpet2", new Objects::GenericObject( Ogre::Vector3(700, 0, 0), Ogre::Vector3(0, 0, 0), "models/FloorCarpet2.mesh" ) );
	addObject( "Stool", new Objects::GenericObject( Ogre::Vector3(800, 0, 0), Ogre::Vector3(0, 0, 0), "models/Stool.mesh" ) );
	addObject( "Floor", new Objects::GenericObject( Ogre::Vector3(0, 20, 0), Ogre::Vector3(0, 0, 0), "models/FloorPlan.mesh" ) );
	//addObject( "TableMesh", new Objects::GenericObject( Ogre::Vector3(900, 0, 0), Ogre::Vector3(0, 0, 0), "models/TableMesh.mesh" ) );
}

void TestScene::update( float deltaTime )
{
	// close the window if ESC is pressed
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_ESCAPE ) )
	{
		Core::Game::setRunning( false );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_Q ) )
	{
		m_cameraType = CAM_FREE;
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_E ) )
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

	IScene::update( deltaTime ); // make sure this is always last
}

void TestScene::onExit()
{

}

void TestScene::freeCamera( float deltaTime )
{
	float movementSpeed = 1000.0f;	

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
	
	Core::Game::getGraphics()->cameraMoveRelative( translate * deltaTime * movementSpeed );

	float rotX = Core::Game::getMouse()->getMouseState().X.rel * deltaTime * -0.3;
	float rotY = Core::Game::getMouse()->getMouseState().Y.rel * deltaTime * -0.3;
	Core::Game::getGraphics()->cameraYaw( Ogre::Radian( rotX ) );
	Core::Game::getGraphics()->cameraPitch( Ogre::Radian( rotY ) );

	getObject( "Player" )->setYaw( rotX );
}

void TestScene::firstPersonCamera( float deltaTime )
{
	float movementSpeed = 1000.0f;	

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

	float rotX = Core::Game::getMouse()->getMouseState().X.rel * deltaTime * -0.3;
	float rotY = Core::Game::getMouse()->getMouseState().Y.rel * deltaTime * -0.3;
	Core::Game::getGraphics()->cameraYaw( Ogre::Radian( rotX ) );
	Core::Game::getGraphics()->cameraPitch( Ogre::Radian( rotY ) );

	getObject( "Player" )->setYaw( rotX );

	Core::Game::getGraphics()->cameraSetPosition( getObject( "Player" )->getPosition().x, 
		getObject( "Player" )->getPosition().y, getObject( "Player" )->getPosition().z );
	translate = translate * deltaTime * movementSpeed;

	//std::cout << translate * getObject( "Player" )->getForwardVector() << std::endl;
	getObject( "Player" )->changePosition( getObject( "Player" )->getOrientation() * translate );
}