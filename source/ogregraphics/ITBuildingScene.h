#pragma once

#include "IScene.h"
#include "ExitScene.h"
#include "SceneLoader.h"
#include "TargetObject.h"
#include "ProjectileObject.h"

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

		bool m_projectileKeyDown;
		int m_numProjectiles;
	
		void createScene();
		void freeCamera( float deltaTime );
		void firstPersonCamera( float deltaTime );

		void createProjectile();

		void moveObject( std::string objectName, float deltaTime ); // FOR DEBUG PURPOSES
	};
}
