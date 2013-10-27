#include "StdAfx.h"
#include "Contact.h"

using namespace Physics;

void Contact::Initialise()
{
	assert(A && B);

	CalculateBasis();

	relativeContactPosition[0] = position - A->getPosition();
	relativeContactPosition[1] = position - B->getPosition();

	contactVelocity = CalculateLocalVelocity(true) - CalculateLocalVelocity(false);

	CalculateDeltaVelocity();
}

Ogre::Vector3 Contact::CalculateLocalVelocity(bool isA)
{
	Ogre::Vector3 velocity, accVelocity, contactVel;

	if(isA)
	{
		velocity = A->getRotation().crossProduct(relativeContactPosition[0]);
		velocity += A->getVelocity();

		accVelocity = A->getLastAcceleration() * Core::Game::getGraphics()->getDeltaTime();
	}
	else
	{
		velocity = B->getRotation().crossProduct(relativeContactPosition[0]);
		velocity += B->getVelocity();

		accVelocity = B->getLastAcceleration() * Core::Game::getGraphics()->getDeltaTime();
	}

	contactVel = worldToContact * velocity;

	accVelocity = worldToContact * accVelocity;
	accVelocity.x = 0;

	contactVel += accVelocity;

	return contactVel;
}

void Contact::CalculateDeltaVelocity()
{
	float velocityLimit = 0.25f;

	float velocityFromAcc = Core::Game::getGraphics()->getDeltaTime() * (A->getLastAcceleration().dotProduct(normal));
	velocityFromAcc -= Core::Game::getGraphics()->getDeltaTime() * (B->getLastAcceleration().dotProduct(normal));

	restitution = 1.0f; // 1:1 bounces
	if(abs(contactVelocity.x) < velocityLimit)
	{
		restitution = 0.0f;
	}

	desiredDeltaVelocity = -contactVelocity.x - restitution * (contactVelocity.x - velocityFromAcc);
}

void Contact::CalculateBasis()
{
	Ogre::Vector3 contactTangent[2];

	if(abs(normal.x) > abs(normal.y))
	{
		// scaling factor
		float scale = 1.0f / sqrt(normal.z * normal.z + normal.x * normal.x);

		// adjusted x axis
		contactTangent[0].x = normal.z * scale;
		contactTangent[0].y = 0;
		contactTangent[0].z = -normal.x * scale;

		// adjusted y axis
		contactTangent[1].x = normal.y * contactTangent[0].x;
		contactTangent[1].y = normal.z * contactTangent[0].x - normal.x * contactTangent[0].z;
		contactTangent[1].z = -normal.y * contactTangent[0].x;
	}
	else
	{
		// scaling factor
		float scale = 1.0f / sqrt(normal.z * normal.z + normal.y * normal.y);

		// adjusted x axis
		contactTangent[0].x = 0;
		contactTangent[0].y = -normal.z * scale;
		contactTangent[0].z = normal.y * scale;

		// adjusted y axis
		contactTangent[1].x = normal.y * contactTangent[0].z - normal.z * contactTangent[0].y;
		contactTangent[1].y = -normal.x * contactTangent[0].z;
		contactTangent[1].z = normal.z * contactTangent[0].y;
	}

	contactToWorld = Ogre::Matrix3(	normal.x, normal.y, normal.z,
							contactTangent[0].x, contactTangent[0].y, contactTangent[0].z,
							contactTangent[1].x, contactTangent[1].y, contactTangent[1].z);

	worldToContact = Ogre::Matrix3(contactToWorld.Transpose());
}

Ogre::Vector3 Contact::CalculateImpulse(Ogre::Matrix3* inverseInertiaTensor)
{
	Ogre::Vector3 impulseContact;

	Ogre::Vector3 deltaVelWorld = relativeContactPosition[0].crossProduct(normal);
	deltaVelWorld = inverseInertiaTensor[0] * deltaVelWorld;
	deltaVelWorld = deltaVelWorld.crossProduct(relativeContactPosition[0]);

	float deltaVelocity = deltaVelWorld.dotProduct(normal);
	deltaVelocity += A->getInverseMass();

	deltaVelWorld = relativeContactPosition[1].crossProduct(normal);
	deltaVelWorld = inverseInertiaTensor[1] * deltaVelWorld;
	deltaVelWorld = deltaVelWorld.crossProduct(relativeContactPosition[1]);

	deltaVelocity += deltaVelWorld.dotProduct(normal);
	deltaVelocity += B->getInverseMass();

	impulseContact.x = desiredDeltaVelocity / deltaVelocity;
	impulseContact.y = 0;
	impulseContact.z = 0;

	return impulseContact;
}

void Contact::ApplyVelocityChange()
{
	Ogre::Vector3 velocityChange[2];
	Ogre::Vector3 rotationChange[2];

	Ogre::Matrix3 inverseInertiaTensor[2]; 
	inverseInertiaTensor[0] = A->getInverseInertiaTensorWorld();
	inverseInertiaTensor[1] = B->getInverseInertiaTensorWorld();

	Ogre::Vector3 impulseContact = CalculateImpulse(inverseInertiaTensor);
	Ogre::Vector3 impulse = contactToWorld * impulseContact;

	Ogre::Vector3 impulsiveTorque = relativeContactPosition[0].crossProduct(impulse);
	rotationChange[0] = inverseInertiaTensor[0] * impulsiveTorque;
	velocityChange[0] = impulse * A->getInverseMass();

	A->addVelocity(velocityChange[0]);
	A->addRotation(rotationChange[0]);
	
	impulsiveTorque = relativeContactPosition[1].crossProduct(impulse);
	rotationChange[1] = inverseInertiaTensor[1] * impulsiveTorque;
	velocityChange[1] = impulse * A->getInverseMass();

	B->addVelocity(velocityChange[1]);
	B->addRotation(rotationChange[1]);
}