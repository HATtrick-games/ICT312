
#include "MapNode.h"
#include "micropather.h"


class NodeContainerSingleton
{
public:
	MapNode* FindNearestNode(Math::Vector3 Position);
	static NodeContainerSingleton* Instance();
protected:
private:
	MapNode* TempNode;
	float Distance;
	Math::Vector3 DisVec;
	std::vector<MapNode*> Hallway;
	std::vector<MapNode*> ItRoom;
	std::vector<MapNode*> CommonRoom;

	NodeContainerSingleton()
	{

	}


};
