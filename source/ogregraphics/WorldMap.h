/**
 * \file	WorldMap.h
 *
 * \brief	Declares the world map class.
 */

#include "micropather.h"
#include "MapNode.h"
#include "Vector3.h"

/**
 * \class	WorldMap
 *
 * \brief	World map a class that implement the grinning lizard A*.
 *
 * \author	Arran Ford
 * \date	09/11/2013
 */

class WorldMap :public micropather::Graph
{
public:

	/**
	 * \fn	WorldMap::WorldMap();
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 */

	WorldMap();

	/**
	 * \fn	virtual float WorldMap::LeastCostEstimate(void *nodeStart, void* nodeEnd);
	 *
	 * \brief	Least cost estimate.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 *
	 * \param [in,out]	nodeStart	If non-null, the node start.
	 * \param [in,out]	nodeEnd  	If non-null, the node end.
	 *
	 * \return	.
	 */

	virtual float LeastCostEstimate(void *nodeStart, void* nodeEnd);

	/**
	 * \fn	virtual void WorldMap::AdjacentCost(void *node,
	 * 		std::vector<micropather::StateCost> *neigbors);
	 *
	 * \brief	Adjacent cost.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 *
	 * \param [in,out]	node		If non-null, the node.
	 * \param [in,out]	neigbors	If non-null, the neigbors.
	 */

	virtual void AdjacentCost(void *node, std::vector<micropather::StateCost> *neigbors);

	/**
	 * \fn	virtual void WorldMap::PrintStateInfo(void* state);
	 *
	 * \brief	Print state information.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 *
	 * \param [in,out]	state	If non-null, the state.
	 */

	virtual void PrintStateInfo(void* state);

	/**
	 * \fn	bool WorldMap::FindPath(Ogre::Vector3 currentpos, Ogre::Vector3 destination);
	 *
	 * \brief	Searches for the best path through the map.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 *
	 * \param	currentpos 	The currentpos.
	 * \param	destination	Destination for the.
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	bool FindPath(Ogre::Vector3 currentpos, Ogre::Vector3 destination);

	/**
	 * \brief	The list of nodes that make up the path.
	 */

	std::vector<void*> path;
protected:
private:

	/**
	 * \brief	The temporary node.
	 */

	MapNode* TempNode;

	/**
	 * \brief	Grinning lizard class used to calculate path
	 */

	micropather::MicroPather* pather;

	/**
	 * \brief	The distance.
	 */

	float Distance;

	/**
	 * \brief	The dis vector.
	 */

	Ogre::Vector3 DisVec;

	/**
	 * \brief	The hallway.
	 */

	std::vector<MapNode*> Hallway;

	/**
	 * \brief	The iterator room.
	 */

	std::vector<MapNode*> ItRoom;

	/**
	 * \brief	The common room.
	 */

	std::vector<MapNode*> CommonRoom;
	

	


};