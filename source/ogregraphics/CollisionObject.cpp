#include "stdafx.h"
#include "CollisionObject.h"


CollisionObject::CollisionObject()
{
ShapeAdded = false;
BulletCollisionObject = new btCollisionObject();

}

void CollisionObject::SetUserPointer(void* obj)
{
	
	BulletCollisionObject->setUserPointer(obj);
}

void CollisionObject::AddBoxShape(float xLength, float yLength, float zLength)
{
	//check to see if object already has a shape
	if(ShapeAdded)
	{
		std::cout<<"This Collision Object has already been added to collision world \n";
	}
	else
	{
		ShapeAdded = true;
		//bullet box takes dimensions as half extents so passed in values need to be halved.
		xLength = xLength/2;
		yLength = yLength/2;
		zLength = zLength/2;

		btBoxShape* box = new btBoxShape(btVector3(xLength,yLength,zLength));
		BulletCollisionObject->setCollisionShape(box);
		CollisionWorldSingleton::Instance()->AddObject(BulletCollisionObject);
		std::cout<<"Collision box object has been added to collision world \n";
	}
}

void CollisionObject::AddSphereShape(float Radius)
{
	//Check to see if object already added
	if(ShapeAdded)
	{
		std::cout<<"This CollisionObject has already been added to collision World \n";
	}
	else
	{
		ShapeAdded = true;
		btSphereShape* sphere = new btSphereShape(Radius);
		BulletCollisionObject->setCollisionShape(sphere);
		CollisionWorldSingleton::Instance()->AddObject(BulletCollisionObject);
		std::cout<<"Collision sphere object has been added to collision world \n";
	}

}

void CollisionObject::SetPosition(float xpos, float ypos, float zpos)
{
	BulletCollisionObject->getWorldTransform().setOrigin(btVector3(xpos, ypos, zpos));
}

void CollisionObject::SetPosition(Math::Vector3 vecpos)
{
	BulletCollisionObject->getWorldTransform().setOrigin(btVector3(vecpos.x, vecpos.y, vecpos.z));
}

void CollisionObject::MoveObject(Math::Vector3 vec)
{
	vec.x = (BulletCollisionObject->getWorldTransform().getOrigin().x() + vec.x);
	vec.y = (BulletCollisionObject->getWorldTransform().getOrigin().y() + vec.y);
	vec.z = (BulletCollisionObject->getWorldTransform().getOrigin().z() + vec.z);

	BulletCollisionObject->getWorldTransform().setOrigin(btVector3(vec.x,vec.y,vec.z));
}

Math::Vector3 CollisionObject::GetObjectPosition()
{
	Math::Vector3 Vector;
	Vector.x = BulletCollisionObject->getWorldTransform().getOrigin().x();
	Vector.y = BulletCollisionObject->getWorldTransform().getOrigin().y();
	Vector.z = BulletCollisionObject->getWorldTransform().getOrigin().z();
	return Vector;
}

void CollisionObject::SetObjectOrientation(Math::Vector3 axis, float Degrees)
{
	Degrees = (Degrees*(3.14159265359/180));
	btQuaternion quat(btVector3(axis.x,axis.y,axis.z),Degrees);
	BulletCollisionObject->getWorldTransform().setRotation(quat);
}