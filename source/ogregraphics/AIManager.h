#pragma once
#include "stdafx.h"
#include "NPC.h"
#include "IObject.h"

class AIManager
{
public:
	AIManager(void);
	~AIManager(void);

	void UpdateAI();
	void Initialise();
	void AddNPC(Objects::IObject* ObjectPointer);
	NPC* GetNPC(int index);

private:
	int counter;
	std::vector<NPC*> NPCList;
};

