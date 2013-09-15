#pragma once

#include "IScene.h"

namespace Scenes
{
	/**
	 * \class	SceneManager
	 *
	 * \brief	Manages the scenes used within the game allowing for changing
	 *			between scenes, updating scenes and even reverting to the
	 *			previous scene.
	 *			
	 * \author	Timothy Veletta
	 * \date	15/08/13
	 */
	class SceneManager
	{
	public:

		/**
		 * \fn	SceneManager::SceneManager(void);
		 *
		 * \brief	Default constructor.
		 */
		SceneManager(void);

		/**
		 * \fn	SceneManager::SceneManager( IScene* scene );
		 *
		 * \brief	Constructor also sets the current scene and initialises it.
		 *
		 * \param [in,out]	scene	If non-null, the scene to be set as current.
		 */
		SceneManager( IScene* scene );

		/**
		 * \fn	SceneManager::~SceneManager(void);
		 *
		 * \brief	Destructor.
		 */
		~SceneManager(void);

		/**
		 * \fn	void SceneManager::changeScene( IScene* scene );
		 *
		 * \brief	Changes the current scene to the input scene, exits the
		 * 			previous scene and initialises the new scene.
		 *
		 * \param [in,out]	scene	If non-null, the scene to be set as current.
		 */
		void changeScene( IScene* scene );

		/**
		 * \fn	void SceneManager::revertToPreviousScene();
		 *
		 * \brief	Revert to previous scene.
		 */
		void revertToPreviousScene();

		/**
		 * \fn	void SceneManager::updateScene( float deltaTime );
		 *
		 * \brief	Updates the current scene passing in the time between frames.
		 *
		 * \param	deltaTime	Time between frames.
		 */
		void updateScene( float deltaTime );

		Scenes::IScene* GetScene()
		{
			return m_currentScene;
		}
	private:
		Scenes::IScene*			m_currentScene;
		Scenes::IScene*			m_previousScene;
	};
}