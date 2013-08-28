#pragma once

#include "IScene.h"
#include "TestObject.h"

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

		void freeCamera( float deltaTime );
		void firstPersonCamera( float deltaTime );
	};
}