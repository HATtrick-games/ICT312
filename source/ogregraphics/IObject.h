#pragma once

#include "Vector3.h"

namespace Objects
{
	class IObject
	{
	public:
		virtual void		initialise() = 0;
		virtual void		update( float deltaTime );

		void				setMeshFile( std::string filename );

		Ogre::Vector3		getPosition();
		void				setPosition( Ogre::Vector3 pos );
		void				changePosition( Ogre::Vector3 pos );

		Ogre::Quaternion	getOrientation() const;

		void				setOrientation( Ogre::Quaternion rot );
		void				setYaw( float angle );
		void				setPitch( float angle );
		void				setRoll( float angle );

		void				setScale( float x, float y, float z );
		void				setScale( Ogre::Vector3 scale );

		std::string getEntity();
	protected:
		void				loadMesh() const;

		Ogre::Vector3 m_position;
		Ogre::Quaternion m_rotation;

		std::string m_filename;

		void setID();
	private:
		std::string m_entity;

		int m_id;
		static int m_objCount;
	};
}