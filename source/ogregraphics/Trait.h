#pragma once
#include  "stdafx.h"

class Trait abstract
{
public:

	std::map<EnumSpace::NeedTypes, int> GetGoalModifier() {return GoalModifier;}

protected:
	std::map<EnumSpace::NeedTypes, int> GoalModifier;
};

