#include "stdafx.h"
#include "WorldMap.h"
#include "NodeContainerSingleton.h"

WorldMap::WorldMap()
{
	pather = new micropather::MicroPather(this, 20);

}

void WorldMap::PrintStateInfo(void * state)
{
	cout<<"print";
}

float WorldMap::LeastCostEstimate(void *nodeStart, void *nodeEnd)
{
	MapNode *tempnode = (MapNode*)nodeStart;
	MapNode *tempnode2 = (MapNode*)nodeEnd;

	
	DisVec.x = tempnode->GetLocation().x - tempnode2->GetLocation().x;
	DisVec.y = tempnode->GetLocation().y - tempnode2->GetLocation().y;
	DisVec.z = tempnode->GetLocation().z - tempnode2->GetLocation().z;
	Distance = ((DisVec.x * DisVec.x) + (DisVec.y * DisVec.y) + (DisVec.z * DisVec.z));
	return Distance;
}

void WorldMap::AdjacentCost(void *node, std::vector<micropather::StateCost> *neighbors)
{
	MapNode *adjacent = (MapNode*)node;

	for(int i = 0; i < adjacent->GetPartners()->size(); i++)
	{
		//cout<<adjacent->GetPartnerById(i)->GetLocation().x<<"\n";
		micropather::StateCost nodeCost = {(void*)adjacent->GetPartnerById(i), LeastCostEstimate(node, (void*)adjacent->GetPartnerById(i))};
		neighbors->push_back(nodeCost);
	}
	

}




bool WorldMap::FindPath(Ogre::Vector3 pos, Ogre::Vector3 pos2)
{
	int result;
	float totalCost;


	result = pather->Solve((void*)NodeContainerSingleton::Instance()->FindNearestNode(pos), (void*)NodeContainerSingleton::Instance()->FindNearestNode(pos2),&path, &totalCost);

	cout<<"\nPather returned: "<<result<<"\n";

	return(result);
}




