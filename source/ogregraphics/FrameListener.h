#pragma once

namespace Graphics
{
	class FrameListener :
		public Ogre::FrameListener
	{
	public:
		FrameListener();
		~FrameListener();

		virtual bool	frameStarted( const Ogre::FrameEvent& evt );
		virtual bool	frameEnded( const Ogre::FrameEvent& evt );
		virtual bool	frameRenderingQueued( const Ogre::FrameEvent& evt );

		float			getDeltaTime() const { return m_deltaTime; }
	private:
		float			m_deltaTime;
	};
}
