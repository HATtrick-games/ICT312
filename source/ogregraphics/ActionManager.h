/**
 * \file	ActionManager.h
 *
 * \brief	Declares the action manager class.
 */

#pragma once
#include "stdafx.h"
#include "Action.h"
#include "Sit.h"
#include "UseComputer.h"
#include "EmotionManager.h"

/**
 * \class	Action
 *
 * \brief	Action.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Action;

/**
 * \class	ActionManager
 *
 * \brief	Manager for actions.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class ActionManager
{
public:

	/**
	 * \fn	Action* ActionManager::FetchAction(EnumSpace::ActionTypes DesiredAction);
	 *
	 * \brief	Fetches an action.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \param	DesiredAction	The desired action.
	 *
	 * \return	null if it fails, else the action.
	 */

	Action* FetchAction(EnumSpace::ActionTypes DesiredAction);

	/**
	 * \fn	void ActionManager::InitialiseAction(EnumSpace::ActionTypes ActionType, int* Multipliers);
	 *
	 * \brief	Initialises the action.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \param	ActionType		   	Type of the action.
	 * \param [in,out]	Multipliers	If non-null, the multipliers.
	 */

	void InitialiseAction(EnumSpace::ActionTypes ActionType, int* Multipliers);

	/**
	 * \fn	std::map<EnumSpace::EmotionTypes, int> ActionManager::GetEmotionMultipliers(EnumSpace::ActionTypes ActionType);
	 *
	 * \brief	Gets emotion multipliers.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \param	ActionType	Type of the action.
	 *
	 * \return	The emotion multipliers.
	 */

	std::map<EnumSpace::EmotionTypes, int> GetEmotionMultipliers(EnumSpace::ActionTypes ActionType);

	/**
	 * \fn	void ActionManager::Init(void);
	 *
	 * \brief	Initialises this object.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	void Init(void); //Initialise the manager class, call all individual action initialisation through here.

	/**
	 * \fn	static ActionManager* ActionManager::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static ActionManager* GetInstance();

private:

	/**
	 * \brief	The action database.
	 */

	std::map<EnumSpace::ActionTypes, Action*> ActionDB;

	/**
	 * \brief	The action emotion multipliers.
	 */

	std::map<EnumSpace::ActionTypes, std::map<EnumSpace::EmotionTypes, int>> ActionEmotionMultipliers;

	/**
	 * \brief	The instance.
	 */

	static ActionManager* Instance;

	/**
	 * \fn	ActionManager::ActionManager(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	ActionManager(void);

	/**
	 * \fn	ActionManager::~ActionManager(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~ActionManager(void);
};

