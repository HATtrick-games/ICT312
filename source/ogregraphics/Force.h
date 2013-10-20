#pragma once

#include "stdafx.h"

namespace Physics
{
	struct Force
	{
		Force() {}
		Force(Ogre::Vector3 pos, Ogre::Vector3 dir, float mag)
		{
			pos = position;
			direction = dir;
			magnitude = mag;
		}

		Ogre::Vector3 position;
		Ogre::Vector3 direction;
		float magnitude;
	};
}