#pragma once
#include "stdafx.h"
#include "Goal.h"

class Work : public Goal
{
public:
	Work(void);
	~Work(void);

	bool CheckForTrigger(std::map<EnumSpace::NeedTypes, int>);

	//bool isCompleted(){};
};

