#pragma once
#include "stdafx.h"
#include "Goal.h"

class Work : public Goal
{
public:
	Work(void);
	~Work(void);

	bool CheckForTrigger(std::map<EnumSpace::NeedTypes, int>);

	std::map<EnumSpace::NeedTypes, int>* ModifyNeeds();
	//bool isCompleted(){};
};

