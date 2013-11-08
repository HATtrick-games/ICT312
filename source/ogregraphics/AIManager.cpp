#include "StdAfx.h"
#include "AIManager.h"


AIManager::AIManager(void)
{

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
	for(int i = 0; i < NPCList.size(); i++)
	{
		std::cout << "NPC " << i << " ";
		NPCList[i]->Update();

		NPCList[i]->runCurrentState();
	}
}