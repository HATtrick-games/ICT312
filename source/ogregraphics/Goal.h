/**
 * \file	Goal.h
 *
 * \brief	Declares the goal class.
 */

#pragma once
#include "stdafx.h"
#include "Action.h"
#include "EnumSpace.h"
#include "ActionManager.h"

/**
 * \class	Goal
 *
 * \brief	Goal.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Goal abstract
{
public:

	/**
	 * \fn	virtual bool abstract::CheckForTrigger(std::map<EnumSpace::NeedTypes, int>) = 0;
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

	virtual bool CheckForTrigger(std::map<EnumSpace::NeedTypes, int>) = 0;

	/**
	 * \fn	Action* abstract::GetAction()
	 *
	 * \brief	Gets the action.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	null if it fails, else the action.
	 */

	Action* GetAction(){return GoalAction;}

	/**
	 * \fn	virtual int abstract::GetThreshold()
	 *
	 * \brief	Gets the threshold.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	The threshold.
	 */

	virtual int GetThreshold(){return (GoalAction->GetThreshold() - AffordanceThreshold);}

	/**
	 * \fn	virtual std::map<EnumSpace::NeedTypes, int>* abstract::ModifyNeeds() = 0;
	 *
	 * \brief	Gets the modify needs.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	null if it fails, else.
	 */

	virtual std::map<EnumSpace::NeedTypes, int>* ModifyNeeds() = 0;

	/**
	 * \fn	void abstract::DecayThreshold()
	 *
	 * \brief	Decay threshold.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	void DecayThreshold(){AffordanceThreshold++;}

	/**
	 * \fn	void abstract::ResetThreshhold()
	 *
	 * \brief	Resets the threshhold.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	void ResetThreshhold(){AffordanceThreshold = 0;}
protected:

	/**
	 * \brief	The affordance threshold.
	 */

	int AffordanceThreshold;

	/**
	 * \brief	The need outcomes.
	 */

	std::map<EnumSpace::NeedTypes, int> NeedOutcomes;

	/**
	 * \brief	The goal action.
	 */

	Action* GoalAction;

	//some kind of outcomes (how much needs fulfilled
};

