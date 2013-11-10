/**
 * \file	MoveItem.h
 *
 * \brief	Declares the move item class.
 */

#pragma once
#include "stdafx.h"
#include "Action.h"

/**
 * \class	MoveItem
 *
 * \brief	Move item.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class MoveItem : public Action
{
public:

	/**
	 * \fn	MoveItem::MoveItem(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	MoveItem(void);

	/**
	 * \fn	MoveItem::~MoveItem(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~MoveItem(void);

	//void Activate(int i);
private:

};

