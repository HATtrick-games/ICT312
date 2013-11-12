/**
 * \file	IObject.h
 *
 * \brief	Declares the IObject interface.
 */

#pragma once

#include "CollisionObject.h"

namespace Objects
{
	/**
	 * \class	IObject
	 *
	 * \brief	Object.
	 */

	class IObject
	{
	public:
		int AI;

		/**
		 * \brief	The type.
		 */

		std::string Type;

		/**
		 * \brief	The identifier.
		 */

		int m_id;

		/**
		 * \fn	virtual void IObject::initialise() = 0;
		 *
		 * \brief	Initialises this object.
		 */

		virtual void		initialise() = 0;

		/**
		 * \fn	virtual void IObject::update( float deltaTime );
		 *
		 * \brief	Updates the given deltaTime.
		 *
		 * \param	deltaTime	Time of the delta.
		 */

		virtual void		update( float deltaTime );

		/**
		 * \fn	void IObject::setMeshFile( std::string filename );
		 *
		 * \brief	Sets mesh file.
		 *
		 * \param	filename	Filename of the file.
		 */

		void				setMeshFile( std::string filename );

		/**
		 * \fn	void IObject::MakeCollisionObject();
		 *
		 * \brief	Makes collision object.
		 */

		void				MakeCollisionObject();

		/**
		 * \fn	void IObject::MakeSphereCollisionObject();
		 *
		 * \brief	Makes sphere collision object.
		 */

		void				MakeSphereCollisionObject();

		/**
		 * \fn	void IObject::MakeBoxCollisionObject();
		 *
		 * \brief	Makes box collision object.
		 */

		void				MakeBoxCollisionObject();

		/**
		 * \fn	Ogre::Vector3 IObject::getPosition();
		 *
		 * \brief	Gets the position.
		 *
		 * \return	The position.
		 */

		Ogre::Vector3		getPosition();

		/**
		 * \fn	void IObject::setPosition( Ogre::Vector3 pos );
		 *
		 * \brief	Sets a position.
		 *
		 * \param	pos	The position.
		 */

		void				setPosition( Ogre::Vector3 pos );

		/**
		 * \fn	void IObject::changePosition( Ogre::Vector3 pos );
		 *
		 * \brief	Change position.
		 *
		 * \param	pos	The position.
		 */

		void				changePosition( Ogre::Vector3 pos );

		/**
		 * \fn	Ogre::Quaternion IObject::getOrientation() const;
		 *
		 * \brief	Gets the orientation.
		 *
		 * \return	The orientation.
		 */

		Ogre::Quaternion	getOrientation() const;

		/**
		 * \fn	Ogre::Vector3 IObject::getRotation() const;
		 *
		 * \brief	Gets the rotation.
		 *
		 * \return	The rotation.
		 */

		Ogre::Vector3		getRotation() const;

		/**
		 * \fn	void IObject::setOrientation( Ogre::Quaternion rot );
		 *
		 * \brief	Sets an orientation.
		 *
		 * \param	rot	The rot.
		 */

		void				setOrientation( Ogre::Quaternion rot );

		/**
		 * \fn	void IObject::rotateByVector( Ogre::Vector3& rot, float scale = 1.0f );
		 *
		 * \brief	Rotate by vector.
		 *
		 * \param [in,out]	rot	The rot.
		 * \param	scale	   	(optional) the scale.
		 */

		void				rotateByVector( Ogre::Vector3& rot, float scale = 1.0f );

		/**
		 * \fn	void IObject::setYaw( float angle );
		 *
		 * \brief	Sets a yaw.
		 *
		 * \param	angle	The angle.
		 */

		void				setYaw( float angle );

		/**
		 * \fn	void IObject::setPitch( float angle );
		 *
		 * \brief	Sets a pitch.
		 *
		 * \param	angle	The angle.
		 */

		void				setPitch( float angle );

		/**
		 * \fn	void IObject::setRoll( float angle );
		 *
		 * \brief	Sets a roll.
		 *
		 * \param	angle	The angle.
		 */

		void				setRoll( float angle );

		/**
		 * \fn	void IObject::setScale( float x, float y, float z );
		 *
		 * \brief	Sets a scale.
		 *
		 * \param	x	The x coordinate.
		 * \param	y	The y coordinate.
		 * \param	z	The z coordinate.
		 */

		void				setScale( float x, float y, float z );

		/**
		 * \fn	void IObject::setScale( Ogre::Vector3 scale );
		 *
		 * \brief	Sets a scale.
		 *
		 * \param	scale	The scale.
		 */

		void				setScale( Ogre::Vector3 scale );

		/**
		 * \fn	Ogre::Vector3 IObject::getScale();
		 *
		 * \brief	Gets the scale.
		 *
		 * \return	The scale.
		 */

		Ogre::Vector3		getScale();

		/**
		 * \fn	Ogre::Quaternion IObject::getOrientation();
		 *
		 * \brief	Gets the orientation.
		 *
		 * \return	The orientation.
		 */

		Ogre::Quaternion	getOrientation();

		/**
		 * \fn	std::string IObject::getEntityName();
		 *
		 * \brief	Gets entity name.
		 *
		 * \return	The entity name.
		 */

		std::string			getEntityName();

		/**
		 * \fn	Ogre::Entity* IObject::getEntity();
		 *
		 * \brief	Gets the entity.
		 *
		 * \return	null if it fails, else the entity.
		 */

		Ogre::Entity*		getEntity();

		/**
		 * \fn	std::map<std::string,int>* IObject::GetMap();
		 *
		 * \brief	Gets the map.
		 *
		 * \return	null if it fails, else the map.
		 */

		std::map<std::string,int>* GetMap();

		/**
		 * \fn	bool IObject::IsInteractable();
		 *
		 * \brief	Query if this object is interactable.
		 *
		 * \return	true if interactable, false if not.
		 */

		bool IsInteractable();

		/**
		 * \fn	void IObject::SetInteractable(bool set)
		 *
		 * \brief	Sets an interactable.
		 *
		 * \param	set	true to set.
		 */

		void SetInteractable(bool set){Interactable = set;}

		/**
		 * \fn	int IObject::GetAffodance(std::string affordance);
		 *
		 * \brief	Gets an affodance.
		 *
		 * \param	affordance	The affordance.
		 *
		 * \return	The affodance.
		 */

		int GetAffodance(std::string affordance);

		/**
		 * \brief	The affordances.
		 */

		std::map<std::string,int> Affordances;

		/**
		 * \brief	true to generic.
		 */

		bool Generic;

		/**
		 * \brief	true if this object is dynamic.
		 */

		bool isDynamic;
	protected:

		/**
		 * \fn	void IObject::loadMesh() const;
		 *
		 * \brief	Loads the mesh.
		 */

		void				loadMesh() const;

		/**
		 * \brief	The col object.
		 */

		CollisionObject* ColObj;

		/**
		 * \brief	The position.
		 */

		Ogre::Vector3 m_position;

		/**
		 * \brief	The rotation.
		 */

		Ogre::Quaternion m_rotation;

		/**
		 * \brief	Filename of the file.
		 */

		std::string m_filename;

		/**
		 * \fn	void IObject::setID();
		 *
		 * \brief	Sets the identifier.
		 */

		void setID();
	private:

		/**
		 * \brief	The entity.
		 */

		std::string m_entity;
		
		bool Interactable;

		/**
		 * \brief	Number of objects.
		 */

		static int m_objCount;
	};
}