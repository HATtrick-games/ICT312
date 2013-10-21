#pragma once

namespace Physics
{
	struct Contact
	{
		Contact() { }
		Contact(Ogre::Vector3 pos, Ogre::Vector3 norm, float pen)
		{
			position = pos;
			normal = norm;
			penetration = pen;
		}

		Ogre::Vector3 position;
		Ogre::Vector3 normal;
		float penetration;
	};
}