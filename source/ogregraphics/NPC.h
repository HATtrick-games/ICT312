/**
 * \file	NPC.h
 *
 * \brief	Declares the npc class.
 */

#pragma once
#include "stdafx.h"
#include "EmotionManager.h"
#include "ActionManager.h"
#include "MoodManager.h"
#include "EnumSpace.h"
#include "Goal.h"
#include "Relax.h"
#include "Work.h"
#include "Trait.h"
#include "FunLoving.h"
#include "Studious.h"
#include "EasyGoing.h"
#include "ItemStore.h"
#include "IObject.h"

/**
 * \class	NPC
 *
 * \brief	Npc.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class NPC 
{
public:

	/**
	 * \fn	NPC::NPC(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	NPC(void);

	/**
	 * \fn	NPC::NPC(Objects::IObject* Obj)
	 *
	 * \brief	Constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \param [in,out]	Obj	If non-null, the object.
	 */

	NPC(Objects::IObject* Obj){myObj = Obj; Initialise();}

	/**
	 * \fn	NPC::~NPC(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~NPC(void);

	/**
	 * \fn	bool NPC::EmotionCheck();
	 *
	 * \brief	Determines if we can emotion check.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	bool EmotionCheck();

	/**
	 * \fn	bool NPC::DetermineGoal();
	 *
	 * \brief	Determines if we can determine goal.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	bool DetermineGoal();

	/**
	 * \fn	void NPC::CheckGoal();
	 *
	 * \brief	Check goal.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	void CheckGoal();

	/**
	 * \fn	void NPC::Update();
	 *
	 * \brief	Updates this object.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	void Update();

	/**
	 * \fn	void NPC::Initialise();
	 *
	 * \brief	Initialises this object.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	void Initialise();

	/**
	 * \fn	bool NPC::runCurrentState();
	 *
	 * \brief	Executes the current state operation.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	true if it succeeds, false if it fails.
	 */

	bool runCurrentState();

	/**
	 * \fn	void NPC::ProgressMood(EnumSpace::EmotionTypes S);
	 *
	 * \brief	Progress mood.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \param	S	The EnumSpace::EmotionTypes to process.
	 */

	void ProgressMood(EnumSpace::EmotionTypes S);

	/**
	 * \fn	void NPC::Clicked(std::string click);
	 *
	 * \brief	Clickeds the given click.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \param	click	The click.
	 */

	void Clicked(std::string click);

protected:

	/**
	 * \brief	The current action.
	 */

	Action* CurrentAction;

	/**
	 * \brief	The current emotion.
	 */

	Emotion* CurrentEmotion;

	/**
	 * \brief	The current mood.
	 */

	Mood* CurrentMood;

	/**
	 * \brief	The current goal.
	 */

	Goal* CurrentGoal;

	/**
	 * \brief	The current state.
	 */

	EnumSpace::NPCState CurrentState;

	/**
	 * \brief	my trait.
	 */

	Trait* myTrait;

	/**
	 * \brief	my object.
	 */

	Objects::IObject * myObj;

	/**
	 * \brief	The object pointer.
	 */

	Objects::IObject* ObjectPointer;

	/**
	 * \property	std::map <EnumSpace::NeedTypes, int> CurrentNeeds
	 *
	 * \brief	Gets the current needs.
	 *
	 * \return	The current needs.
	 */

	std::map <EnumSpace::NeedTypes, int> CurrentNeeds;

	/**
	 * \brief	The mood progress.
	 */

	std::map<EnumSpace::MoodTypes, int> MoodProgress;
};

