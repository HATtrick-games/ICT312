#include "stdafx.h"
//#include "CollisionWorldSingleton.h"
//#include "CollisionObject.h"
//#include "TemporaryPlayerObject.h"
//#include "Manifold.h"
//#include "GenericObject.h"
#include "Contact.h"


CollisionWorldSingleton* CollisionWorldSingleton::Instance()
{
	static CollisionWorldSingleton instance;

	return &instance;
}

void CollisionWorldSingleton::AddObject(btCollisionObject* colobj)
{
	collisionWorld->addCollisionObject(colobj);
	
}

void CollisionWorldSingleton::SetUpDebug()
{
	
	
	 OgreDebugger = new OgreDebugDrawer(Core::Game::getGraphics()->GetSceneManager());
		OgreDebugger->setDebugMode( btIDebugDraw::DBG_DrawWireframe );
		collisionWorld->setDebugDrawer(OgreDebugger);
}

void CollisionWorldSingleton::CheckCollision()
{
	
	if(Draw)
	collisionWorld->debugDrawWorld();
	
//	}
	broadphase->calculateOverlappingPairs(dispatcher);
	collisionWorld->performDiscreteCollisionDetection();

	int numManifolds = collisionWorld->getDispatcher()->getNumManifolds();
	
	for (int i=0;i<numManifolds;i++)
	{
		
		btPersistentManifold* contactManifold =  collisionWorld->getDispatcher()->getManifoldByIndexInternal(i);
		btCollisionObject* obA = (btCollisionObject*)(contactManifold->getBody0());
		btCollisionObject* obB = (btCollisionObject*)(contactManifold->getBody1());

		if((obB->getUserPointer())&&(obA->getUserPointer()))
				{
					Objects::RigidBodyObject* A = static_cast<Objects::RigidBodyObject*>(obA->getUserPointer());
					Objects::RigidBodyObject* B = static_cast<Objects::RigidBodyObject*>(obB->getUserPointer());

					if(contactManifold->getNumContacts() > 0)
					{
						btManifoldPoint contact = contactManifold->getContactPoint(0);

						if((A->isDynamic && B->isDynamic)||(A->isDynamic && !B->isDynamic)||(!A->isDynamic && B->isDynamic))
						{
							if(A->Generic || B->Generic)
							{
							//std::cout << "Collision Generic" << std::endl;
							}
							else
							{
							//std::cout << "Collision" << std::endl;

							Physics::Contact(A,	B,
								Ogre::Vector3(contact.getPositionWorldOnA().getX(), contact.getPositionWorldOnA().getY(), contact.getPositionWorldOnA().getZ()),
								Ogre::Vector3(contact.m_normalWorldOnB.getX(), contact.m_normalWorldOnB.getY(), contact.m_normalWorldOnB.getZ()));
							}
						}
					}

					
				}
/*
		if(obA->getUserPointer())
		{
			
		
		TemporaryPlayerObject* obj = (TemporaryPlayerObject*)obA->getUserPointer();
		
		Core::Game::getSceneManager()->GetScene()->getObject("Camera")->setPosition(Ogre::Vector3(obj->lastposition.x,obj->lastposition.y,obj->lastposition.z));
		//std::cout<<"Colliding\n";
		//Sleep(1000);

		}
		else if(obB->getUserPointer())
		{
		//	TemporaryPlayerObject* obj = (TemporaryPlayerObject*)obB->getUserPointer();
		//	Core::Game::getSceneManager()->GetScene()->getObject("Camera")->setPosition(Ogre::Vector3(obj->lastposition.x,obj->lastposition.y,obj->lastposition.z));
		//std::cout<<"Colliding\n";
			//	Sleep(1000);
		}
		else
		{
			std::cout<<"Colliding\n";
		}*/
	
		//std::cout<<"Colliding\n";
		
		//std::cout<<"Colliding\n";
 
		int numContacts = contactManifold->getNumContacts();
		
		for (int j=0;j<numContacts;j++)
		{ 
			
			btManifoldPoint& pt = contactManifold->getContactPoint(j);
			if (pt.getDistance()<0.01f)
			{
				
				const btVector3& ptA = pt.getPositionWorldOnA();
				const btVector3& ptB = pt.getPositionWorldOnB();
				const btVector3& normalOnB = pt.m_normalWorldOnB;
				if((!obB->getUserPointer())&&(!obA->getUserPointer()))
				{
					
				std::cout<<ptA.y()<<"\n";
				}
				//Sleep(1000);
			}
					
		}
		contactManifold->clearManifold();	
	}
	

}