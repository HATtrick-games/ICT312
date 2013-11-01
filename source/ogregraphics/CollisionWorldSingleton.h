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
#include "DebugDrawerOg.h"
#include "Game.h"

//#include "Manifold.h"

/**
 * \class	CollisionWorldSingleton
 *
 * \brief	Collision world singleton.
 *
 * \author	Arran Ford
 * \date	31/10/2013
 */

class CollisionWorldSingleton
{
public:
	bool Draw;
	void SetUpDebug();
	/**
	 * \fn	static CollisionWorldSingleton* CollisionWorldSingleton::Instance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * \return	null if it fails, else.
	 */

	static CollisionWorldSingleton* Instance();

	/**
	 * \fn	void CollisionWorldSingleton::AddObject(btCollisionObject* colobj);
	 *
	 * \brief	Adds an object.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * \param [in,out]	colobj	If non-null, the colobj.
	 */

	void AddObject(btCollisionObject* colobj);

	/**
	 * \fn	void CollisionWorldSingleton::CheckCollision();
	 *
	 * \brief	Check collision.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 */

	void CheckCollision();
protected:
private:
	


	OgreDebugDrawer* OgreDebugger;

	/**
	 * \brief	Zero-based index of the.
	 */

	int i;

	/**
	 * \brief	The debug object.
	 */

	OgreBulletDraw* DebugObject;

	/**
	 * \brief	The broadphase.
	 */

	btDbvtBroadphase*	broadphase;

	/**
	 * \brief	The collision world.
	 */

	btCollisionWorld* collisionWorld;

	/**
	 * \brief	The dispatcher.
	 */

	btCollisionDispatcher* dispatcher;

	/**
	 * \brief	The collision configuration.
	 */

	btDefaultCollisionConfiguration* collisionConfiguration;

	/**
	 * \fn	CollisionWorldSingleton::CollisionWorldSingleton()
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 */

	CollisionWorldSingleton()
	{
		i = 0;
		

		Draw = false;
		DebugObject = new OgreBulletDraw();
		collisionConfiguration = new btDefaultCollisionConfiguration();
		dispatcher = new btCollisionDispatcher(collisionConfiguration);
		broadphase = new btDbvtBroadphase();
		collisionWorld = new btCollisionWorld(dispatcher,broadphase,collisionConfiguration);
		
		//collisionWorld->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
		
	}

	
};

/**
// End of CollisionWorldSingleton.h
 */

#endif;