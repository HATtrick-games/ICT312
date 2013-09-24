#pragma once

#include "IScene.h"
#include "SceneLoader.h"

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
		SceneLoader m_sceneLoader;

		CameraType		m_cameraType;
		float cameraSpeed;
	
		void createScene();
		void freeCamera( float deltaTime );
		void firstPersonCamera( float deltaTime );

		void moveObject( std::string objectName, float deltaTime ); // FOR DEBUG PURPOSES
	};
}
