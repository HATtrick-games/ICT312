#pragma once

namespace Math
{
	struct Vector3
	{
		Vector3(void) { x = 0; y = 0; z = 0; }
		Vector3( float x, float y, float z ) { x = x; y = y; z = z; }
		~Vector3(void);

		Vector3& operator=( const Vector3& rhs );
		Vector3& operator+=( const Vector3& rhs );
		Vector3& operator*( const float rhs );

		Ogre::Vector3 toOgre() const;

		float x;
		float y;
		float z;
	};
}