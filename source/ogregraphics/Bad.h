/**
 * \file	Bad.h
 *
 * \brief	Declares the bad class.
 */

#pragma once
#include "mood.h"

/**
 * \class	Bad
 *
 * \brief	Bad.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Bad :
	public Mood
{
public:

	/**
	 * \fn	Bad::Bad(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	Bad(void);

	/**
	 * \fn	Bad::~Bad(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~Bad(void);
};

