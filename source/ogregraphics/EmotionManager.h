#pragma once
#include "stdafx.h"
#include "Emotion.h"
#include "Happy.h"
#include "Sad.h"
#include "Neutral.h"
#include "EnumSpace.h"

class EmotionManager
{
public:

	Emotion* FetchEmotion(EnumSpace::EmotionTypes DesiredEmotion);

	static EmotionManager* GetInstance();

private:
	std::map<EnumSpace::EmotionTypes, Emotion*> EmotionDB;
	std::map<EnumSpace::EmotionTypes, std::map<EnumSpace::MoodTypes, int>> EmotionMoodMultipliers;

	static EmotionManager* Instance;

	EmotionManager(void);
	~EmotionManager(void);
};

