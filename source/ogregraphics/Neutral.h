/**
 * \file	Neutral.h
 *
 * \brief	Declares the neutral class.
 */

#pragma once
#include "emotion.h"

/**
 * \class	Neutral
 *
 * \brief	Neutral.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Neutral :
	public Emotion
{
public:

	/**
	 * \fn	Neutral::Neutral(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	Neutral(void);

	/**
	 * \fn	Neutral::~Neutral(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~Neutral(void);
};

