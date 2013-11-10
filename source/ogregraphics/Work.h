/**
 * \file	Work.h
 *
 * \brief	Declares the work class.
 */

#pragma once
#include "stdafx.h"
#include "Goal.h"

/**
 * \class	Work
 *
 * \brief	Work.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Work : public Goal
{
public:

	/**
	 * \fn	Work::Work(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	Work(void);

	/**
	 * \fn	Work::~Work(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~Work(void);

	/**
	 * \fn	bool Work::CheckForTrigger(std::map<EnumSpace::NeedTypes, int>);
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
	 * \fn	std::map<EnumSpace::NeedTypes, int>* Work::ModifyNeeds();
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

