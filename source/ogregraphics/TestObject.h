#pragma once
#include "IObject.h"

namespace Objects
{
	class TestObject :
		public IObject
	{
	public:
		TestObject(void);
		~TestObject(void);

		virtual void			initialise();
		virtual void			update( float deltaTime );
	};
}