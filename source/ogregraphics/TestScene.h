/**
 * \file	TestScene.h
 *
 * \brief	Declares the test scene class.
 */

#pragma once

#include "IScene.h"
#include "TestObject.h"
#include "GenericObject.h"
#include "TargetObject.h"

/**
 * \enum	CameraType
 *
 * \brief	Values that represent CameraType.
 */

enum CameraType
{
	CAM_FREE,
	///< An enum constant representing the camera firstperson option
	CAM_FIRSTPERSON
};

namespace Scenes

/**
 * \namespace	Scenes
 *
 * \brief	.
 */

{
	class TestScene :
		public Scenes::IScene
	{
	public:

		/**
		 * \fn	virtual void initialise();
		 *
		 * \brief	Initialises this object.
		 */

		virtual void initialise();
		virtual void update( float deltaTime );

		/**
		 * \fn	virtual void onExit();
		 *
		 * \brief	Executes the exit action.
		 */

		virtual void onExit();

	private:
		CameraType		m_cameraType;
		bool			m_projectileKeyDown;

		/**
		 * \brief	Number of projectiles.
		 */

		int				m_numProjectiles;

		void freeCamera( float deltaTime );

		/**
		 * \fn	void firstPersonCamera( float deltaTime );
		 *
		 * \brief	First person camera.
		 *
		 * \param	deltaTime	Time of the delta.
		 */

		void firstPersonCamera( float deltaTime );

		void createProjectile();
	};
}