/**
 * \file	Sad.h
 *
 * \brief	Declares the sad class.
 */

#pragma once
#include "emotion.h"

/**
 * \class	Sad
 *
 * \brief	Sad.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Sad :
	public Emotion
{
public:

	/**
	 * \fn	Sad::Sad(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	Sad(void);

	/**
	 * \fn	Sad::~Sad(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~Sad(void);
};

