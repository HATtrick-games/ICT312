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
	CurrentGoal = NULL;


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
		myTrait = new EasyGoing; 
	}
}

bool NPC::EmotionCheck(void)
{	
	int TotalModifiers[EnumSpace::EmotionTypes_Max];
	int Total = 0;

	for(int i =0; i < EnumSpace::EmotionTypes_Max; i++)
	{	
		TotalModifiers[i] += (ActionManager::GetInstance()->GetEmotionMultipliers(CurrentGoal->GetAction()->GetType())[(EnumSpace::EmotionTypes)i]);
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
	
	int Grades = 0;
	int Comfort = 0;
	int Fun = 0;

	Grades = CurrentNeeds[EnumSpace::enumGrades] + myTrait->GetGoalModifier()[EnumSpace::enumGrades];
	Comfort = CurrentNeeds[EnumSpace::enumComfort] + myTrait->GetGoalModifier()[EnumSpace::enumComfort];
	Fun = CurrentNeeds[EnumSpace::enumFun] + myTrait->GetGoalModifier()[EnumSpace::enumFun];

	int Total = Grades + Comfort + Fun;

	int Outcome = 0;
	if(Total != 0)
	{
		Outcome = rand() % Total;
	}

	int NeedLevel = 0;
	EnumSpace::NeedTypes Need;
	//getchar();
	if(Outcome > (Total -= Fun))
	{
		std::cout << "Prioritising Fun" << std::endl;
		NeedLevel = Fun;
		Need = EnumSpace::enumFun;
	}
	else if(Outcome > (Total -= Comfort))
	{
		std::cout << "Prioritising Comfort" << std::endl;
		NeedLevel = Comfort;
		Need = EnumSpace::enumComfort;
	}
	else if(Outcome > (Total -= Grades))
	{
		std::cout << "Prioritising Grades" << std::endl;
		NeedLevel = Grades;
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
				break;
			}
		case EnumSpace::enumComfort:
			{
				CurrentGoal = new Relax;
				break;
			}
		case EnumSpace::enumGrades:
			{
				CurrentGoal = new Work;
				break;
			}

		}
		CurrentGoal->ResetThreshhold();

			
		return true;
	}
	else
	{
		return false;
	}


}

void NPC::Clicked(std::string Click)
{
	if(Click == "Left")
	{
	std::cout << "Hey don't click me!";
	ProgressMood(EnumSpace::enumSad);
	}
	else
	{
		std::cout<<"That feels nice!";
		ProgressMood(EnumSpace::enumHappy);
	}
}

bool NPC::runCurrentState()
{
	std::cout << "CURRENT STATE";
	//std::getchar();
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
				std::cout << "Motivated, examining goals..";
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

			ObjectPointer->SetInteractable(false);

			if(CurrentGoal->GetAction()->Activate())
			{
				EmotionCheck();
				CurrentState = EnumSpace::enumIdling; 
			}
			else
			{
				CurrentNeeds[EnumSpace::enumFun] -= (*CurrentGoal->ModifyNeeds())[EnumSpace::enumFun];
				CurrentNeeds[EnumSpace::enumGrades] -= (*CurrentGoal->ModifyNeeds())[EnumSpace::enumGrades];
				CurrentNeeds[EnumSpace::enumComfort] -= (*CurrentGoal->ModifyNeeds())[EnumSpace::enumComfort];
				if(CurrentNeeds[EnumSpace::enumFun] < 0)
				{
					CurrentNeeds[EnumSpace::enumFun] = 0;
				}
				if(CurrentNeeds[EnumSpace::enumGrades] < 0)
				{
					CurrentNeeds[EnumSpace::enumGrades] = 0;
				}
				if(CurrentNeeds[EnumSpace::enumComfort] < 0)
				{
					CurrentNeeds[EnumSpace::enumComfort] = 0;
				}
			}

			return false;
			break;
		}
		case EnumSpace::enumSearching:
		{
			std::cout << "Searching for interactable object... ";
			//this is where affordance checking comes in.
			
			
				//CurrentGoal->GetThreshold(); //compare this to affordance value on objects
				ObjectPointer = NULL;
				cout<<CurrentGoal->GetAction()->GetAffordanceName()<<"\n";
				cout<<CurrentGoal->GetThreshold()<<"\n";
				ObjectPointer = ItemStore::Instance()->GetObject(myObj->getPosition(), "Sit", CurrentGoal->GetThreshold());
				std::cout << "Checked ItemSTORE";
				//std::getchar();
				//cout<<ObjectPointer->getEntityName()<<"\n";
				if ( ObjectPointer == NULL )
				{
				//	Object Not found // change affordance value for next attempt
					CurrentGoal->DecayThreshold();
				}
				else
				{
					std::cout << "Found an object with suitable affordance";
					CurrentState = EnumSpace::enumInteracting;
				}
		
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
	

	if(CurrentGoal != NULL)
	{
		CurrentGoal->DecayThreshold();
	}
}