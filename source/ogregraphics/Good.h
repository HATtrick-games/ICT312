/**
 * \file	Good.h
 *
 * \brief	Declares the good class.
 */

#pragma once
#include "mood.h"

/**
 * \class	Good
 *
 * \brief	Good.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Good :
	public Mood
{
public:

	/**
	 * \fn	Good::Good(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	Good(void);

	/**
	 * \fn	Good::~Good(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~Good(void);
};

