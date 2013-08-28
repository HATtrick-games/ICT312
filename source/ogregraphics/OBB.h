#pragma once

namespace Collision
{
	struct OBB
	{
		Ogre::Vector3 center;		// OBB center point
		Ogre::Vector3 local[3];		// local x, y, z axes
		Ogre::Vector3 extent;		// extents along each axis
	};
}