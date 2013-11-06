#pragma once
#include "stdafx.h"
#include "Action.h"

class Sit : public Action
{
public:
	Sit(void);
	~Sit(void);

	bool Activate();
};

