# pragma once
#ifndef COLLISION_WORLD_SINGLETON
#include "OgreBulletCollisions.h"
#include "OgreBulletCollisionsObject.h"
#include "Debug/OgreBulletCollisionsDebugShape.h"

#include "OgreBulletCollisionsObjectState.h"
#include "OgreBulletCollisionsShape.h"
#include "OgreBulletCollisionsWorld.h"
#include "OgreBulletCollisionsPreRequisites.h"
#include "Shapes/OgreBulletCollisionsBoxShape.h"  
#include "Vector3.h"
#include "OgreGraphics.h"
#include "OgreBulletDraw.h"

//#include "PhysicsEngine.h"


class CollisionWorldSingleton
{
public:
	static CollisionWorldSingleton* Instance();
	void AddObject(btCollisionObject* colobj);
	void CheckCollision();
protected:
private:
	int i;
	OgreBulletDraw* DebugObject;
	btDbvtBroadphase*	broadphase;
	btCollisionWorld* collisionWorld;
	btCollisionDispatcher* dispatcher;
	btDefaultCollisionConfiguration* collisionConfiguration;

	CollisionWorldSingleton()
	{
		i = 0;
		DebugObject = new OgreBulletDraw();
		collisionConfiguration = new btDefaultCollisionConfiguration();
		dispatcher = new btCollisionDispatcher(collisionConfiguration);
		broadphase = new btDbvtBroadphase();
		collisionWorld = new btCollisionWorld(dispatcher,broadphase,collisionConfiguration);
		collisionWorld->setDebugDrawer(DebugObject);
		collisionWorld->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
		
	}
};

#endif;