#pragma once

#include "stdafx.h"
#include "EmotionManager.h"
#include "EnumSpace.h"

class Action abstract
{
public:

	EnumSpace::ActionTypes GetType() {return Type;};

	int GetThreshold() {return Threshold;}

	virtual void Activate() = 0;
protected:

	void SetEmotionalMultipliers(int *MultiplierArray) {EmotionalMultipliers = new int[EnumSpace::EmotionTypes_Max]; EmotionalMultipliers = MultiplierArray;};

	int* EmotionalMultipliers;

	int Threshold; //affordance
	EnumSpace::ActionTypes Type;
};