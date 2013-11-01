#pragma once
#include "stdafx.h"
#include "Action.h"
#include "Sit.h"
#include "UseComputer.h"
#include "EmotionManager.h"

class Action;

class ActionManager
{
public:



	Action* FetchAction(EnumSpace::ActionTypes DesiredAction);

	void InitialiseAction(EnumSpace::ActionTypes ActionType, int* Multipliers);

	std::map<EnumSpace::EmotionTypes, int> GetEmotionMultipliers(EnumSpace::ActionTypes ActionType);

	void Init(void); //Initialise the manager class, call all individual action initialisation through here.

	static ActionManager* GetInstance();

private:
	std::map<EnumSpace::ActionTypes, Action*> ActionDB;
	std::map<EnumSpace::ActionTypes, std::map<EnumSpace::EmotionTypes, int>> ActionEmotionMultipliers;

	static ActionManager* Instance;

	ActionManager(void);
	~ActionManager(void);
};

