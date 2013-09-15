# pragma once
#ifndef COLLISION_WORLD_SINGLETON
#include "OgreBulletCollisions.h"
#include "OgreBulletCollisionsPreRequisites.h"
#include "OgreBulletCollisionsWorld.h"
#include "OgreBulletCollisionsObject.h"
#include "Shapes/OgreBulletCollisionsBoxShape.h"  
#include "Vector3.h"
#include "OgreGraphics.h"


class CollisionWorldSingleton
{
public:
	static CollisionWorldSingleton* Instance();
	void AddObject(btCollisionObject* colobj);
	void CheckCollision();
protected:
private:
	btDbvtBroadphase*	broadphase;
	btCollisionWorld* collisionWorld;
	btCollisionDispatcher* dispatcher;
	btDefaultCollisionConfiguration* collisionConfiguration;

	CollisionWorldSingleton()
	{
		collisionConfiguration = new btDefaultCollisionConfiguration();
		dispatcher = new btCollisionDispatcher(collisionConfiguration);
		broadphase = new btDbvtBroadphase();
		collisionWorld = new btCollisionWorld(dispatcher,broadphase,collisionConfiguration);
		
	}
};

#endif;