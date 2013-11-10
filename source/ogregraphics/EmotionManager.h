/**
 * \file	EmotionManager.h
 *
 * \brief	Declares the emotion manager class.
 */

#pragma once
#include "stdafx.h"
#include "Emotion.h"
#include "Happy.h"
#include "Sad.h"
#include "Neutral.h"
#include "EnumSpace.h"

/**
 * \class	EmotionManager
 *
 * \brief	Manager for emotions.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class EmotionManager
{
public:

	/**
	 * \fn	Emotion* EmotionManager::FetchEmotion(EnumSpace::EmotionTypes DesiredEmotion);
	 *
	 * \brief	Fetches an emotion.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \param	DesiredEmotion	The desired emotion.
	 *
	 * \return	null if it fails, else the emotion.
	 */

	Emotion* FetchEmotion(EnumSpace::EmotionTypes DesiredEmotion);

	/**
	 * \fn	static EmotionManager* EmotionManager::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static EmotionManager* GetInstance();

private:

	/**
	 * \brief	The emotion database.
	 */

	std::map<EnumSpace::EmotionTypes, Emotion*> EmotionDB;

	/**
	 * \brief	The emotion mood multipliers.
	 */

	std::map<EnumSpace::EmotionTypes, std::map<EnumSpace::MoodTypes, int>> EmotionMoodMultipliers;

	/**
	 * \brief	The instance.
	 */

	static EmotionManager* Instance;

	/**
	 * \fn	EmotionManager::EmotionManager(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	EmotionManager(void);

	/**
	 * \fn	EmotionManager::~EmotionManager(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~EmotionManager(void);
};

