#include "StdAfx.h"
#include "ActionManager.h"

ActionManager* ActionManager::Instance = NULL;

ActionManager::ActionManager(void)
{
	Init();
}


ActionManager::~ActionManager(void)
{
}

Action* ActionManager::FetchAction(EnumSpace::ActionTypes DesiredAction)
{
	if(ActionDB[DesiredAction] == NULL)
	{
		if(DesiredAction== EnumSpace::enumMoveItem)
		{
			//ActionDB[DesiredAction] = new MoveItem;
		}
		else if(DesiredAction == EnumSpace::enumUseItem)
		{
			//ActionDB[DesiredAction] = new Bad;	
		}
		return ActionDB[DesiredAction];
	}
	else
	{
		return ActionDB[DesiredAction];
	}
}

void ActionManager::InitialiseAction(EnumSpace::ActionTypes ActionType, int Multipliers[])
{
	std::map<EnumSpace::EmotionTypes, int> TempMap;
	int NumberOfEmotions = EnumSpace::EmotionTypes::EmotionTypes_Max;
	for(int i =0; i <= NumberOfEmotions; i++)
	{
		TempMap[(EnumSpace::EmotionTypes) i] = Multipliers[i];
	}

	ActionEmotionMultipliers[ActionType] = TempMap;

}

void ActionManager::Init(void)
{
	int Multipliers[] = {7, 1, 2};
	InitialiseAction(EnumSpace::enumMoveItem, Multipliers);
}

ActionManager* ActionManager::GetInstance()
{
	if(Instance == NULL)
	{
		Instance = new ActionManager();
	}
	return Instance;
}

std::map<EnumSpace::EmotionTypes, int> ActionManager::GetEmotionMultipliers(EnumSpace::ActionTypes DesiredAction)
{
	return ActionEmotionMultipliers[DesiredAction];
}