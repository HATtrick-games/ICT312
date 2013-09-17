#include "StdAfx.h"
#include "ITBuildingScene.h"

using namespace Scenes;

void ITBuildingScene::initialise()
{
	m_cameraType = CAM_FIRSTPERSON;
	cameraSpeed = 100.0f;

	Core::Game::getGraphics()->cameraSetPosition( 0, 0, 50 );
	Core::Game::getGraphics()->cameraSetLookAt( 0, 0, 0 );

	if( Core::Game::getGraphics()->getWindowHeight() > 0 )
		Core::Game::getGraphics()->cameraSetAspectRatio( (float)(Core::Game::getGraphics()->getWindowWidth()) / (float)(Core::Game::getGraphics()->getWindowHeight()) );
	else
		Core::Game::getGraphics()->cameraSetAspectRatio( 1.0f );

	Core::Game::getGraphics()->createDirectionalLight( "Light1", 0, 0, 0, 1, -1, 0 );

	Core::Game::getGraphics()->cameraMoveRelative( Ogre::Vector3(0, 120, 0) );

	addObject( "Player", new Objects::GenericObject( Ogre::Vector3(0, 120, 0), 
		Ogre::Vector3(0, 0, 0), "models/boxmesh.mesh" ) );

	addObject( "Camera", new Objects::GenericObject( Ogre::Vector3(100.0f, 100.0f, 100.0f), 
		Ogre::Vector3(0, 0, 0), "models/boxmesh.mesh" ) );

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

	//moveObject("ComputerChair1", deltaTime);

	IScene::update( deltaTime ); // must always be last
}

void ITBuildingScene::onExit()
{

}

