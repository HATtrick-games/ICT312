#pragma once

#include <cmath>
#include "RigidBodyObject.h"

namespace Objects
{
	class RigidBodyObject;
};

namespace Physics
{
	struct Contact
	{
		Contact() { }
		Contact(Objects::RigidBodyObject* a, Objects::RigidBodyObject* b,
			Ogre::Vector3 pos, Ogre::Vector3 norm)
		{
			A = a;
			B = b;

			position = pos;
			normal = norm;
		}

		void Initialise();

		void CalculateBasis();
		Ogre::Vector3 CalculateImpulse(Ogre::Matrix3* inverseInertiaTensor);
		Ogre::Vector3 CalculateLocalVelocity(bool isA);
		void CalculateDeltaVelocity();

		void ApplyVelocityChange(Ogre::Vector3 velocityChange[2], Ogre::Vector3 rotationChange[2]);

		Ogre::Matrix3 contactToWorld;
		Ogre::Matrix3 worldToContact;
		Ogre::Vector3 relativeContactPosition[2];
		Ogre::Vector3 localVelocity;
		float desiredDeltaVelocity;
		Ogre::Vector3 contactVelocity;

		float restitution;

		Objects::RigidBodyObject* A;
		Objects::RigidBodyObject* B;

		Ogre::Vector3 position;
		Ogre::Vector3 normal;
	};
}
