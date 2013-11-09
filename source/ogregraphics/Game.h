#pragma once

#include "OgreGraphics.h"
#include "SceneManager.h"
#include "TestScene.h"
#include "ITBuildingScene.h"
#include "AIManager.h"

namespace Core
{
	class Game
	{
	public:
		~Game(void);
		
		static int		initialise();
		static void		gameLoop();

		static bool		getRunning() { return m_running; }
		static void		setRunning( bool running ) { m_running = running; }

		static Graphics::OgreGraphics*	getGraphics() { return m_graphics; }
		static Scenes::SceneManager*	getSceneManager() { return m_sceneManager; }
		static OIS::InputManager*		getInputManager() { return m_inputManager; }
		static OIS::Keyboard*			getKeyboard() { return m_keyboard; }
		static OIS::Mouse*				getMouse() { return m_mouse; }

		/**
		 * \fn	static void Game::TestSelect();
		 *
		 * \brief	This is a raycasting function for triggering a response in AI.
		 *
		 * \author	Arran Ford
		 * \date	09/11/2013
		 */

		static void TestSelect();

		/**
		 * \fn	static void Game::SetAffordances();
		 *
		 * \brief	Sets affordances for objects in the world
		 *
		 * \author	Arran Ford
		 * \date	09/11/2013
		 */

		static void SetAffordances();
	private:
		Game() { }

		static bool						m_running;

		static Graphics::OgreGraphics*	m_graphics;
		static Scenes::SceneManager*	m_sceneManager;
		static OIS::InputManager*		m_inputManager;
		static OIS::Keyboard*			m_keyboard;
		static OIS::Mouse*				m_mouse;

		void BuildCollisionRoom();
	};
}

int main( int argc, char** argv )
{
	Core::Game::initialise();
	Core::Game::gameLoop();

	return 0;
}