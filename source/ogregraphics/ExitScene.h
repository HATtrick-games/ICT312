#pragma once

#include "IScene.h"

namespace Scenes
{
	class ExitScene :
		public Scenes::IScene
	{
	public:
		virtual void initialise();
		virtual void update(float deltaTime);
		virtual void onExit();
	};
}