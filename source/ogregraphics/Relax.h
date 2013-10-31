#pragma once
#include "stdafx.h"
#include "Goal.h"


class Relax : public Goal
{
public:
	Relax(void);
	~Relax(void);

	bool CheckForTrigger(std::map<EnumSpace::NeedTypes, int>);

	//bool isCompleted(){};
};

