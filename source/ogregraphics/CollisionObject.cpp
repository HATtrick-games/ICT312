#include "stdafx.h"
#include "CollisionObject.h"
#include "Utils/OgreBulletConverter.h"
#include "Utils/OgreBulletCollisionsMeshToShapeConverter.h"
#include "Shapes/OgreBulletCollisionsConvexHullShape.h"
#include "Shapes/OgreBulletCollisionsTrimeshShape.h"
#include "Shapes/OgreBulletCollisionsSphereShape.h"
//#include "btShapeHull.h"
//#include "btConvexHullShape.h"




CollisionObject::CollisionObject()
{
ShapeAdded = false;
BulletCollisionObject = new btCollisionObject();

}

void CollisionObject::SetUserPointer(void* obj)
{
	
	BulletCollisionObject->setUserPointer(obj);
}


void CollisionObject::AddMeshShapeWithOffset(Ogre::Entity* Ent, Ogre::Vector3 Offset)
{

}


void CollisionObject::AddSphereShape(Ogre::Entity* Ent)
{
	OgreBulletCollisions::StaticMeshToShapeConverter *convert;


	convert = new OgreBulletCollisions::StaticMeshToShapeConverter(Ent, Ent->_getParentNodeFullTransform());
	
	
	OgreBulletCollisions::SphereCollisionShape * shape = convert->createSphere();
	
	//btBoxShape * mesh = (btSphereShape*)(shape->getBulletShape());
	btSphereShape * mesh = (btSphereShape*)(shape->getBulletShape());
	BulletCollisionObject->setCollisionShape(mesh);
	CollisionWorldSingleton::Instance()->AddObject(BulletCollisionObject);
}

void CollisionObject::AddMeshShape(Ogre::Entity* Ent)
{
	
	OgreBulletCollisions::StaticMeshToShapeConverter *convert;


	convert = new OgreBulletCollisions::StaticMeshToShapeConverter(Ent, Ent->_getParentNodeFullTransform());
	//std::cout<<"OMFG WHY IS THIS PART NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";


	OgreBulletCollisions::TriangleMeshCollisionShape *shape = convert->createTrimesh();
	//OgreBulletCollisions::BoxCollisionShape * shape = convert->createBox();
	//OgreBulletCollisions::ConvexHullCollisionShape * shape = convert->createConvex();
	
	//btConvexHullShape * mesh = (btConvexHullShape*)(shape->getBulletShape());
	//btBoxShape * mesh = (btBoxShape*)(shape->getBulletShape());
	btTriangleMeshShape * mesh =(btTriangleMeshShape*)shape->getBulletShape();



	BulletCollisionObject->setCollisionShape(mesh);
	CollisionWorldSingleton::Instance()->AddObject(BulletCollisionObject);

	
	
	

}

void CollisionObject::AddBoxMesh(Ogre::Entity* Ent)
{
	OgreBulletCollisions::StaticMeshToShapeConverter *convert;


	convert = new OgreBulletCollisions::StaticMeshToShapeConverter(Ent, Ent->_getParentNodeFullTransform());
		
	OgreBulletCollisions::BoxCollisionShape * shape = convert->createBox();
	
	
	btBoxShape * mesh = (btBoxShape*)(shape->getBulletShape());
	
	BulletCollisionObject->setCollisionShape(mesh);
	CollisionWorldSingleton::Instance()->AddObject(BulletCollisionObject);

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

void CollisionObject::SetPosition(Ogre::Vector3 vecpos)
{
	BulletCollisionObject->getWorldTransform().setOrigin(btVector3(vecpos.x, vecpos.y, vecpos.z));
}

void CollisionObject::MoveObject(Ogre::Vector3 vec)
{
	vec.x = (BulletCollisionObject->getWorldTransform().getOrigin().x() + vec.x);
	vec.y = (BulletCollisionObject->getWorldTransform().getOrigin().y() + vec.y);
	vec.z = (BulletCollisionObject->getWorldTransform().getOrigin().z() + vec.z);

	BulletCollisionObject->getWorldTransform().setOrigin(btVector3(vec.x,vec.y,vec.z));
}

Ogre::Vector3 CollisionObject::GetObjectPosition()
{
	Ogre::Vector3 Vector;
	Vector.x = BulletCollisionObject->getWorldTransform().getOrigin().x();
	Vector.y = BulletCollisionObject->getWorldTransform().getOrigin().y();
	Vector.z = BulletCollisionObject->getWorldTransform().getOrigin().z();
	return Vector;
}

void CollisionObject::SetObjectOrientation(float x, float y, float z, float Degrees)
{
	Degrees = (Degrees*(3.14159265359/180));
	btQuaternion quat(btVector3(x,y,z),Degrees);
	quat = BulletCollisionObject->getWorldTransform().getRotation();
	quat = quat.normalize();
	quat.setRotation(btVector3(x,y,z),1.57079633);
	
	BulletCollisionObject->getWorldTransform().setRotation(quat);
}

void CollisionObject::SetObjectOrientation(Ogre::Quaternion quat)
{
	btQuaternion btquat(quat.x,quat.y,quat.z,quat.w);
	BulletCollisionObject->getWorldTransform().setRotation(btquat);
		
		
}

void CollisionObject::SetScale(float xs, float ys, float zs)
{
	BulletCollisionObject->getCollisionShape()->setLocalScaling(btVector3(xs,ys,zs));

}