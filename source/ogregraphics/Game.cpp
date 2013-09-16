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
CollisionObject* col1;
CollisionObject* col2;
CollisionObject* PlayerSphere;
CollisionObject* col[10];
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
	m_sceneManager = new Scenes::SceneManager( new Scenes::ITBuildingScene() );


	 Player = new TemporaryPlayerObject();
	 col1 = new CollisionObject();
	 col2 = new CollisionObject();
	 col1->AddBoxShape(12,12,12);
	 col2->AddBoxShape(1,1,1);
	 col1->SetPosition(0,0,-50);
	 col2->SetPosition(10,0,0);
	 PlayerSphere = new CollisionObject();
	 PlayerSphere->AddSphereShape(0.1);
	 PlayerSphere->SetPosition(0,0,0);
	 PlayerSphere->SetUserPointer(Player);
	
/*	for(int i = 0; i<10; i++)
	{
		col[i] = new CollisionObject();
		col[i]->AddBoxShape(1,1,1);
		col[i]->SetPosition(1,1,1);
	}*/

	return 0;
}

void Game::gameLoop()
{
	while( m_running )
	{
		CollisionWorldSingleton::Instance()->CheckCollision();
		
		Player->SetLastPos(m_sceneManager->GetScene()->getObject("Player")->getPosition().x,m_sceneManager->GetScene()->getObject("Player")->getPosition().y,m_sceneManager->GetScene()->getObject("Player")->getPosition().z);
		m_keyboard->capture();
		m_mouse->capture();
		
		
		m_graphics->renderOneFrame();

		if( m_sceneManager )
		{
			m_sceneManager->updateScene( m_graphics->getDeltaTime() );
		}
		//std::cout<<m_sceneManager->GetScene()->getObject("Player")->getPosition().z;
		PlayerSphere->SetPosition(m_sceneManager->GetScene()->getObject("Player")->getPosition().x,m_sceneManager->GetScene()->getObject("Player")->getPosition().y,m_sceneManager->GetScene()->getObject("Player")->getPosition().z);
	}
}