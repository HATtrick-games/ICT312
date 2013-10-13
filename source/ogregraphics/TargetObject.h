#pragma once

#include "rigidbodyobject.h"

namespace Objects
{
	class TargetObject :
		public RigidBodyObject
	{
	public:
		TargetObject(void);
		~TargetObject(void);

		virtual void initialise();

		virtual void update( float deltaTime );
	};
}