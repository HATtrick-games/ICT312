#include "StdAfx.h"
#include "Relax.h"


Relax::Relax(void)
{
	GoalAction = ActionManager::GetInstance()->FetchAction(EnumSpace::enumSit);
}


Relax::~Relax(void)
{
}

bool Relax::CheckForTrigger(std::map<EnumSpace::NeedTypes, int>)
{
	return true;
}