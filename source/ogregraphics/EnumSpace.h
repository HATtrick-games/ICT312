/**
 * \file	EnumSpace.h
 *
 * \brief	Declares the enum space class.
 */

#pragma once
#include "stdafx.h"

namespace EnumSpace
{
	/**
	 * \enum	ActionTypes
	 *
	 * \brief	Values that represent ActionTypes.
	 */

	enum ActionTypes
	{
		enumSit,
		enumUseComputer,
		ActionTypes_Max = enumUseComputer
	};

	/**
	 * \enum	MoodTypes
	 *
	 * \brief	Values that represent MoodTypes.
	 */

	enum MoodTypes
	{
		enumGood,
		enumBad,
		MoodTypes_Max = enumBad

	};

	/**
	 * \enum	EmotionTypes
	 *
	 * \brief	Values that represent EmotionTypes.
	 */

	enum EmotionTypes
	{
		enumNeutral,
		enumHappy,
		enumSad,
		EmotionTypes_Max = enumSad
	};

	/**
	 * \enum	NeedTypes
	 *
	 * \brief	Values that represent NeedTypes.
	 */

	enum NeedTypes
	{
		enumGrades,
		enumComfort,
		enumFun,
		NeedTypes_Max = enumFun
	};

	/**
	 * \enum	NPCState
	 *
	 * \brief	Values that represent NPCState.
	 */

	enum NPCState
	{
		enumSearching,
		enumIdling,
		enumInteracting,
		enumThinking,
		NPCState_Max = enumThinking
	};

/**
 * \property	}
 *
 * \brief	Gets or sets the.
 *
 * \value	.
 */

}
