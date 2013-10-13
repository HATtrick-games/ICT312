#pragma once

#include "IObject.h"

namespace Objects
{
	class RigidBodyObject :
		public GenericObject
	{
	public:
		RigidBodyObject(void);
		~RigidBodyObject(void);

		virtual void		initialise();
		virtual void		update( float deltaTime );

		void applyForce(Ogre::Vector3 force);

	protected:
		Ogre::Vector3 m_force;
		float m_mass;
		float m_restitution;

		Ogre::Vector3 m_acceleration;
		Ogre::Vector3 m_velocity;

		Ogre::Vector3 m_lastAcceleration;
	private:

	};
}