
#include "MapNode.h"
#include "micropather.h"
#include "Vector3.h"

class NodeContainerSingleton
{
public:
	MapNode* FindNearestNode(Ogre::Vector3 Position);
	static NodeContainerSingleton* Instance();
protected:
private:
	MapNode* TempNode;
	float Distance;
	Ogre::Vector3 DisVec;
	void BuildMap();
	std::vector<MapNode*> Hallway;
	std::vector<MapNode*> ItRoom;
	std::vector<MapNode*> CommonRoom;

	NodeContainerSingleton()
	{
		BuildMap();
	}


};
