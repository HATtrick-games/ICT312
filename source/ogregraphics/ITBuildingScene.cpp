#include "StdAfx.h"
#include "ITBuildingScene.h"

using namespace Scenes;

void ITBuildingScene::initialise()
{
	cameraSpeed = 100.0f;

	Core::Game::getGraphics()->cameraSetPosition( 0, 0, 50 );
	Core::Game::getGraphics()->cameraSetLookAt( 0, 0, 0 );

	if( Core::Game::getGraphics()->getWindowHeight() > 0 )
		Core::Game::getGraphics()->cameraSetAspectRatio( (float)(Core::Game::getGraphics()->getWindowWidth()) / (float)(Core::Game::getGraphics()->getWindowHeight()) );
	else
		Core::Game::getGraphics()->cameraSetAspectRatio( 1.0f );

	Core::Game::getGraphics()->createDirectionalLight( "Light1", 0, 0, 0, 1, -1, 0 );

	Core::Game::getGraphics()->cameraMoveRelative( Ogre::Vector3(0, 180, 0) );

	createScene();
}

void ITBuildingScene::update( float deltaTime )
{
	// close the window if ESC is pressed
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_ESCAPE ) )
	{
		// TODO add screen with our faces which the user has to click to exit
		Core::Game::setRunning( false );
	}

	freeCamera( deltaTime );

	moveObject("WallSection9", deltaTime);

	IScene::update( deltaTime ); // must always be last
}

void ITBuildingScene::onExit()
{

}

void ITBuildingScene::createScene()
{
	addObject( "FloorPlan", new Objects::GenericObject( Ogre::Vector3(-1.88, 10, 82.5697),
		Ogre::Vector3(0, 0, 0), "models/FloorPlan.mesh" ) );

	// front left side
	addObject( "WallSection1", new Objects::GenericObject( Ogre::Vector3(-667.662, 0, 17.939), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) ); 
	addObject( "WallSection2", new Objects::GenericObject( Ogre::Vector3(-616.127, 0, 17.950), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection9", new Objects::GenericObject( Ogre::Vector3(-368.138, 0, 17.950), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );

	// front right side
	addObject( "WallSection3", new Objects::GenericObject( Ogre::Vector3(-672.004, 0, 195.756), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection4", new Objects::GenericObject( Ogre::Vector3(-553.387, 0, 195.706), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection5", new Objects::GenericObject( Ogre::Vector3(-434.873, 0, 195.706), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection6", new Objects::GenericObject( Ogre::Vector3(-316.617, 0, 195.706), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection7", new Objects::GenericObject( Ogre::Vector3(-198.31, 0, 195.706), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection8", new Objects::GenericObject( Ogre::Vector3(-80.8895, 0, 195.706), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
}

void ITBuildingScene::freeCamera( float deltaTime )
{
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


	Core::Game::getGraphics()->cameraMoveRelative( translate * deltaTime * cameraSpeed );

	float rotX = Core::Game::getMouse()->getMouseState().X.rel * deltaTime * -0.3;
	float rotY = Core::Game::getMouse()->getMouseState().Y.rel * deltaTime * -0.3;
	Core::Game::getGraphics()->cameraYaw( Ogre::Radian( rotX ) );
	Core::Game::getGraphics()->cameraPitch( Ogre::Radian( rotY ) );
}

void ITBuildingScene::moveObject( std::string objectName, float deltaTime )
{
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_UP ) )
	{
		getObject( objectName )->changePosition( Ogre::Vector3(10 * deltaTime, 0, 0) );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_DOWN ) )
	{
		getObject( objectName )->changePosition( Ogre::Vector3(-10 * deltaTime, 0, 0) );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_LEFT ) )
	{
		getObject( objectName )->changePosition( Ogre::Vector3(0, 0, 10 * deltaTime) );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_RIGHT ) )
	{
		getObject( objectName )->changePosition( Ogre::Vector3(0, 0, -10 * deltaTime) );
	}

	std::cout << "Position: " << getObject( objectName )->getPosition() << std::endl;
}