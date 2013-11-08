#include "StdAfx.h"
#include "Relax.h"


Relax::Relax(void)
{
	GoalAction = ActionManager::GetInstance()->FetchAction(EnumSpace::enumSit);

	NeedOutcomes[EnumSpace::enumFun] = 1;
	NeedOutcomes[EnumSpace::enumComfort] = 2;
	NeedOutcomes[EnumSpace::enumGrades] = 0;
}


Relax::~Relax(void)
{
}

bool Relax::CheckForTrigger(std::map<EnumSpace::NeedTypes, int>)
{
	return true;
}

std::map<EnumSpace::NeedTypes, int>* Relax::ModifyNeeds()
{
	return &NeedOutcomes;
}