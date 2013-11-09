/**
 * \file	NodeContainerSingleton.h
 *
 * \brief	Declares the node container singleton class.
 */

#include "MapNode.h"
#include "micropather.h"
#include "Vector3.h"

/**
 * \class	NodeContainerSingleton
 *
 * \brief	Node container singleton this is the class that contains all the nodes that make up the world for pathing.
 *
 * \author	Arran Ford
 * \date	09/11/2013
 */

class NodeContainerSingleton
{
public:

	/**
	 * \fn	MapNode* NodeContainerSingleton::FindNearestNode(Ogre::Vector3 Position);
	 *
	 * \brief	Searches for the nearest node to a postion.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 *
	 * \param	Position	The position.
	 *
	 * \return	null if it fails, else the found node.
	 */

	MapNode* FindNearestNode(Ogre::Vector3 Position);

	/**
	 * \fn	static NodeContainerSingleton* NodeContainerSingleton::Instance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 *
	 * \return	null if it fails, else.
	 */

	static NodeContainerSingleton* Instance();
protected:
private:

	/**
	 * \brief	The temporary node.
	 */

	MapNode* TempNode;

	/**
	 * \brief	The distance.
	 */

	float Distance;

	/**
	 * \brief	The dis vector.
	 */

	Ogre::Vector3 DisVec;

	/**
	 * \fn	void NodeContainerSingleton::BuildMap();
	 *
	 * \brief	Builds the map.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 */

	void BuildMap();

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

	/**
	 * \fn	NodeContainerSingleton::NodeContainerSingleton()
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 */

	NodeContainerSingleton()
	{
		BuildMap();
	}


};
