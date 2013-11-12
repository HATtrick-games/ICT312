/**
 * \file	FrameListener.h
 *
 * \brief	Declares the frame listener class.
 */

#pragma once

#include "DebugDrawer.h"

namespace Graphics
{
	/**
	 * \class	FrameListener
	 *
	 * \brief	Frame listener.
	 */

	class FrameListener :
		public Ogre::FrameListener
	{
	public:

		/**
		 * \fn	FrameListener::FrameListener(Ogre::SceneManager* sceneManager);
		 *
		 * \brief	Constructor.
		 *
		 * \param [in,out]	sceneManager	If non-null, manager for scene.
		 */

		FrameListener(Ogre::SceneManager* sceneManager);

		/**
		 * \fn	FrameListener::~FrameListener();
		 *
		 * \brief	Destructor.
		 */

		~FrameListener();

		/**
		 * \fn	virtual bool FrameListener::frameStarted( const Ogre::FrameEvent& evt );
		 *
		 * \brief	Frame started.
		 *
		 * \param	evt	The event.
		 *
		 * \return	true if it succeeds, false if it fails.
		 */

		virtual bool	frameStarted( const Ogre::FrameEvent& evt );

		/**
		 * \fn	virtual bool FrameListener::frameEnded( const Ogre::FrameEvent& evt );
		 *
		 * \brief	Frame ended.
		 *
		 * \param	evt	The event.
		 *
		 * \return	true if it succeeds, false if it fails.
		 */

		virtual bool	frameEnded( const Ogre::FrameEvent& evt );

		/**
		 * \fn	virtual bool FrameListener::frameRenderingQueued( const Ogre::FrameEvent& evt );
		 *
		 * \brief	Frame rendering queued.
		 *
		 * \param	evt	The event.
		 *
		 * \return	true if it succeeds, false if it fails.
		 */

		virtual bool	frameRenderingQueued( const Ogre::FrameEvent& evt );

		/**
		 * \fn	float FrameListener::getDeltaTime() const
		 *
		 * \brief	Gets delta time.
		 *
		 * \return	The delta time.
		 */

		float			getDeltaTime() const { return m_deltaTime; }
	private:

		/**
		 * \brief	Time of the delta.
		 */

		float			m_deltaTime;
	};
}
