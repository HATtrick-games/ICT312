#include "stdafx.h"
#include "MapNode.h"

MapNode::MapNode(int ident, Math::Vector3 location)
{
	LocationVec = location;
	id = ident;

}

MapNode::MapNode(int ident, Math::Vector3 location, std::vector<int> links)
{
	LocationVec = location;
	id = ident;
	PartnerIds = links;
}

std::vector<MapNode*> *MapNode::GetPartners()
{
	return &Partners;
}
MapNode* MapNode::GetPartnerById(int i)
{
	return Partners[i];
}

int MapNode::GetId()
{
	return id;
}

Math::Vector3 MapNode::GetLocation()
{
	return LocationVec;
}

