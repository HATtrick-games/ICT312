/**
 * \file	Happy.h
 *
 * \brief	Declares the happy class.
 */

#pragma once
#include "emotion.h"

/**
 * \class	Happy
 *
 * \brief	Happy.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Happy :
	public Emotion
{
public:

	/**
	 * \fn	Happy::Happy(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	Happy(void);

	/**
	 * \fn	Happy::~Happy(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~Happy(void);
};

