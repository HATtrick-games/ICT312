#pragma once

#include "stdafx.h"
#include "EmotionManager.h"
#include "EnumSpace.h"

class Action abstract
{
public:

	EnumSpace::ActionTypes GetType() {return Type;};

	int GetThreshold() {return Threshold;}

	std::string GetAffordanceName(){return AffordanceName;}

	virtual bool Activate() = 0;
protected:

	void SetEmotionalMultipliers(int *MultiplierArray) {EmotionalMultipliers = new int[EnumSpace::EmotionTypes_Max]; EmotionalMultipliers = MultiplierArray;};

	int* EmotionalMultipliers;

	std::string AffordanceName;
	int Threshold; //affordance
	EnumSpace::ActionTypes Type;
};