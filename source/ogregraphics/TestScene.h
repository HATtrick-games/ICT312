#pragma once

#include "IScene.h"
#include "TestObject.h"
#include "GenericObject.h"
#include "TargetObject.h"

enum CameraType
{
	CAM_FREE,
	CAM_FIRSTPERSON
};

namespace Scenes
{
	class TestScene :
		public Scenes::IScene
	{
	public:
		virtual void initialise();
		virtual void update( float deltaTime );
		virtual void onExit();

	private:
		CameraType		m_cameraType;
		bool			m_projectileKeyDown;
		int				m_numProjectiles;

		void freeCamera( float deltaTime );
		void firstPersonCamera( float deltaTime );

		void createProjectile();
	};
}