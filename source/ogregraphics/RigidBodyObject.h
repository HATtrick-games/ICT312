#pragma once

#include "IObject.h"
#include "Constants.h"

namespace Objects
{
	class RigidBodyObject :
		public IObject
	{
	public:
		RigidBodyObject(void);
		~RigidBodyObject(void);

		virtual void		initialise();
		virtual void		update( float deltaTime );

		void checkPosition();
	protected:
		Ogre::Vector3 m_force;
		float m_mass;
		float m_restitution;

		Ogre::Vector3 m_position;
		Ogre::Vector3 m_acceleration;
		Ogre::Vector3 m_velocity;
	private:

	};
}