#include "StdAfx.h"
#include "EmotionManager.h"

EmotionManager* EmotionManager::Instance = NULL;

EmotionManager::EmotionManager(void)
{
}


EmotionManager::~EmotionManager(void)
{
}

Emotion* EmotionManager::FetchEmotion(EnumSpace::EmotionTypes DesiredEmotion)
{
	if(EmotionDB[DesiredEmotion] == NULL)
	{
		if(DesiredEmotion == EnumSpace::enumHappy)
		{
			EmotionDB[DesiredEmotion] = new Happy;
		}
		else if(DesiredEmotion == EnumSpace::enumSad)
		{
			EmotionDB[DesiredEmotion] = new Sad;	
		}
		else if(DesiredEmotion == EnumSpace::enumNeutral)
		{
			EmotionDB[DesiredEmotion] = new Neutral;	
		}
		return EmotionDB[DesiredEmotion];
	}
	else
	{
		return EmotionDB[DesiredEmotion];
	}

}

EmotionManager* EmotionManager::GetInstance()
{
	if(Instance == NULL)
	{
		Instance = new EmotionManager();
	}
	return Instance;
}