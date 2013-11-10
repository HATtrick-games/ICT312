/**
 * \file	Mood.h
 *
 * \brief	Declares the mood class.
 */

#pragma once
#include "stdafx.h"
#include "EnumSpace.h"

/**
 * \class	Mood
 *
 * \brief	Mood.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Mood abstract
{
public:

	/**
	 * \fn	EnumSpace::MoodTypes abstract::GetType()
	 *
	 * \brief	Gets the type.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	The type.
	 */

	EnumSpace::MoodTypes GetType(){return Type;};

protected:

	/**
	 * \brief	The emotional multipliers.
	 */

	int* EmotionalMultipliers;

	/**
	 * \brief	The type.
	 */

	EnumSpace::MoodTypes Type;
};

