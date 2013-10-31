#pragma once
#include "stdafx.h"
#include "NPC.h"

class AIManager
{
public:
	AIManager(void);
	~AIManager(void);

	void UpdateAI();
	void Initialise();

private:

	std::vector<NPC*> NPCList;
};

