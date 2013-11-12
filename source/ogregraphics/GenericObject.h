/**
 * \file	GenericObject.h
 *
 * \brief	Declares the generic object class.
 */

#pragma once

#include "IObject.h"


namespace Objects
{
	class IObject;
};

namespace Objects
{
	/**
	 * \class	GenericObject
	 *
	 * \brief	Generic object.
	 */

	class GenericObject :
		public IObject
	{
	public:

		/**
		 * \fn	GenericObject::GenericObject();
		 *
		 * \brief	Default constructor.
		 */

		GenericObject();

		/**
		 * \fn	GenericObject::GenericObject(Ogre::Vector3 pos, Ogre::Vector3 rot, std::string meshFile);
		 *
		 * \brief	Constructor.
		 *
		 * \param	pos			The position.
		 * \param	rot			The rot.
		 * \param	meshFile	The mesh file.
		 */

		GenericObject(Ogre::Vector3 pos, Ogre::Vector3 rot, std::string meshFile);

		/**
		 * \fn	GenericObject::GenericObject(Ogre::Vector3 pos, Ogre::Quaternion rot, Ogre::Vector3 scale,
		 *  std::string meshFile);
		 *
		 * \brief	Constructor.
		 *
		 * \param	pos			The position.
		 * \param	rot			The rot.
		 * \param	scale   	The scale.
		 * \param	meshFile	The mesh file.
		 */

		GenericObject(Ogre::Vector3 pos, Ogre::Quaternion rot, Ogre::Vector3 scale, std::string meshFile);

		/**
		 * \fn	GenericObject::~GenericObject(void);
		 *
		 * \brief	Destructor.
		 */

		~GenericObject(void);

		/**
		 * \fn	virtual void GenericObject::initialise();
		 *
		 * \brief	bool Generic;
		 */

		virtual void initialise();

		/**
		 * \fn	virtual void GenericObject::update( float deltaTime );
		 *
		 * \brief	Updates the given deltaTime.
		 *
		 * \param	deltaTime	Time of the delta.
		 */

		virtual void update( float deltaTime );
	};

}