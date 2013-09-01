#pragma once

#include "OBB.h"
#include "AABB.h"

namespace Collision
{
	class CollisionManager
	{
	public:
		CollisionManager(void);
		~CollisionManager(void);

		static bool TestAABBAABB(AABB a, AABB b);
	};
}