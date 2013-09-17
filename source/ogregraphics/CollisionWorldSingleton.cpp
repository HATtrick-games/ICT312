#include "stdafx.h"
#include "CollisionWorldSingleton.h"
#include "CollisionObject.h"
#include "TemporaryPlayerObject.h"


CollisionWorldSingleton* CollisionWorldSingleton::Instance()
{
	static CollisionWorldSingleton instance;

	return &instance;
}

void CollisionWorldSingleton::AddObject(btCollisionObject* colobj)
{
	collisionWorld->addCollisionObject(colobj);
}

void CollisionWorldSingleton::CheckCollision()
{
	broadphase->calculateOverlappingPairs(dispatcher);
	collisionWorld->performDiscreteCollisionDetection();

	int numManifolds = collisionWorld->getDispatcher()->getNumManifolds();
	
	for (int i=0;i<numManifolds;i++)
	{
		
		btPersistentManifold* contactManifold =  collisionWorld->getDispatcher()->getManifoldByIndexInternal(i);
		btCollisionObject* obA = (btCollisionObject*)(contactManifold->getBody0());
		btCollisionObject* obB = (btCollisionObject*)(contactManifold->getBody1());
		
		if(obA->getUserPointer())
		{
		TemporaryPlayerObject* obj = (TemporaryPlayerObject*)obA->getUserPointer();
		Core::Game::getSceneManager()->GetScene()->getObject("Camera")->setPosition(Ogre::Vector3(obj->lastposition.x,obj->lastposition.y,obj->lastposition.z));

		}
		if(obB->getUserPointer())
		{
			TemporaryPlayerObject* obj = (TemporaryPlayerObject*)obB->getUserPointer();
			Core::Game::getSceneManager()->GetScene()->getObject("Camera")->setPosition(Ogre::Vector3(obj->lastposition.x,obj->lastposition.y,obj->lastposition.z));
		}
	
		
		

 
		int numContacts = contactManifold->getNumContacts();
		
		for (int j=0;j<numContacts;j++)
		{ 
			
			btManifoldPoint& pt = contactManifold->getContactPoint(j);
			if (pt.getDistance()<0.01f)
			{
				const btVector3& ptA = pt.getPositionWorldOnA();
				const btVector3& ptB = pt.getPositionWorldOnB();
				const btVector3& normalOnB = pt.m_normalWorldOnB;
				std::cout<<numContacts<<"COLLIDE \n\n\n\n\n";
				//Sleep(1000);
			}
					
		}
		contactManifold->clearManifold();	
	}


}