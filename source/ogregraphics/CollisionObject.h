/**
 * \file	CollisionObject.h
 *
 * \brief	Declares the collision object class.
 */
#pragma once
#include "CollisionWorldSingleton.h"
#include "CollisionWorldSingleton.h"
#include "OgreBulletCollisionsPreRequisites.h"
#include "OgreBulletCollisionsWorld.h"

#include "OgreBulletCollisions.h"

#include "OgreBulletCollisionsObject.h"
#include "Debug/OgreBulletCollisionsDebugShape.h"

#include "OgreBulletCollisionsObjectState.h"
#include "OgreBulletCollisionsShape.h"
#include "Vector3.h"
#include "IObject.h"

/**
 * \class	CollisionObject
 *
 * \brief	Collision object.
 *
 * \author	Arran Ford
 * \date	16/09/2013
 */

class CollisionObject
{
public:

	/**
	 * \brief	The convex shape.
	 */

	btConvexHullShape* convexShape;
	/**
	 * \fn	void CollisionObject::CollisionObject();
	 *
	 * \brief	Default constructer
	 *
	 * \author	Arran Ford
	 * \date	16/09/2013
	 *
	 */
	CollisionObject();
	/**
	 * \fn	void CollisionObject::AddMeshShape(Ogre::Entity* Ent);
	 *
	 * \brief	Adds a mesh shape based off the Ogre mesh
	 *
	 * \author	Arran Ford
	 * \date	20/10/2013
	 *
	 * \param	Radius	The radius.
	 */
	void AddMeshShape(Ogre::Entity* Ent);

	/**
	 * \fn	void CollisionObject::AddMeshShapeWithOffset(Ogre::Entity* Ent, Ogre::Vector3 Offset);
	 *
	 * \brief	Adds a mesh shape based off the Ogre mesh with an offset to correctly position center of gravity
	 *
	 * \author	Arran Ford
	 * \date	20/10/2013
	 *
	 * \param	ent the Ogre entity
	 * \param	Offset the offset vector
	 */
	void AddMeshShapeWithOffset(Ogre::Entity* Ent, Ogre::Vector3 Offset);

	/**
	 * \fn	void CollisionObject::AddBoxShape(float xLength, float yLength, float zLength);
	 *
	 * \brief	Adds a box shape.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * \param	xLength	The length.
	 * \param	yLength	The length.
	 * \param	zLength	The length.
	 */

	void AddBoxShape(float xLength, float yLength, float zLength);

	/**
	 * \fn	void CollisionObject::AddSphereShape(float Radius);
	 *
	 * \brief	Adds a sphere shape.
	 *
	 * \author	Arran Ford
	 * \date	16/09/2013
	 *
	 * \param	Radius	The radius.
	 */

	void AddSphereShape(float Radius);

	/**
	 * \fn	void CollisionObject::SetPosition(float xpox, float ypoz, float zpos);
	 *
	 * \brief	Sets the object position via 3 floats
	 *
	 * \author	Arran Ford
	 * \date	16/09/2013
	 *
	 * \param	xpos Position on the x axis.
	 * \param	ypos Position on the y axis
	 * \param	zpos Position on the z axis
	 */
	void SetPosition(float xpos, float ypos, float zpos);

	/**
	 * \fn	void CollisionObject::SetPosition(Ogre::Vector3 vecpos);
	 *
	 * \brief	Sets the object position via an Ogre Vector3
	 *
	 * \author	Arran Ford
	 * \date	16/09/2013
	 *
	 * \param	vecpos the Ogre Vector that determines new object location
	 */

	void SetPosition(Ogre::Vector3 vecpos);

	/**
	 * \fn	void CollisionObject::MoveObject(Ogre::Vector3 vec);
	 *
	 * \brief	Move object.
	 *
	 * \author	Arran Ford
	 * \date	16/09/2013
	 *
	 * \param	vec	The vector.
	 */

	void AddSphereShape(Ogre::Entity* Ent);

	/**
	 * \fn	void CollisionObject::MoveObject(Ogre::Vector3 vec);
	 *
	 * \brief	Move object.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * \param	vec	The vector.
	 */

	void MoveObject(Ogre::Vector3 vec);

	/**
	 * \fn	void CollisionObject::SetObjectOrientation(float x, float y, float z, float Degrees);
	 *
	 * \brief	Sets the objects orientation
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * \param	Degrees The amount in degrees to rotate around the defined axis.
	 * \param	x the x portion of the rotation axis
	 * \param	y the y portion of the rotation axis			
	 * \param	z the z portion of the rotation axis
	 * 		 
	 *
	 */

	void SetObjectOrientation(float x, float y, float z, float Degrees);

	/**
	 * \fn	void CollisionObject::SetObjectOrientation(Ogre::Quaternion quat);
	 *
	 * \brief	Set the object orientation by quaternion
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * \param	quat The Quaternion defining the objects new orientation
	 * 		 
	 */

	void SetObjectOrientation(Ogre::Quaternion quat);

	/**
	 * \fn	void CollisionObject::SetUserPointer(void* obj);
	 *
	 * \brief	Set the objects void pointer.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * \param	obj The object the void pointer will point to.
	 * 		 
	 */

	void SetUserPointer(void* obj);

	/**
	 * \fn	void CollisionObject::SetScale(float xs, float ys, float zs);
	 *
	 * \brief	Sets the scale of the object
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * \param	xs the scale along x axis
	 * \param	ys the scale along y axis
	 * \param	zs the scale along z axis
	 * 	
	 * 		 	 	 	 	 	 	 	 
	 */

	void SetScale(float xs, float ys, float zs);

	/**
	 * \fn	Ogre::Vector3 CollisionObject::Ogre::Vector3 GetObjectPosition();
	 *
	 * \brief	return the position vector of the object
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * 		 	 	 	 	 	 	 	 
	 */

	Ogre::Vector3 GetObjectPosition();

	void AddBoxMesh(Ogre::Entity* Ent);
protected:

private:

	/**
	 * \brief	The bullet triangle mesh object
	 */

	btScaledBvhTriangleMeshShape* obj;

	/**
	 * \brief	The bullet collision object that is stored in the collision world
	 */

	btCollisionObject* BulletCollisionObject;

	/**
	 * \brief	true if shape added.
	 */

	bool ShapeAdded;
};