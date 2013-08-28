#include "StdAfx.h"
#include "Vector3.h"

using namespace Math;

Vector3::~Vector3(void)
{
}

Vector3& Vector3::operator=( const Vector3& rhs )
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;

	return *this;
}

Vector3& Vector3::operator+=( const Vector3& rhs )
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	return *this;
}

Vector3& Vector3::operator*( const float rhs )
{
	x *= rhs;
	y *= rhs;
	z *= rhs;

	return *this;
}

Ogre::Vector3 Vector3::toOgre() const
{
	return Ogre::Vector3( x, y, z );
}