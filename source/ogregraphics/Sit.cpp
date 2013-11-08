#include "StdAfx.h"
#include "Sit.h"


Sit::Sit(void)
{
	Threshold = 70;
	AffordanceName = "Sit";
}


Sit::~Sit(void)
{
}

bool Sit::Activate()
{
	std::cout << "Sitting";

	int outcome = rand() %10;

	if(outcome == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}