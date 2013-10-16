#include "Vector3.h"
#pragma once
class MapNode
{
public:
	MapNode(int ident, Math::Vector3 location);
	MapNode(int ident, Math::Vector3 location, std::vector<int> links);
	int GetId();
	Math::Vector3 GetLocation();
	std::vector<MapNode*> *GetPartners();
	MapNode* GetPartnerById(int i);
	
protected:
private:
	Math::Vector3 LocationVec;
	int id;
	std::vector<int> PartnerIds;
	std::vector<MapNode*> Partners;


};