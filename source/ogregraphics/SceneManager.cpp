#include "StdAfx.h"
#include "SceneManager.h"

using namespace Scenes;

//-----------------------------------------------------------------------------

SceneManager::SceneManager(void)
{
	m_currentScene = NULL;
	m_previousScene = NULL;
}

//-----------------------------------------------------------------------------

SceneManager::SceneManager( IScene* scene )
{
	m_currentScene = scene;
	m_currentScene->initialise();

	m_previousScene = NULL;
}

//-----------------------------------------------------------------------------

SceneManager::~SceneManager(void)
{
	if( m_currentScene ) delete m_currentScene;
	if( m_previousScene ) delete m_previousScene;
}

//-----------------------------------------------------------------------------

void SceneManager::changeScene( IScene* scene )
{
	if( m_currentScene )
	{	
		m_currentScene->onExit();
		m_previousScene = m_currentScene;
	}

	m_currentScene = scene;
	m_currentScene->initialise();
}

//-----------------------------------------------------------------------------

void SceneManager::revertToPreviousScene()
{
	if( m_previousScene )
	{
		m_currentScene = m_previousScene;
	}
}

//-----------------------------------------------------------------------------

void SceneManager::updateScene( float deltaTime )
{
	if( m_currentScene ) m_currentScene->update( deltaTime );
}

//-----------------------------------------------------------------------------