void ITBuildingScene::createScene()
{
	addObject( "FloorPlan", new Objects::GenericObject( Ogre::Vector3(-1.88, 10, 82.5697),
		Ogre::Vector3(0, 0, 0), "models/FloorPlan.mesh" ) );

	// front left sidesa
	addObject( "WallSection1", new Objects::GenericObject( Ogre::Vector3(-667.662, 0, 17.939), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) ); 
	addObject( "WallSection2", new Objects::GenericObject( Ogre::Vector3(-616.127, 0, 17.950), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection9", new Objects::GenericObject( Ogre::Vector3(-368.138, 0, 17.950), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection10", new Objects::GenericObject( Ogre::Vector3(-250.448, 0, 17.950), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection11", new Objects::GenericObject( Ogre::Vector3(-179.458, 0, 17.950), 
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
	addObject( "WallSection8", new Objects::GenericObject( Ogre::Vector3(-74.3394, 0, 195.706), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );

	// mid left side
	addObject( "DoorOpen1", new Objects::GenericObject( Ogre::Vector3(-52.437, 0, -31.9801), 
		Ogre::Vector3(0, 3.14159, 0), "models/DoorOpen.mesh" ) );
	addObject( "WallSection12", new Objects::GenericObject( Ogre::Vector3(39.393, 0, 17.950), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection13", new Objects::GenericObject( Ogre::Vector3(158.453, 0, 17.960), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection14", new Objects::GenericObject( Ogre::Vector3(191.011, 0, 17.950), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "DoorOpen2", new Objects::GenericObject( Ogre::Vector3(318.314, 0, -31.9801), 
		Ogre::Vector3(0, 3.14159, 0), "models/DoorOpen.mesh" ) );
	addObject( "WallSection15", new Objects::GenericObject( Ogre::Vector3(410.18, 0, 17.950), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection16", new Objects::GenericObject( Ogre::Vector3(528.45, 0, 17.950), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection17", new Objects::GenericObject( Ogre::Vector3(647.291, 0, 17.960), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection18", new Objects::GenericObject( Ogre::Vector3(678.979, 0, 17.950), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );

	// mid right side
	addObject( "DoorClosed1", new Objects::GenericObject( Ogre::Vector3(57.9132, 0, 196), 
		Ogre::Vector3(0, 3.14159, 0), "models/DoorClosed.mesh" ) );
	addObject( "WallSection20", new Objects::GenericObject( Ogre::Vector3(61.7906, 0, 191.18), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "SmallWall1", new Objects::GenericObject( Ogre::Vector3(85.9401, 0, 103.276), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection2.mesh" ) );

	// common room
	addObject( "WallSection19", new Objects::GenericObject( Ogre::Vector3(115.24, 0, 186.53), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection21", new Objects::GenericObject( Ogre::Vector3(115.24, 0, 304.923), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection22", new Objects::GenericObject( Ogre::Vector3(115.24, 0, 422.699), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection23", new Objects::GenericObject( Ogre::Vector3(115.24, 0, 540), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection24", new Objects::GenericObject( Ogre::Vector3(150.781, 0, 576.013), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection25", new Objects::GenericObject( Ogre::Vector3(268.692, 0, 576.012), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection26", new Objects::GenericObject( Ogre::Vector3(330.887, 0, 576.010), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection27", new Objects::GenericObject( Ogre::Vector3(415.110, 0, 534.911), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection29", new Objects::GenericObject( Ogre::Vector3(415.117, 0, 472.39), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection28", new Objects::GenericObject( Ogre::Vector3(363.296, 0, 540.091), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection30", new Objects::GenericObject( Ogre::Vector3(363.290, 0, 478.129), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection31", new Objects::GenericObject( Ogre::Vector3(327.658, 0, 441.921), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection32", new Objects::GenericObject( Ogre::Vector3(283.59, 0, 441.918), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection33", new Objects::GenericObject( Ogre::Vector3(327.181, 0, 389.368), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection34", new Objects::GenericObject( Ogre::Vector3(278.241, 0, 389.365), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );

	// back wall
	addObject( "WallSection35", new Objects::GenericObject( Ogre::Vector3(628.624, 0, 537.346), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection36", new Objects::GenericObject( Ogre::Vector3(628.634, 0, 420.052), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection37", new Objects::GenericObject( Ogre::Vector3(628.634, 0, 300), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection38", new Objects::GenericObject( Ogre::Vector3(628.624, 0, 228.173), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );

	// inside 2.046
	// right wall
	addObject( "WallSection39", new Objects::GenericObject( Ogre::Vector3(34.5129, 0, -32.35), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection40", new Objects::GenericObject( Ogre::Vector3(152.653, 0, -32.30), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection41", new Objects::GenericObject( Ogre::Vector3(187.791, 0, -32.25), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection42", new Objects::GenericObject( Ogre::Vector3(405, 0, -32.37), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection43", new Objects::GenericObject( Ogre::Vector3(523.35, 0, -32.39), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection44", new Objects::GenericObject( Ogre::Vector3(644.801, 0, -32.35), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection45", new Objects::GenericObject( Ogre::Vector3(678.979, 0, -32.25), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );

	// back wall
	addObject( "WallSection46", new Objects::GenericObject( Ogre::Vector3(707.399, 0, -67.8404), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection47", new Objects::GenericObject( Ogre::Vector3(707.400, 0, -186.473), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection48", new Objects::GenericObject( Ogre::Vector3(707.399, 0, -304.79), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection49", new Objects::GenericObject( Ogre::Vector3(707.398, 0, -423.34), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );

	// left wall
	addObject( "WallSection50", new Objects::GenericObject( Ogre::Vector3(671.438, 0, -410.18), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection51", new Objects::GenericObject( Ogre::Vector3(550, 0, -410.20), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection52", new Objects::GenericObject( Ogre::Vector3(432.18, 0, -410.18), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection53", new Objects::GenericObject( Ogre::Vector3(314.07, 0, -410.20), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection54", new Objects::GenericObject( Ogre::Vector3(195.58, 0, -410.18), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection55", new Objects::GenericObject( Ogre::Vector3(77.18, 0, -410.20), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection56", new Objects::GenericObject( Ogre::Vector3(-41.1799, 0, -410.18), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection57", new Objects::GenericObject( Ogre::Vector3(-159.54, 0, -410.20), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection58", new Objects::GenericObject( Ogre::Vector3(-277.84, 0, -410.18), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection59", new Objects::GenericObject( Ogre::Vector3(-395.981, 0, -410.20), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );

	// front wall
	addObject( "WallSection60", new Objects::GenericObject( Ogre::Vector3(-402.871, 0, -373.961), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection61", new Objects::GenericObject( Ogre::Vector3(-402.869, 0, -255.64), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection62", new Objects::GenericObject( Ogre::Vector3(-402.871, 0, -138.97), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection63", new Objects::GenericObject( Ogre::Vector3(-402.872, 0, -71.154), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection.mesh" ) );

	// front left wall
	addObject( "WallSection64", new Objects::GenericObject( Ogre::Vector3(-184.456, 0, -32.3849), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection65", new Objects::GenericObject( Ogre::Vector3(-302.774, 0, -32.3851), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection66", new Objects::GenericObject( Ogre::Vector3(-371.613, 0, -32.3849), 
		Ogre::Vector3(0, 3.14159, 0), "models/WallSection.mesh" ) );

	// corridor inset
	addObject( "WallSection67", new Objects::GenericObject( Ogre::Vector3(-456.016, 0, -65.224), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "WallSection68", new Objects::GenericObject( Ogre::Vector3(-456.018, 0, -183.644), 
		Ogre::Vector3(0, -1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "DoorClosed2", new Objects::GenericObject( Ogre::Vector3(-535.849, 0, -50.9507), 
		Ogre::Vector3(0, 1.570795, 0), "models/DoorClosed.mesh" ) );
	addObject( "WallSection69", new Objects::GenericObject( Ogre::Vector3(-535.849, 0, -183.132), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection.mesh" ) );
	addObject( "DoorClosed3", new Objects::GenericObject( Ogre::Vector3(-516.911, 0, -121.39), 
		Ogre::Vector3(0, 0, 0), "models/DoorClosed.mesh" ) );
	addObject( "SmallWall2", new Objects::GenericObject( Ogre::Vector3(-434.094, 0, -122.93), 
		Ogre::Vector3(0, 0, 0), "models/WallSection2.mesh" ) );
	addObject( "SmallWall3", new Objects::GenericObject( Ogre::Vector3(-442.983, 0, -122.93), 
		Ogre::Vector3(0, 0, 0), "models/WallSection2.mesh" ) );
	addObject( "SmallWall4", new Objects::GenericObject( Ogre::Vector3(-533.081, 0, -12.5402), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection2.mesh" ) );
	addObject( "SmallWall5", new Objects::GenericObject( Ogre::Vector3(-533.081, 0, -21.4702), 
		Ogre::Vector3(0, 1.570795, 0), "models/WallSection2.mesh" ) );
	addObject( "WallSection70", new Objects::GenericObject( Ogre::Vector3(-602.45, 0, -121.122), 
		Ogre::Vector3(0, 0, 0), "models/WallSection.mesh" ) );

	// cabinets
	addObject( "Cabinet1", new Objects::GenericObject( Ogre::Vector3(420.479, 0, 471.098), 
		Ogre::Vector3(0, 0, 0), "models/Cabinet.mesh" ) );

	// computer tables
	addObject( "ComputerTable1", new Objects::GenericObject( Ogre::Vector3(-217.116, 0, -271.38), 
		Ogre::Vector3(0, 0, 0), "models/ComputerTable.mesh" ) );
	addObject( "ComputerTable2", new Objects::GenericObject( Ogre::Vector3(-32.539, 0, -271.38), 
		Ogre::Vector3(0, 0, 0), "models/ComputerTable.mesh" ) );
	addObject( "ComputerTable3", new Objects::GenericObject( Ogre::Vector3(152.038, 0, -271.38), 
		Ogre::Vector3(0, 0, 0), "models/ComputerTable.mesh" ) );
	addObject( "ComputerTable4", new Objects::GenericObject( Ogre::Vector3(336.615, 0, -271.38), 
		Ogre::Vector3(0, 0, 0), "models/ComputerTable.mesh" ) );
	addObject( "ComputerTable5", new Objects::GenericObject( Ogre::Vector3(521.192, 0, -271.38), 
		Ogre::Vector3(0, 0, 0), "models/ComputerTable.mesh" ) );

	// computer chairs
	/*addObject( "ComputerChair1", new Objects::GenericObject( Ogre::Vector3(521.192, 0, -271.38), 
		Ogre::Vector3(0, 0, 0), "models/ComputerChair.mesh" ) );*/

	// corridor tables
	addObject( "Table1", new Objects::GenericObject( Ogre::Vector3(-406.622, 0, 179.278), 
		Ogre::Vector3(0, 1.570795, 0), "models/TableMesh.mesh" ) );
	addObject( "Table2", new Objects::GenericObject( Ogre::Vector3(-179.185, 0, 179.278), 
		Ogre::Vector3(0, 1.570795, 0), "models/TableMesh.mesh" ) );
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

	getObject( "Camera" )->setYaw( rotX );
}

void ITBuildingScene::firstPersonCamera( float deltaTime )
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

	getObject( "Camera" )->setYaw( rotX );

	Core::Game::getGraphics()->cameraSetPosition( getObject( "Camera" )->getPosition().x, 
		getObject( "Camera" )->getPosition().y, getObject( "Camera" )->getPosition().z );
	translate = translate * deltaTime * cameraSpeed;

	std::cout << getObject( "Camera" )->getPosition() << std::endl;
	getObject( "Camera" )->changePosition( getObject( "Camera" )->getOrientation() * translate );
}

void ITBuildingScene::moveObject( std::string objectName, float deltaTime )
{
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_UP ) )
	{
		getObject( objectName )->changePosition( Ogre::Vector3(20 * deltaTime, 0, 0) );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_DOWN ) )
	{
		getObject( objectName )->changePosition( Ogre::Vector3(-20 * deltaTime, 0, 0) );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_LEFT ) )
	{
		getObject( objectName )->changePosition( Ogre::Vector3(0, 0, 20 * deltaTime) );
	}
	if( Core::Game::getKeyboard()->isKeyDown( OIS::KC_RIGHT ) )
	{
		getObject( objectName )->changePosition( Ogre::Vector3(0, 0, -20 * deltaTime) );
	}

	std::cout << "Position: " << getObject( objectName )->getPosition() << std::endl;
}