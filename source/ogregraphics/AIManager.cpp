#include "StdAfx.h"
#include "AIManager.h"


AIManager::AIManager(void)
{
	counter = 0;
}


AIManager::~AIManager(void)
{
}

void AIManager::Initialise()
{

}
void AIManager::AddNPC(Objects::IObject* ObjectPointer)
{
	NPCList.push_back(new NPC(ObjectPointer));
}

NPC* AIManager::GetNPC(int Index)
{
	return NPCList[Index];
}

void AIManager::UpdateAI()
{
	if(counter%100 == 0)
	{
		for(int i = 0; i < NPCList.size(); i++)
		{
			std::cout << std::endl << "NPC " << i << " " << std::endl;
			NPCList[i]->Update();

			NPCList[i]->runCurrentState();

		}
	}
	counter++;
}