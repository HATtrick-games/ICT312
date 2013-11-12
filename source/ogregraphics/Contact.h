/**
 * \file	Contact.h
 *
 * \brief	Declares the contact class.
 */

#pragma once

#include <cmath>
#include "RigidBodyObject.h"

namespace Physics
{
	/**
	 * \struct	Contact
	 *
	 * \brief	Contact.
	 */

	struct Contact
	{
		/**
		 * \fn	Contact()
		 *
		 * \brief	Default constructor.
		 */

		Contact() { }

		/**
		 * \fn	Contact(Objects::RigidBodyObject* a, Objects::RigidBodyObject* b, Ogre::Vector3 pos,
		 *  Ogre::Vector3 norm)
		 *
		 * \brief	Constructor.
		 *
		 * \param [in,out]	a	If non-null, the Objects::RigidBodyObject* to process.
		 * \param [in,out]	b	If non-null, the Objects::RigidBodyObject* to process.
		 * \param	pos		 	The position.
		 * \param	norm	 	The normalise.
		 */

		Contact(Objects::RigidBodyObject* a, Objects::RigidBodyObject* b,
			Ogre::Vector3 pos, Ogre::Vector3 norm)
		{
			A = a;
			B = b;

			position = pos;
			normal = norm;

			Initialise();
			ApplyVelocityChange();
		}

		/**
		 * \fn	void Initialise();
		 *
		 * \brief	Initialises this object.
		 */

		void Initialise();

		/**
		 * \fn	void CalculateBasis();
		 *
		 * \brief	Calculates the basis.
		 */

		void CalculateBasis();

		/**
		 * \fn	Ogre::Vector3 CalculateImpulse(Ogre::Matrix3* inverseInertiaTensor);
		 *
		 * \brief	Calculates the impulse.
		 *
		 * \param [in,out]	inverseInertiaTensor	If non-null, the inverse inertia tensor.
		 *
		 * \return	The calculated impulse.
		 */

		Ogre::Vector3 CalculateImpulse(Ogre::Matrix3* inverseInertiaTensor);

		/**
		 * \fn	Ogre::Vector3 CalculateLocalVelocity(bool isA);
		 *
		 * \brief	Calculates the local velocity.
		 *
		 * \param	isA	true if this object is a.
		 *
		 * \return	The calculated local velocity.
		 */

		Ogre::Vector3 CalculateLocalVelocity(bool isA);

		/**
		 * \fn	void CalculateDeltaVelocity();
		 *
		 * \brief	Calculates the delta velocity.
		 */

		void CalculateDeltaVelocity();

		/**
		 * \fn	void ApplyVelocityChange();
		 *
		 * \brief	Applies the velocity change.
		 */

		void ApplyVelocityChange();

		/**
		 * \brief	The contact to world.
		 */

		Ogre::Matrix3 contactToWorld;

		/**
		 * \brief	The world to contact.
		 */

		Ogre::Matrix3 worldToContact;

		/**
		 * \brief	The relative contact position[ 2].
		 */

		Ogre::Vector3 relativeContactPosition[2];

		/**
		 * \brief	The local velocity.
		 */

		Ogre::Vector3 localVelocity;

		/**
		 * \brief	The desired delta velocity.
		 */

		float desiredDeltaVelocity;

		/**
		 * \brief	The contact velocity.
		 */

		Ogre::Vector3 contactVelocity;

		/**
		 * \brief	The restitution.
		 */

		float restitution;

		/**
		 * \brief	The Objects::RigidBodyObject* to process.
		 */

		Objects::RigidBodyObject* A;

		/**
		 * \brief	to process.
		 */

		Objects::RigidBodyObject* B;

		/**
		 * \brief	The position.
		 */

		Ogre::Vector3 position;

		/**
		 * \brief	The normal.
		 */

		Ogre::Vector3 normal;
	};
}
