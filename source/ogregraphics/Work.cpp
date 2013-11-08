#include "StdAfx.h"
#include "Work.h"


Work::Work(void)
{
	//std::map<std::string, int> AffordanceThreshholds;
	//std::map<EnumSpace::NeedTypes, int> NeedOutcomes;
	
	GoalAction = ActionManager::GetInstance()->FetchAction(EnumSpace::enumUseComputer);

	NeedOutcomes[EnumSpace::enumFun] = 0;
	NeedOutcomes[EnumSpace::enumComfort] = 0;
	NeedOutcomes[EnumSpace::enumGrades] = 3;
}


Work::~Work(void)
{
}

bool Work::CheckForTrigger(std::map<EnumSpace::NeedTypes, int>)
{
	return true;
}

std::map<EnumSpace::NeedTypes, int>* Work::ModifyNeeds()
{
	return &NeedOutcomes;
}