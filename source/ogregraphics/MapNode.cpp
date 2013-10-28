#include "stdafx.h"
#include "MapNode.h"
#include "Vector3.h"

MapNode::MapNode(int ident, Ogre::Vector3 location)
{
	LocationVec = location;
	id = ident;

}

MapNode::MapNode(int ident, Ogre::Vector3 location, std::vector<int> links)
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

Ogre::Vector3 MapNode::GetLocation()
{
	return LocationVec;
}

