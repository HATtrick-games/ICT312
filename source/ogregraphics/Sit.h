/**
 * \file	Sit.h
 *
 * \brief	Declares the sit class.
 */

#pragma once
#include "stdafx.h"
#include "Action.h"

/**
 * \class	Sit
 *
 * \brief	Sit.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Sit : public Action
{
public:

	/**
	 * \fn	Sit::Sit(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	Sit(void);

	/**
	 * \fn	Sit::~Sit(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~Sit(void);

	/**
	 * \fn	bool Sit::Activate();
	 *
	 * \brief	Activates this object.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	bool Activate();
};

