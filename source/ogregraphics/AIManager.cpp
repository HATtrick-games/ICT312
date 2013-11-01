#include "StdAfx.h"
#include "AIManager.h"


AIManager::AIManager(void)
{
	NPCList.push_back(new NPC);
	NPCList.push_back(new NPC);
}


AIManager::~AIManager(void)
{
}

void AIManager::Initialise()
{

}

void AIManager::UpdateAI()
{
	/*
		for(each NPC)
		{
			checkCurrentActivity() //is it idle? Enum?
			if(idle)
				check whether or not transition should be triggered

			if activity complete return true, transition.

			Activities are goals, 


			checkCurrentState()
			runCurrentState() //set a flag signalling action completion when done (if goal determinining, and returned false transition back to idle)
			
			checkStateFlag() //trigger a transition


		}


	*/

	/*for (std::map<NPC*,npcFSM*>::iterator it=NPCList.begin(); it!=NPCList.end(); ++it)
	{
		if((it->first)->runCurrentState())
		{
			//call a function with a switch case of the current action and desired action, mapped to a fsmtransition
			//it->first->CurrentAction 
		}
		else
		{
			//if(it->first->CurrentAction)
			//{

			//}
		}
    }*/

	for(int i = 0; i < NPCList.size(); i++)
	{
		std::cout << "NPC " << i << " ";
		NPCList[i]->Update();

		NPCList[i]->runCurrentState();
	}
}