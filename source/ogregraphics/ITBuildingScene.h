#pragma once

#include "IScene.h"

namespace Scenes
{
	class ITBuildingScene :
		public IScene
	{
	public:
		virtual void initialise();
		virtual void update( float deltaTime );
		virtual void onExit();

	private:
		CameraType		m_cameraType;
		float cameraSpeed;
	
		void createScene();
		void freeCamera( float deltaTime );
		void firstPersonCamera( float deltaTime );

		void moveObject( std::string objectName, float deltaTime ); // FOR DEBUG PURPOSES
	};
}
