#pragma once
#include "stdafx.h"
#include "Action.h"
#include "EnumSpace.h"

class Goal abstract
{
public:

	virtual bool CheckForTrigger(std::map<EnumSpace::NeedTypes, int>) = 0;


	Action* GetAction(){return GoalAction;}
	
	virtual int GetThreshold(){return (GoalAction->GetThreshold() - AffordanceThreshold);}

	void DecayThreshold(){AffordanceThreshold++;}
	void ResetThreshhold(){AffordanceThreshold = 0;}
protected:
	int AffordanceThreshold;
	std::map<EnumSpace::NeedTypes, int> NeedOutcomes;
	Action* GoalAction;

	//some kind of outcomes (how much needs fulfilled
};

