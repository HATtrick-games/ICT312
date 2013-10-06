#include "StdAfx.h"
#include "FrameListener.h"

using namespace Graphics;

FrameListener::FrameListener(Ogre::SceneManager* sceneManager) :
	m_deltaTime( 0.0f )
{
	new DebugDrawer(sceneManager, 0.5f);
}

FrameListener::~FrameListener()
{
	delete DebugDrawer::getSingletonPtr();
}

bool FrameListener::frameStarted( const Ogre::FrameEvent& evt )
{
	m_deltaTime = evt.timeSinceLastFrame;

	DebugDrawer::getSingleton().build();

	return true;
}

bool FrameListener::frameEnded( const Ogre::FrameEvent& evt )
{
	DebugDrawer::getSingleton().clear();

	return true;
}

bool FrameListener::frameRenderingQueued( const Ogre::FrameEvent& evt )
{
	return true;
}
