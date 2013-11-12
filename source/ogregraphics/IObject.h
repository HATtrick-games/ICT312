#pragma once

#include "CollisionObject.h"

namespace Objects
{
	class IObject
	{
	public:
		int AI;
		std::string Type;
		int m_id;
		virtual void		initialise() = 0;
		virtual void		update( float deltaTime );

		void				setMeshFile( std::string filename );
		void				MakeCollisionObject();
		void				MakeSphereCollisionObject();
		void				MakeBoxCollisionObject();

		Ogre::Vector3		getPosition();
		void				setPosition( Ogre::Vector3 pos );
		void				changePosition( Ogre::Vector3 pos );

		Ogre::Quaternion	getOrientation() const;
		Ogre::Vector3		getRotation() const;

		void				setOrientation( Ogre::Quaternion rot );
		void				rotateByVector( Ogre::Vector3& rot, float scale = 1.0f );
		void				setYaw( float angle );
		void				setPitch( float angle );
		void				setRoll( float angle );

		void				setScale( float x, float y, float z );
		void				setScale( Ogre::Vector3 scale );
		Ogre::Vector3		getScale();
		Ogre::Quaternion	getOrientation();

		std::string			getEntityName();
		Ogre::Entity*		getEntity();
		std::map<std::string,int>* GetMap();
		bool IsInteractable();
		void SetInteractable(bool set){Interactable = set;}
		int GetAffodance(std::string affordance);
		std::map<std::string,int> Affordances;
		bool Generic;
		bool isDynamic;
	protected:
		void				loadMesh() const;
		CollisionObject* ColObj;
		Ogre::Vector3 m_position;
		Ogre::Quaternion m_rotation;

		
		
		std::string m_filename;

		void setID();
	private:
		std::string m_entity;
		
		bool Interactable;
		
		
		static int m_objCount;
	};
}