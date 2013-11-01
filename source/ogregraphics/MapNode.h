#include "Vector3.h"
#pragma once
class MapNode
{
public:
	MapNode(int ident, Ogre::Vector3 location);
	MapNode(int ident, Ogre::Vector3 location, std::vector<int> links);
	int GetId();
	Ogre::Vector3 GetLocation();
	std::vector<MapNode*> *GetPartners();
	MapNode* GetPartnerById(int i);
	std::vector<MapNode*> Partners;
	
protected:
private:
	Ogre::Vector3 LocationVec;
	int id;
	std::vector<int> PartnerIds;



};