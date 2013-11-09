#include "StdAfx.h"
#include "MoodManager.h"

MoodManager* MoodManager::Instance = NULL;

MoodManager::MoodManager(void)
{
	Init();
}


MoodManager::~MoodManager(void)
{
}

Mood* MoodManager::FetchMood(EnumSpace::MoodTypes DesiredEmotion)
{
	//check to see if the desired emotion exists
	if(MoodDB[DesiredEmotion] == NULL)
	{
		if(DesiredEmotion == EnumSpace::enumGood)
		{
			MoodDB[DesiredEmotion] = new Good;
		}
		else if(DesiredEmotion == EnumSpace::enumBad)
		{
			MoodDB[DesiredEmotion] = new Bad;	
		}
		return MoodDB[DesiredEmotion];
	}
	else
	{
		return MoodDB[DesiredEmotion];
	}
}

void MoodManager::InitialiseMood(EnumSpace::MoodTypes MoodType, int Multipliers[])
{
	std::map<EnumSpace::EmotionTypes, int> TempMap;
	int NumberOfEmotions = EnumSpace::EmotionTypes::EmotionTypes_Max;
	for(int i =0; i <= NumberOfEmotions; i++)
	{
		TempMap[(EnumSpace::EmotionTypes) i] = Multipliers[i];
	}

	MoodEmotionMultipliers[MoodType] = TempMap;

}

std::map<EnumSpace::EmotionTypes, int> MoodManager::GetEmotionMultipliers(EnumSpace::MoodTypes DesiredMood)
{
	return MoodEmotionMultipliers[DesiredMood];
}

void MoodManager::Init(void)
{
	int Multipliers[] = {1, 3, 0};
	InitialiseMood(EnumSpace::enumGood, Multipliers);
	int Multipliers2[] = {1, 0, 3};
	InitialiseMood(EnumSpace::enumBad, Multipliers2);
}

MoodManager* MoodManager::GetInstance()
{
	if(Instance == NULL)
	{
		Instance = new MoodManager();
	}
	return Instance;
}