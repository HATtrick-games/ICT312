#include "StdAfx.h"
#include "FrameListener.h"

using namespace Graphics;

FrameListener::FrameListener() :
	m_deltaTime( 0.0f )
{
}

FrameListener::~FrameListener()
{
}

bool FrameListener::frameStarted( const Ogre::FrameEvent& evt )
{
	m_deltaTime = evt.timeSinceLastFrame;

	return true;
}

bool FrameListener::frameEnded( const Ogre::FrameEvent& evt )
{
	return true;
}

bool FrameListener::frameRenderingQueued( const Ogre::FrameEvent& evt )
{
	return true;
}
