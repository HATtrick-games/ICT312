#pragma once

#include "stdafx.h"
#include "Mood.h"
#include "Good.h"
#include "Bad.h"
#include "EmotionManager.h"

class MoodManager
{
public:



	Mood* FetchMood(EnumSpace::MoodTypes DesiredMood);

	void InitialiseMood(EnumSpace::MoodTypes MoodType, int* Multipliers);

	std::map<EnumSpace::EmotionTypes, int> GetEmotionMultipliers(EnumSpace::MoodTypes MoodType);

	void Init(void); //Initialise the manager class, call all individual action initialisation through here.
	
	static MoodManager* GetInstance();

private:
	std::map<EnumSpace::MoodTypes, Mood*> MoodDB;
	std::map<EnumSpace::MoodTypes, std::map<EnumSpace::EmotionTypes, int>> MoodEmotionMultipliers;
	//std::map<EnumSpace::MoodTypes, int> MoodProgression;


	static MoodManager* Instance;

	MoodManager(void);
	~MoodManager(void);
};

