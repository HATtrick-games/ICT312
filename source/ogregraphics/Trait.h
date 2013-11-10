/**
 * \file	Trait.h
 *
 * \brief	Declares the trait class.
 */

#pragma once
#include  "stdafx.h"

/**
 * \class	Trait
 *
 * \brief	Trait.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Trait abstract
{
public:

	/**
	 * \fn	std::map<EnumSpace::NeedTypes, int> abstract::GetGoalModifier()
	 *
	 * \brief	Gets goal modifier.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	The goal modifier.
	 */

	std::map<EnumSpace::NeedTypes, int> GetGoalModifier() {return GoalModifier;}

protected:

	/**
	 * \brief	The goal modifier.
	 */

	std::map<EnumSpace::NeedTypes, int> GoalModifier;
};

