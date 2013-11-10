/**
 * \file	MoodManager.h
 *
 * \brief	Declares the mood manager class.
 */

#pragma once

#include "stdafx.h"
#include "Mood.h"
#include "Good.h"
#include "Bad.h"
#include "EmotionManager.h"

/**
 * \class	MoodManager
 *
 * \brief	Manager for moods.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class MoodManager
{
public:

	/**
	 * \fn	Mood* MoodManager::FetchMood(EnumSpace::MoodTypes DesiredMood);
	 *
	 * \brief	Fetches a mood.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \param	DesiredMood	The desired mood.
	 *
	 * \return	null if it fails, else the mood.
	 */

	Mood* FetchMood(EnumSpace::MoodTypes DesiredMood);

	/**
	 * \fn	void MoodManager::InitialiseMood(EnumSpace::MoodTypes MoodType, int* Multipliers);
	 *
	 * \brief	Initialises the mood.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \param	MoodType		   	Type of the mood.
	 * \param [in,out]	Multipliers	If non-null, the multipliers.
	 */

	void InitialiseMood(EnumSpace::MoodTypes MoodType, int* Multipliers);

	/**
	 * \fn	std::map<EnumSpace::EmotionTypes, int> MoodManager::GetEmotionMultipliers(EnumSpace::MoodTypes MoodType);
	 *
	 * \brief	Gets emotion multipliers.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \param	MoodType	Type of the mood.
	 *
	 * \return	The emotion multipliers.
	 */

	std::map<EnumSpace::EmotionTypes, int> GetEmotionMultipliers(EnumSpace::MoodTypes MoodType);

	/**
	 * \fn	void MoodManager::Init(void);
	 *
	 * \brief	Initialises this object.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	void Init(void); //Initialise the manager class, call all individual action initialisation through here.

	/**
	 * \fn	static MoodManager* MoodManager::GetInstance();
	 *
	 * \brief	Gets the instance.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 *
	 * \return	null if it fails, else the instance.
	 */

	static MoodManager* GetInstance();

private:

	/**
	 * \brief	The mood database.
	 */

	std::map<EnumSpace::MoodTypes, Mood*> MoodDB;

	/**
	 * \brief	The mood emotion multipliers.
	 */

	std::map<EnumSpace::MoodTypes, std::map<EnumSpace::EmotionTypes, int>> MoodEmotionMultipliers;

	/**
	 * \brief	std::map<EnumSpace::MoodTypes, int> MoodProgression;
	 */

	static MoodManager* Instance;

	/**
	 * \fn	MoodManager::MoodManager(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	MoodManager(void);

	/**
	 * \fn	MoodManager::~MoodManager(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~MoodManager(void);
};

