#include "StdAfx.h"
#include "NPC.h"


NPC::NPC(void)
{
	Initialise();
}


NPC::~NPC(void)
{
}

void NPC::Initialise(void)
{
	srand (time(NULL));
	CurrentNeeds[EnumSpace::enumGrades] = 0;
	CurrentNeeds[EnumSpace::enumComfort] = 0;
	CurrentNeeds[EnumSpace::enumFun] = 0;
	CurrentEmotion = EmotionManager::GetInstance()->FetchEmotion(EnumSpace::enumNeutral);
	CurrentMood = MoodManager::GetInstance()->FetchMood(EnumSpace::enumGood);
	CurrentState = EnumSpace::enumIdling;

	int i = rand() % 3;
	
	if(i == 0)
	{
		myTrait = new FunLoving;
	}
	else if(i == 1)
	{
		myTrait = new Studious;
	}
	else
	{
		myTrait = new FunLoving; //change to third
	}
}

bool NPC::EmotionCheck(void)
{	
	int TotalModifiers[EnumSpace::EmotionTypes_Max];
	int Total = 0;

	for(int i =0; i < EnumSpace::EmotionTypes_Max; i++)
	{	
		TotalModifiers[i] += (ActionManager::GetInstance()->GetEmotionMultipliers(CurrentAction->GetType())[(EnumSpace::EmotionTypes)i]);
		TotalModifiers[i] += (MoodManager::GetInstance()->GetEmotionMultipliers(CurrentMood->GetType())[(EnumSpace::EmotionTypes)i]);

		Total += TotalModifiers[i];
	}

	int X = 0;
	int EmotionalProb;
	EnumSpace::EmotionTypes EmotionalOutcome = EnumSpace::enumNeutral;

	EmotionalProb = rand() % Total;

	for(int i = 0; i < EnumSpace::EmotionTypes_Max; i++)
	{
		if(EmotionalProb <= (X += TotalModifiers[i]))
		{
			EmotionalOutcome = (EnumSpace::EmotionTypes)i;
		}
	}

	CurrentEmotion = EmotionManager::GetInstance()->FetchEmotion(EmotionalOutcome); //Change emotion

	ProgressMood(EmotionalOutcome);
	//Do something with this emotion. Swap it out and ...?

	return true;
}

void NPC::ProgressMood(EnumSpace::EmotionTypes EmotionalOutcome)
{
	int flag = 0;
	if(EmotionalOutcome == EnumSpace::enumHappy)
	{
		if(MoodProgress[EnumSpace::enumGood]++ > 10)
		{
			flag = 1;
		}
	}
	else if(EmotionalOutcome == EnumSpace::enumSad)
	{
		if(MoodProgress[EnumSpace::enumBad]++ > 10)
		{
			flag = 2;
		}
	}
	
	if(flag > 0)
	{
		if(flag == 1)
		{
			CurrentMood = MoodManager::GetInstance()->FetchMood(EnumSpace::enumGood);
		}
		else
		{
			CurrentMood = MoodManager::GetInstance()->FetchMood(EnumSpace::enumBad);
		}
		MoodProgress[EnumSpace::enumBad] = 0;
		MoodProgress[EnumSpace::enumGood] = 0;
	}
}

