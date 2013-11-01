#include "Vector3.h"

class TemporaryPlayerObject
{
public:
	Ogre::Vector3 lastposition;
	TemporaryPlayerObject()
	{
		lastposition.x = 0;
		lastposition.y = 0;
		lastposition.z = 0;

	}

	void SetLastPos(float posx, float posy, float posz);

protected:
private:



};