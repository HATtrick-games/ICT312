/**
 * \file	Relax.h
 *
 * \brief	Declares the relax class.
 */

#pragma once
#include "stdafx.h"
#include "Goal.h"

/**
 * \class	Relax
 *
 * \brief	Relax.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Relax : public Goal
{
public:

	/**
	 * \fn	Relax::Relax(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	Relax(void);

	/**
	 * \fn	Relax::~Relax(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~Relax(void);

	/**
	 * \fn	bool Relax::CheckForTrigger(std::map<EnumSpace::NeedTypes, int>);
	 *
	 * \brief	Check for trigger.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \param	parameter1	The first parameter.
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	bool CheckForTrigger(std::map<EnumSpace::NeedTypes, int>);

	/**
	 * \fn	std::map<EnumSpace::NeedTypes, int>* Relax::ModifyNeeds();
	 *
	 * \brief	Gets the modify needs.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	null if it fails, else.
	 */

	std::map<EnumSpace::NeedTypes, int>* ModifyNeeds();
	//bool isCompleted(){};
};

