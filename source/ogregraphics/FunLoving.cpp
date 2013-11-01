#include "StdAfx.h"
#include "FunLoving.h"


FunLoving::FunLoving(void)
{
	GoalModifier[EnumSpace::enumFun] = 10;
	GoalModifier[EnumSpace::enumGrades] = -5;
	GoalModifier[EnumSpace::enumComfort] = 0;
}


FunLoving::~FunLoving(void)
{
}
