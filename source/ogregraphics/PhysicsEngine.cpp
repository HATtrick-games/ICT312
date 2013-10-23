#include "StdAfx.h"
#include "PhysicsEngine.h"
#include <cmath>

using namespace Physics;

Ogre::Vector3 PhysicsEngine::GRAVITY = Ogre::Vector3(0.0f, -9.8f, 0.0f);

void PhysicsEngine::ResolveCollision(Physics::Manifold& manifold)
{
	Ogre::Vector3 a_extent = manifold.A->getEntity()->getBoundingBox().getHalfSize();
	Ogre::Vector3 b_extent = manifold.B->getEntity()->getBoundingBox().getHalfSize();

	// translation vector
	Ogre::Vector3 translation = manifold.B->getPosition() - manifold.A->getPosition();

	// get overlapping vectors
	float x_overlap = a_extent.x + b_extent.x - std::abs(translation.x);
	float y_overlap = a_extent.y + b_extent.y - std::abs(translation.y);
	float z_overlap = a_extent.z + b_extent.z - std::abs(translation.z);

	// get contacts
	Contact c1, c2;
	c1.position.x = max( manifold.A->getEntity()->getBoundingBox().getMinimum().x, manifold.B->getEntity()->getBoundingBox().getMinimum().x );
	c1.position.y = max( manifold.A->getEntity()->getBoundingBox().getMinimum().y, manifold.B->getEntity()->getBoundingBox().getMinimum().y );
	c1.position.z = max( manifold.A->getEntity()->getBoundingBox().getMinimum().z, manifold.B->getEntity()->getBoundingBox().getMinimum().z );
	c2.position.x = min( manifold.A->getEntity()->getBoundingBox().getMaximum().x, manifold.B->getEntity()->getBoundingBox().getMaximum().x );
	c2.position.y = min( manifold.A->getEntity()->getBoundingBox().getMaximum().y, manifold.B->getEntity()->getBoundingBox().getMaximum().y );
	c2.position.z = min( manifold.A->getEntity()->getBoundingBox().getMaximum().z, manifold.B->getEntity()->getBoundingBox().getMaximum().z );

	if(x_overlap > y_overlap && x_overlap > z_overlap)
	{
		manifold.normal = translation.x < 0 ? Ogre::Vector3(1, 0, 0) : Ogre::Vector3(-1, 0, 0);
		manifold.penetration = x_overlap;
	}
	else if(y_overlap > x_overlap && y_overlap > z_overlap)
	{
		manifold.normal = translation.y < 0 ? Ogre::Vector3(0, 1, 0) : Ogre::Vector3(0, -1, 0);
		manifold.penetration = y_overlap;
	}
	else if(z_overlap > x_overlap && z_overlap > y_overlap)
	{
		manifold.normal = translation.z < 0 ? Ogre::Vector3(0, 0, 1) : Ogre::Vector3(0, 0, -1);
		manifold.penetration = z_overlap;
	}

	//std::cout << "Normal: " << manifold.normal << std::endl;
	//std::cout << "Penetration: " << manifold.normal << std::endl;
	//std::cout << "Contacts: " << manifold.numContacts << std::endl;
	//std::cout << manifold.contacts[0] << std::endl;
	//std::cout << manifold.contacts[1] << std::endl;
	std::cout << c1.position << std::endl;
	std::cout << c2.position << std::endl;

	ApplyImpulse(manifold);
}

void PhysicsEngine::ApplyImpulse(Physics::Manifold& manifold)
{
	Ogre::Vector3 relativeVel = manifold.B->getVelocity() - manifold.A->getVelocity();
	float contactVelocity = relativeVel.dotProduct(manifold.normal);

	// no need to resolve if moving away from each other
	if(contactVelocity > 0)
		return;

	float impulseScalar = -1.0f * contactVelocity;
	impulseScalar /= (1.0f / manifold.A->getMass()) + (1.0f / manifold.B->getMass());

	Ogre::Vector3 impulse = impulseScalar * manifold.normal;
	manifold.A->setVelocity(manifold.A->getVelocity() - (impulse / manifold.A->getMass()));
	manifold.B->setVelocity(manifold.B->getVelocity() + (impulse / manifold.B->getMass()));
}

bool PhysicsEngine::AABBvsAABB(Physics::Manifold& manifold)
{
	/*Objects::RigidBodyObject* A = manifold.A;
	Objects::RigidBodyObject* B = manifold.B;

	Ogre::Vector3 n = B->getPosition() - A->getPosition;

	Ogre::AxisAlignedBox aBox = A->getEntity()->getBoundingBox();
	Ogre::AxisAlignedBox bBox = B->getEntity()->getBoundingBox();

	float aExtent = (aBox.getMaximum().x - aBox.getMinimum().x) / 2.0f;
	float bExtent = (bBox.getMaximum().x - bBox.getMinimum().x) / 2.0f;

	float xOverlap = aExtent + bExtent - abs(n.x);

	if(xOverlap > 0)
	{
		aExtent = (aBox.getMaximum().y - aBox.getMinimum().y) / 2.0f;
		bExtent = (bBox.getMaximum().y - bBox.getMinimum().y) / 2.0f;

		float yOverlap = aExtent + bExtent - abs(n.y);

		if(yOverlap > 0)
		{
			aExtent = (aBox.getMaximum().z - aBox.getMinimum().y) / 2.0f;
		}
	}*/
	return true;
}