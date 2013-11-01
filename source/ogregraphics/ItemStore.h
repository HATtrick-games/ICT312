#pragma once
#include "Vector3.h"
#include <stdlib.h>
#include "IObject.h"
#include <string.h>

class ItemStore
{
public:
	Objects::IObject* CheckVector(std::vector<Objects::IObject*> vec, Ogre::Vector3 pos, std::string affordance, int min );
	void AddObject(Objects::IObject* obj);
	Objects::IObject* GetObject(Ogre::Vector3 pos,std::string affordance, int min);
	static ItemStore* Instance();
protected:
private:
	

	std::vector<Objects::IObject*> Hallway;
	std::vector<Objects::IObject*> ItRoom;
	std::vector<Objects::IObject*> CommonRoom;
	std::vector<Objects::IObject*> Other;

	ItemStore()
	{
		
	}


};
