#pragma once
#include "Action.h"
#include "stdafx.h"


class UseComputer : public Action
{
public:
	UseComputer(void);
	~UseComputer(void);

	bool Activate();
};

