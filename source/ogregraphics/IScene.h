#pragma once

#include "IObject.h"

typedef std::map< std::string, Objects::IObject* > MapObjects;
typedef MapObjects::const_iterator MapObjectsItr;

namespace Scenes
{
	/**
	 * \class	IScene
	 *
	 * \brief	Scene interface including scene initialisation, updating and
	 * 			actions when the scene is exited.
	 * 			
	 * \author	Timothy Veletta
	 * \date	15/08/13
	 */
	class IScene
	{
	public:

		/**
		 * \fn	virtual void IScene::initialise() = 0;
		 *
		 * \brief	Initialises the scene.
		 */
		virtual void initialise() = 0;

		/**
		 * \fn	virtual void IScene::update( float deltaTime ) = 0;
		 *
		 * \brief	Updates the scene given the change in time from one 
		 * 			frame to another.
		 *
		 * \param	deltaTime	The change in time from one frame to another.
		 */
		virtual void update( float deltaTime );

		/**
		 * \fn	virtual void IScene::onExit() = 0;
		 *
		 * \brief	Called upon the scene being closed.
		 */
		virtual void onExit() = 0;

		void				addObject( std::string identifier, Objects::IObject* object );
		void				removeObject( std::string identifier );
		Objects::IObject*	getObject( std::string identifier );

	private:
		MapObjects			m_objects;

	};
}