/**
 * \file	CollisionObject.h
 *
 * \brief	Declares the collision object class.
 */

#include "CollisionWorldSingleton.h"
#include "CollisionWorldSingleton.h"
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
	CollisionObject();
	void AddBoxShape(float xLength, float yLength, float zLength);//creates a collision object with a box shape

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

	void AddSphereShape(float Radius);//creates a collision object with a sphere shape
	void SetPosition(float xpox, float ypoz, float zpos);//sets position by 3 floats
	void SetPosition(Math::Vector3 vecpos);//sets position by vector

	/**
	 * \fn	void CollisionObject::MoveObject(Math::Vector3 vec);
	 *
	 * \brief	Move object.
	 *
	 * \author	Arran Ford
	 * \date	16/09/2013
	 *
	 * \param	vec	The vector.
	 */

	void MoveObject(Math::Vector3 vec);//moves position by passed vector
	void SetObjectOrientation(Math::Vector3 axis, float Degrees);
	void SetUserPointer(void* obj);
	Math::Vector3 GetObjectPosition();
	
protected:
private:
	btCollisionObject* BulletCollisionObject;
	bool ShapeAdded;
};