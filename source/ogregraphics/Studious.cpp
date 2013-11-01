#include "StdAfx.h"
#include "Studious.h"


Studious::Studious(void)
{
	GoalModifier[EnumSpace::enumFun] = 0;
	GoalModifier[EnumSpace::enumGrades] = 10;
	GoalModifier[EnumSpace::enumComfort] = -5;
}


Studious::~Studious(void)
{
}
