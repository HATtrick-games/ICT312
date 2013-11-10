/**
 * \file	UseComputer.h
 *
 * \brief	Declares the use computer class.
 */

#pragma once
#include "Action.h"
#include "stdafx.h"

/**
 * \class	UseComputer
 *
 * \brief	Use computer.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class UseComputer : public Action
{
public:

	/**
	 * \fn	UseComputer::UseComputer(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	UseComputer(void);

	/**
	 * \fn	UseComputer::~UseComputer(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~UseComputer(void);

	/**
	 * \fn	bool UseComputer::Activate();
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

