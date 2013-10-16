#include "micropather.h"
#include "MapNode.h"


class WorldMap :public micropather::Graph
{
public:
	WorldMap();
	virtual float LeastCostEstimate(void *nodeStart, void* nodeEnd);
	virtual void AdjacentCost(void *node, std::vector<micropather::StateCost> *neigbors);
	virtual void PrintStateInfo(void* state);
	bool FindPath(Math::Vector3 currentpos, Math::Vector3 destination);
	
protected:
private:
	MapNode* TempNode;
	micropather::MicroPather* pather;
	float Distance;
	Math::Vector3 DisVec;
	std::vector<MapNode*> Hallway;
	std::vector<MapNode*> ItRoom;
	std::vector<MapNode*> CommonRoom;
	std::vector<void*> path;

	//will contain a map of nodes linking numbers or labels with nodes
	// each node will have its own structure that holds all the labels of nodes it can access
	// then the adjacent cost function will loop through these labels and push each adjacent node onto the neighbors vector
	// It will get the cost by calculating the distance between two nodes
	// each node needs a position vector only x and y is nessaccary


};