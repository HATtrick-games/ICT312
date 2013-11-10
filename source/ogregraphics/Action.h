#pragma once

#include "stdafx.h"
#include "EmotionManager.h"
#include "EnumSpace.h"

class Action abstract
{
public:

	/**
	 * \fn	EnumSpace::ActionTypes abstract::GetType()
	 *
	 * \brief	Gets the type.
	 *
	 * \author	Chaokel
	 * \date	10/11/2013
	 *
	 * \return	The type.
	 */

	EnumSpace::ActionTypes GetType() {return Type;};

	/**
	 * \fn	int abstract::GetThreshold()
	 *
	 * \brief	Gets the threshold.
	 *
	 * \author	Chaokel
	 * \date	10/11/2013
	 *
	 * \return	The threshold.
	 */

	int GetThreshold() {return Threshold;}

	/**
	 * \fn	std::string abstract::GetAffordanceName()
	 *
	 * \brief	Gets affordance name.
	 *
	 * \author	Chaokel
	 * \date	10/11/2013
	 *
	 * \return	The affordance name.
	 */

	std::string GetAffordanceName(){return AffordanceName;}

	/**
	 * \fn	virtual bool abstract::Activate() = 0;
	 *
	 * \brief	Activates this object.
	 *
	 * \author	Chaokel
	 * \date	10/11/2013
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	virtual bool Activate() = 0;
protected:

	/**
	 * \fn	void abstract::SetEmotionalMultipliers(int *MultiplierArray)
	 *
	 * \brief	Sets emotional multipliers.
	 *
	 * \author	Chaokel
	 * \date	10/11/2013
	 *
	 * \param [in,out]	MultiplierArray	If non-null, array of multipliers.
	 */

	void SetEmotionalMultipliers(int *MultiplierArray) {EmotionalMultipliers = new int[EnumSpace::EmotionTypes_Max]; EmotionalMultipliers = MultiplierArray;};

	/**
	 * \brief	The emotional multipliers.
	 */

	int* EmotionalMultipliers;

	/**
	 * \brief	Name of the affordance.
	 */

	std::string AffordanceName;

	/**
	 * \brief	The threshold.
	 */

	int Threshold; //affordance

	/**
	 * \brief	The type.
	 */

	EnumSpace::ActionTypes Type;
};