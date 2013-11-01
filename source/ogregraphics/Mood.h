#pragma once
#include "stdafx.h"
#include "EnumSpace.h"

class Mood abstract
{
public:
	
	EnumSpace::MoodTypes GetType(){return Type;};

protected:
	int* EmotionalMultipliers;

	EnumSpace::MoodTypes Type;
};

