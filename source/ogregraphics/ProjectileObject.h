#pragma once
#include "rigidbodyobject.h"

namespace Objects
{
	class ProjectileObject :
		public RigidBodyObject
	{
	public:
		ProjectileObject(Ogre::Vector3 pos);
		~ProjectileObject(void);

		virtual void initialise();

		virtual void update( float deltaTime );
	};
}
