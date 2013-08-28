#pragma once

#include "Vector3.h"

namespace Objects
{
	class IObject
	{
	public:
		IObject(void);
		~IObject(void);

		virtual void		initialise() = 0;
		virtual void		update( float deltaTime );

		Ogre::Vector3		getPosition();
		void				setPosition( Ogre::Vector3 pos );
		void				changePosition( Ogre::Vector3 pos );

		Ogre::Quaternion	getOrientation() const;

		void				setYaw( float angle );
		void				setPitch( float angle );
		void				setRoll( float angle );

	protected:
		void				loadMesh() const;

		Ogre::Vector3 m_position;
		Ogre::Quaternion m_rotation;

		
		std::string m_entity;
		std::string m_filename;
	};
}