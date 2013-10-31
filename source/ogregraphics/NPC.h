#pragma once
#include "stdafx.h"
#include "EmotionManager.h"
#include "ActionManager.h"
#include "MoodManager.h"
#include "EnumSpace.h"
#include "Goal.h"
#include "Relax.h"
#include "Work.h"
#include "Trait.h"
#include "FunLoving.h"
#include "Studious.h"
//#include "npcFSM.h"

class NPC //abstract later
{
public:
	NPC(void);
	~NPC(void);

	bool EmotionCheck();
	bool DetermineGoal();
	void CheckGoal();
	void Update();
	void Initialise();

	bool runCurrentState();
	void ProgressMood(EnumSpace::EmotionTypes S);

	//void setPosition();
	//vector3 getPosition

protected:
	Action* CurrentAction;
	Emotion* CurrentEmotion;
	Mood* CurrentMood;
	Goal* CurrentGoal;
	EnumSpace::NPCState CurrentState;
	Trait* myTrait;

	std::map <EnumSpace::NeedTypes, int> CurrentNeeds;
	std::map<EnumSpace::MoodTypes, int> MoodProgress;
};

