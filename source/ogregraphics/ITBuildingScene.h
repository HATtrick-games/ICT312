/**
 * \file	ITBuildingScene.h
 *
 * \brief	Declares the iterator building scene class.
 */

#pragma once

#include "IScene.h"
#include "ExitScene.h"
#include "SceneLoader.h"
#include "TargetObject.h"
#include "ProjectileObject.h"

namespace Scenes
{
	/**
	 * \class	ITBuildingScene
	 *
	 * \brief	Iterator building scene.
	 */

	class ITBuildingScene :
		public IScene
	{
	public:

		/**
		 * \fn	virtual void ITBuildingScene::initialise();
		 *
		 * \brief	Initialises this object.
		 */

		virtual void initialise();

		/**
		 * \fn	virtual void ITBuildingScene::update( float deltaTime );
		 *
		 * \brief	Updates the given deltaTime.
		 *
		 * \param	deltaTime	Time of the delta.
		 */

		virtual void update( float deltaTime );

		/**
		 * \fn	virtual void ITBuildingScene::onExit();
		 *
		 * \brief	Executes the exit action.
		 */

		virtual void onExit();

	private:
		SceneLoader m_sceneLoader;

		/**
		 * \brief	Type of the camera.
		 */

		CameraType		m_cameraType;
		float cameraSpeed;

		/**
		 * \brief	true to projectile key down.
		 */

		bool m_projectileKeyDown;
		int m_numProjectiles;

		/**
		 * \fn	void ITBuildingScene::createScene();
		 *
		 * \brief	Creates the scene.
		 */

		void createScene();
		void freeCamera( float deltaTime );

		/**
		 * \fn	void ITBuildingScene::firstPersonCamera( float deltaTime );
		 *
		 * \brief	First person camera.
		 *
		 * \param	deltaTime	Time of the delta.
		 */

		void firstPersonCamera( float deltaTime );

		/**
		 * \fn	void ITBuildingScene::createProjectile();
		 *
		 * \brief	Creates the projectile.
		 */

		void createProjectile();

		/**
		 * \fn	void ITBuildingScene::moveObject( std::string objectName, float deltaTime );
		 *
		 * \brief	Move object.
		 *
		 * \param	objectName	Name of the object.
		 * \param	deltaTime 	Time of the delta.
		 */

		void moveObject( std::string objectName, float deltaTime ); // FOR DEBUG PURPOSES
	};
}