bool NPC::DetermineGoal()
{
	//Determine a status bar priority
	
	//Slot in here ADD TRAIT MODIFIER TO APPROPRIATE NEED

	int Total = CurrentNeeds[EnumSpace::enumGrades] + CurrentNeeds[EnumSpace::enumComfort] + CurrentNeeds[EnumSpace::enumFun];

	int Outcome = 0;
	if(Total != 0)
	{
		Outcome = rand() % Total;
	}

	int NeedLevel = 0;
	EnumSpace::NeedTypes Need;
	getchar();
	if(Outcome > (Total -= CurrentNeeds[EnumSpace::enumFun]))
	{
		std::cout << "Prioritising Fun" << std::endl;
		NeedLevel = CurrentNeeds[EnumSpace::enumFun];
		Need = EnumSpace::enumFun;
	}
	else if(Outcome > (Total -= CurrentNeeds[EnumSpace::enumComfort]))
	{
		std::cout << "Prioritising Comfort" << std::endl;
		NeedLevel = CurrentNeeds[EnumSpace::enumComfort];
		Need = EnumSpace::enumComfort;
	}
	else if(Outcome > (Total -= CurrentNeeds[EnumSpace::enumGrades]))
	{
		std::cout << "Prioritising Grades" << std::endl;
		NeedLevel = CurrentNeeds[EnumSpace::enumGrades];
		Need = EnumSpace::enumGrades;
	}
	else
	{
		//something went wrong
	}

	Outcome = rand() % 100;

	if(CurrentMood->GetType() == EnumSpace::enumGood)
	{
		Outcome - 10;
	}
	else if(CurrentMood->GetType() == EnumSpace::enumBad)
	{
		Outcome + 10;
	}

	if(Outcome < NeedLevel)
	{
		std::cout << "Picking a goal" << std::endl;

		switch(Need)
		{
		case EnumSpace::enumFun:
			{
				CurrentGoal = new Relax;
			}
		case EnumSpace::enumComfort:
			{
				CurrentGoal = new Relax;
			}
		case EnumSpace::enumGrades:
			{
				CurrentGoal = new Work;
			}

		}
	
		
		return true;
	}
	else
	{
		return false;
	}


}
bool NPC::runCurrentState()
{
	switch(CurrentState)
	{
		case EnumSpace::enumThinking:
		{
			std::cout << "Thinking" << std::endl;
			if(DetermineGoal()) //return true if a goal is determined, if not return to idle?
			{
				std::cout << "Goal Determined" << std::endl;
				CurrentState = EnumSpace::enumSearching;
				return true;
			}
			else
			{
				std::cout << "Demotivated, no goal selected" << std::endl;
				CurrentState = EnumSpace::enumIdling;
				return false;
			}
			break;
		}
		case EnumSpace::enumIdling:
		{
			std::cout << "Idling" << std::endl;
			if(rand() %2 == 0)
			{
				std::cout << "Motivated, examining goals" << std::endl;
				CurrentState = EnumSpace::enumThinking;
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
		case EnumSpace::enumInteracting:
		{
			std::cout << "Interacting" << std::endl;
			//get current object, perform current goal action with (% chance to repeat action = return false)
			//CurrentGoal->GetAction()->Use();
			return false;
			break;
		}
		case EnumSpace::enumSearching:
		{
			std::cout << "Searching for interactable object" << std::endl;
			//this is where affordance checking comes in.
			/*
			
				CurrentGoal->GetThreshold(); //compare this to affordance value on objects
				ObjectPointer = NULL;
				ObjectPointer = blahclass::GetInstance()->GetObject(AI postion Ogre Vector, CurrentGoal->AffordanceName(string) CurrentGoal->AffordanceMin(int));
				if (  == NULL )
				{
					Object Not found // change affordance value for next attempt
				}
				else
				{
					myObjectPointer = ObjectPointer;
				}

			*/
			return true;
			break;
		}
	}
}
void NPC::Update()
{


	//Decay a random Need

	switch(rand() % 3)
	{
	case 0:
		{
			CurrentNeeds[EnumSpace::enumGrades]++;
			if(CurrentNeeds[EnumSpace::enumGrades] > 100)
			{
				CurrentNeeds[EnumSpace::enumGrades] = 100;
			}
			break;
		}
	case 1:
		{
			CurrentNeeds[EnumSpace::enumComfort]++;
			if(CurrentNeeds[EnumSpace::enumComfort] > 100)
			{
				CurrentNeeds[EnumSpace::enumComfort] = 100;
			}
			break;
		}
	case 2:
		{
			CurrentNeeds[EnumSpace::enumFun]++;
			if(CurrentNeeds[EnumSpace::enumFun] > 100)
			{
				CurrentNeeds[EnumSpace::enumFun] = 100;
			}
			break;
		}
	}

	//if currently owns a goal + affordance, decay that affordance
}