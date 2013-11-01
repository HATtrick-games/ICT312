#pragma once
#include "stdafx.h"

namespace EnumSpace
{
	enum ActionTypes
	{
		enumSit,
		enumUseComputer,
		ActionTypes_Max = enumUseComputer
	};

	enum MoodTypes
	{
		enumGood,
		enumBad,
		MoodTypes_Max = enumBad

	};

	enum EmotionTypes
	{
		enumNeutral,
		enumHappy,
		enumSad,
		EmotionTypes_Max = enumSad
	};

	enum NeedTypes
	{
		enumGrades,
		enumComfort,
		enumFun,
		NeedTypes_Max = enumFun
	};

	enum NPCState
	{
		enumSearching,
		enumIdling,
		enumInteracting,
		enumThinking,
		NPCState_Max = enumThinking
	};

}
