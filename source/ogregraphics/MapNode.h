/**
 * \file	MapNode.h
 *
 * \brief	Declares the map node class.
 */

#include "Vector3.h"
#pragma once

/**
 * \class	MapNode
 *
 * \brief	This class is a node that can be moved to in the path finding.
 *
 * \author	Arran Ford
 * \date	09/11/2013
 */

class MapNode
{
public:

	/**
	 * \fn	MapNode::MapNode(int ident, Ogre::Vector3 location);
	 *
	 * \brief	Constructor that takes in the location and identifier of the node.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 *
	 * \param	ident   	The identifier.
	 * \param	location	The location.
	 */

	MapNode(int ident, Ogre::Vector3 location);

	/**
	 * \fn	MapNode::MapNode(int ident, Ogre::Vector3 location, std::vector<int> links);
	 *
	 * \brief	Constructor takes in the identifier, position and the partners of this node.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 *
	 * \param	ident   	The identifier.
	 * \param	location	The location.
	 * \param	links   	The links.
	 */

	MapNode(int ident, Ogre::Vector3 location, std::vector<int> links);

	/**
	 * \fn	int MapNode::GetId();
	 *
	 * \brief	Gets the identifier.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 *
	 * \return	The identifier.
	 */

	int GetId();

	/**
	 * \fn	Ogre::Vector3 MapNode::GetLocation();
	 *
	 * \brief	Gets the location.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 *
	 * \return	The location.
	 */

	Ogre::Vector3 GetLocation();

	/**
	 * \fn	std::vector<MapNode*> MapNode::*GetPartners();
	 *
	 * \brief	Gets the partners.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 *
	 * \return	null if it fails, else the partners.
	 */

	std::vector<MapNode*> *GetPartners();

	/**
	 * \fn	MapNode* MapNode::GetPartnerById(int i);
	 *
	 * \brief	Gets partner by identifier.
	 *
	 * \author	Arran Ford
	 * \date	09/11/2013
	 *
	 * \param	i	Zero-based index of the.
	 *
	 * \return	null if it fails, else the partner by identifier.
	 */

	MapNode* GetPartnerById(int i);

	/**
	 * \brief	A Vector containing pointers to this nodes partners.
	 */

	std::vector<MapNode*> Partners;
	
protected:
private:

	/**
	 * \brief	The location vector.
	 */

	Ogre::Vector3 LocationVec;

	/**
	 * \brief	The identifier.
	 */

	int id;

	/**
	 * \brief	List of identifiers for the partners.
	 */

	std::vector<int> PartnerIds;



};