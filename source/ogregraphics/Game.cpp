#include "StdAfx.h"
#include "Game.h"
#include "CollisionObject.h"
#include "CollisionWorldSingleton.h"
#include "TemporaryPlayerObject.h"

using namespace Core;

bool Game::m_running = true;

Graphics::OgreGraphics* Game::m_graphics = NULL;
Scenes::SceneManager* Game::m_sceneManager = NULL;
OIS::InputManager* Game::m_inputManager = NULL;
OIS::Keyboard* Game::m_keyboard = NULL;
OIS::Mouse* Game::m_mouse = NULL;

CollisionObject* PlayerSphere;
//CollisionObject* col[10];
TemporaryPlayerObject* Player;




Game::~Game(void)
{
	if( m_keyboard ) m_inputManager->destroyInputObject( m_keyboard );
	if( m_mouse ) m_inputManager->destroyInputObject( m_mouse );
	if( m_inputManager ) OIS::InputManager::destroyInputSystem( m_inputManager );

	if( m_graphics ) delete m_graphics;
	if( m_sceneManager ) delete m_sceneManager;
}

int Game::initialise()
{
	// initialise graphics
	m_graphics = new Graphics::OgreGraphics();
	if( !m_graphics->initialise() )
	{
		m_running = false;
		return 1;
	}

	// initialise input (this must be done after graphics)
	OIS::ParamList parameters;
	unsigned int windowHandle;
	std::ostringstream windowHandleString;

	m_graphics->getRenderWindow()->getCustomAttribute( "WINDOW", &windowHandle );
	windowHandleString << windowHandle;

	parameters.insert( std::make_pair( "WINDOW", windowHandleString.str() ) );

	m_inputManager = OIS::InputManager::createInputSystem( parameters );
	m_keyboard = static_cast< OIS::Keyboard* >( m_inputManager->createInputObject( OIS::OISKeyboard, false ) );
	m_mouse = static_cast< OIS::Mouse* >( m_inputManager->createInputObject( OIS::OISMouse, false ) );

	// initialise scene manager
	m_sceneManager = new Scenes::SceneManager( new Scenes::TestScene() );


	 Player = new TemporaryPlayerObject();
	// Player->SetLastPos(0,0,0);
	 PlayerSphere = new CollisionObject();
	 PlayerSphere->AddSphereShape(1);
	 PlayerSphere->SetPosition(0,0,0);
	 PlayerSphere->SetUserPointer(Player);
	
	 /***Collision GOES HERE****************************/
/*	 //left side wall
	CollisionObject* WallSection1 = new CollisionObject();
	WallSection1->AddBoxShape(200,1000,2);
	WallSection1->SetPosition(-653.3385,100,1);


	//right side wall
	CollisionObject* WallSection2 = new CollisionObject();
	WallSection2->AddBoxShape(869, 1000, 2);
	WallSection2->SetPosition(-334,100,210);

	//indent
	CollisionObject* Indent = new CollisionObject();
	Indent->AddBoxShape(2,100,80);
	Indent->SetPosition(-545,100,-40);

	//door at back of indent
	CollisionObject* DoorAtBackOfIndent = new CollisionObject();
	DoorAtBackOfIndent->AddBoxShape(100,1000,2);
	DoorAtBackOfIndent->SetPosition(-490,100,-90);

	//Wall From indent to IT room door
	CollisionObject* Wall1 = new CollisionObject();
	Wall1->AddBoxShape(316,1000,16);
	Wall1->SetPosition(-273,100,-5);

	//wall from first door to second door
	CollisionObject* Wall2 = new CollisionObject();
	Wall2->AddBoxShape(320,1000,16);
	Wall2->SetPosition(120,100,-5);

	//Last wall on left side
	CollisionObject* Wall3 = new CollisionObject();
	Wall3->AddBoxShape(426,100,16);
	Wall3->SetPosition(545,100,-5);

	//LEft side wall of LAb
	CollisionObject* LabWall1 = new CollisionObject();
	LabWall1->AddBoxShape(20,1000,470);
	LabWall1->SetPosition(-430,100,-246);

	//Big back wall of lab
	CollisionObject* LabWall2 = new CollisionObject();
	LabWall2->AddBoxShape(1147,1000,10);
	LabWall2->SetPosition(152,100,-425);

	//Right side wall of lab
	CollisionObject* LabWall3 = new CollisionObject();
	LabWall3->AddBoxShape(10,1000,400);
	LabWall3->SetPosition(713,100,-216);

	//IT Common Room left side wall
	CollisionObject* Common1 = new CollisionObject();
	Common1->AddBoxShape(60,1000,440);
	Common1->SetPosition(625,100,380);

	//Common room tables
	CollisionObject* Table1 = new CollisionObject();
	Table1->AddBoxShape(100,1000,240);
	Table1->SetPosition(-215,100,-300);

	CollisionObject* Table2 = new CollisionObject();
	Table2->AddBoxShape(100,1000,240);
	Table2->SetPosition(-31,100,-300);

	CollisionObject* Table3 = new CollisionObject();
	Table3->AddBoxShape(100,1000,240);
	Table3->SetPosition(150,100,-300);

	CollisionObject* Table4 = new CollisionObject();
	Table4->AddBoxShape(100,1000,240);
	Table4->SetPosition(339,100,-300);

	CollisionObject* Table5 = new CollisionObject();
	Table5->AddBoxShape(100,1000,240);
	Table5->SetPosition(523,100,-300);

	//Hallway table
	CollisionObject* HallTable = new CollisionObject();
	HallTable->AddBoxShape(480,1000,55);
	HallTable->SetPosition(-380,100,172);
	
	//Cabinet and bench common room
	CollisionObject* Bench = new CollisionObject();
	Bench->AddBoxShape(80,1000,200);
	Bench->SetPosition(410,100,500);

	//Back window wall
	CollisionObject* Common2 = new CollisionObject();
	Common2->AddBoxShape(140,1000,20);
	Common2->SetPosition(515,100,570);

	//front wall of kitchen
	CollisionObject* Kitchen1 = new CollisionObject();
	Kitchen1->AddBoxShape(180,1000,20);
	Kitchen1->SetPosition(305,100,415);

	//Kitchen Sink
	CollisionObject* Sink = new CollisionObject();
	Sink->AddBoxShape(250,1000,10);
	Sink->SetPosition(245,100,540);

	//Kitchen Right wall
	CollisionObject* Kitchen2 = new CollisionObject();
	Kitchen2->AddBoxShape(20,1000,460);
	Kitchen2->SetPosition(90,100,335);

	//end of all block
	CollisionObject* EndBlock = new CollisionObject();
	EndBlock->AddBoxShape(20,1000,155);
	EndBlock->SetPosition(640,100,72.5);

	// Entrance block
	CollisionObject* Entrance = new CollisionObject();
	Entrance->AddBoxShape(20,1000,204);
	Entrance->SetPosition(-725,100,105);

	//OPen door 1
	CollisionObject* Door1 = new CollisionObject();
	Door1->AddBoxShape(25,1000,120);
	Door1->SetPosition(-115,100,-50);

	CollisionObject* Door2 = new CollisionObject();
	Door2->AddBoxShape(25,1000,120);
	Door2->SetPosition(260,100,-50);

	//left couch
	CollisionObject* Couch1 = new CollisionObject();
	Couch1->AddBoxShape(110,1000,120);
	Couch1->SetPosition(500,100,200);

	//right couch
	CollisionObject* Couch2 = new CollisionObject();
	Couch2->AddBoxShape(200,1000,120);
	Couch2->SetPosition(200,100,200);

	CollisionObject* Couch3 = new CollisionObject();
	Couch3->AddBoxShape(50,1000,85);
	Couch3->SetPosition(125,100,302);

//	CollisionObject* random1 = new CollisionObject();
//	CollisionObject* random2 = new CollisionObject();
//	random1->AddBoxShape(100,100,100);
	//random2->AddBoxShape(100,100,5);
//	random1->SetPosition(100,0,-50);
//	random2->SetPosition(100,100,0);

	/*********************ENDS HERE*********??????????????/////////////*/

	Core::Game::getSceneManager()->GetScene()->getObject("Camera")->setPosition(Ogre::Vector3(-623.419, -277, -1048.77));
	Player->SetLastPos(-623.419, -277, -1048.77);
	return 0;
}

void Game::gameLoop()
{
	while( m_running )
	{
		CollisionWorldSingleton::Instance()->CheckCollision();
		//std::cout<<m_sceneManager->GetScene()->getObject("Camera")->getPosition().z<<"\n";
		Player->SetLastPos(m_sceneManager->GetScene()->getObject("Camera")->getPosition().x,m_sceneManager->GetScene()->getObject("Camera")->getPosition().y,m_sceneManager->GetScene()->getObject("Camera")->getPosition().z);
		m_keyboard->capture();
		m_mouse->capture();
		
		
		m_graphics->renderOneFrame();

		if( m_sceneManager )
		{
			m_sceneManager->updateScene( m_graphics->getDeltaTime() );
		}
		
		PlayerSphere->SetPosition(m_sceneManager->GetScene()->getObject("Camera")->getPosition().x,m_sceneManager->GetScene()->getObject("Camera")->getPosition().y,m_sceneManager->GetScene()->getObject("Camera")->getPosition().z);
	}
}