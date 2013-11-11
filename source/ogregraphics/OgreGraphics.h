#pragma once

#include "DebugDrawer.h"
#include "FrameListener.h"
#include "Vector3.h"
#include <cmath>
#include <math.h>

const std::string	WINDOWTITLE = "Ogre Graphics Test";

typedef std::map< std::string, Ogre::SceneNode* > MapSceneNode;

enum RelativeTo
{
	RT_WORLD,
	RT_LOCAL
};

namespace Graphics
{
	/**
	 * \class	OgreGraphics
	 *
	 * \brief	Facade class for Ogre3D graphics engine. Allows for the creation
	 * 			of windows, cameras, lighting, entities and more using Ogre3D.
	 *
	 * \author	Timothy Veletta
	 * \date	13/08/2013
	 */
	class OgreGraphics
	{
	public:
		Ogre::Vector3 GetPosition()
		{
			return m_camera->getPosition();
		}

		/**
		 * \fn	OgreGraphics::OgreGraphics(void);
		 *
		 * \brief	Default constructor.
		 * 			
		 *	Initialises the member variables of this class.
		 */
		OgreGraphics(void);

		/**
		 * \fn	OgreGraphics::~OgreGraphics(void);
		 *
		 * \brief	Destructor.
		 * 			
		 *	Destroys the Ogre Root object which in turn destroys all other
		 *	objects that are attached to it.
		 */
		~OgreGraphics(void);

		/**
		 * \fn	bool OgreGraphics::initialise();
		 *
		 * \brief	Initialises this object.
		 * 			
		 *	Sets up the Ogre root, window, scene manager, camera, viewport and frame
		 *	listener before loading resources.
		 *
		 * \return	true if it succeeds, false if it fails.
		 */
		bool				initialise();

		/**
		 * \fn	void OgreGraphics::loadResources();
		 *
		 * \brief	Loads the resources.
		 * 			
		 *	Loads the 'resources.cfg' file which contains information about the
		 *	resources used by this program.
		 */
		void				loadResources();

		/**
		 * \fn	void OgreGraphics::renderOneFrame();
		 *
		 * \brief	Renders a single frame.
		 * 			
		 *	Renders a single frame to screen using the main camera object as
		 *	the viewpoint.
		 */
		void				renderOneFrame();

		/**
		 * \fn	float OgreGraphics::getDeltaTime()
		 *
		 * \brief	Gets delta time.
		 *
		 *	Gets the change in time from one frame to the next. 
		 *
		 * \return	The delta time.
		 */
		float				getDeltaTime() { return m_frameListener->getDeltaTime(); }

		/**
		 * \fn	void OgreGraphics::cameraSetPosition( float posX, float posY, float posZ );
		 *
		 * \brief	Sets the position of the camera object.
		 *
		 * \param	posX	The position x coordinate.
		 * \param	posY	The position y coordinate.
		 * \param	posZ	The position z coordinate.
		 */
		void				cameraSetPosition( float posX, float posY, float posZ );

		/**
		 * \fn	void OgreGraphics::cameraSetLookAt( float lookAtX, float lookAtY, float lookAtZ );
		 *
		 * \brief	Sets the point that the camera object looks at.
		 *
		 * \param	lookAtX	The look at x coordinate.
		 * \param	lookAtY	The look at y coordinate.
		 * \param	lookAtZ	The look at z coordinate.
		 */
		void				cameraSetLookAt( float lookAtX, float lookAtY, float lookAtZ );

		/**
		 * \fn	void OgreGraphics::cameraSetAspectRatio( float ratio );
		 *
		 * \brief	Sets the aspect ratio from which the camera is viewed.
		 *
		 * \param	ratio	The ratio.
		 */
		void				cameraSetAspectRatio( float ratio );

		/**
		 * \fn	void OgreGraphics::cameraMoveRelative( Ogre::Vector3& movement );
		 *
		 * \brief	Moves the camera object relative to its current position.
		 *
		 * \param [in,out]	movement	The movement.
		 */
		void				cameraMoveRelative( Ogre::Vector3& movement );

		/**
		 * \fn	void OgreGraphics::cameraYaw( Ogre::Radian& angle );
		 *
		 * \brief	Sets the camera yaw angle.
		 *
		 * \param [in,out]	angle	The angle.
		 */
		void				cameraYaw( Ogre::Radian& angle );

		/**
		 * \fn	void OgreGraphics::cameraPitch( Ogre::Radian& angle );
		 *
		 * \brief	Sets the camera pitch angle.
		 *
		 * \param [in,out]	angle	The angle.
		 */
		void				cameraPitch( Ogre::Radian& angle );

		Ogre::Vector3		cameraDirection() { return m_camera->getDirection(); }

		/**
		 * \fn	int OgreGraphics::getWindowWidth() const
		 *
		 * \brief	Returns the width of the window.
		 *
		 * \return	The window width.
		 */
		int					getWindowWidth() const { return m_renderWindow->getWidth(); }

		/**
		 * \fn	int OgreGraphics::getWindowHeight() const
		 *
		 * \brief	Returns the height of the window
		 *
		 * \return	The window height.
		 */
		int					getWindowHeight() const { return m_renderWindow->getHeight(); }

		/**
		 * \fn	Ogre::RenderWindow* OgreGraphics::getRenderWindow() const
		 *
		 * \brief	Gets render window. TODO: Remove in favor of outputting
		 * 			the necessary information.
		 *
		 * \return	null if it fails, else the render window.
		 */
		Ogre::RenderWindow*	getRenderWindow() const { return m_renderWindow; }

		/**
		 * \fn	void OgreGraphics::createMeshEntity( std::string identifier, std::string filename );
		 *
		 * \brief	Creates a mesh entity and attaches it to the root scene node.
		 *
		 * \param	identifier	The entity identifier.
		 * \param	filename  	Filename of the mesh file.
		 */
		void				createMeshEntity( std::string identifier, std::string filename );

		/**
		 * \fn	void OgreGraphics::createPlaneEntity( std::string identifier, std::string meshName,
		 *  Ogre::Vector3 normal, float changeAlongNormal, float width, float height, int xSegments,
		 *  int ySegments, float uTile, float vTile );
		 *
		 * \brief	Creates plane entity and attaches it to the root scene node.
		 *
		 * \param	identifier		 	The entity identifier.
		 * \param	meshName		 	Name of the mesh.
		 * \param	normal			 	The normal to the plane.
		 * \param	changeAlongNormal	How much to move the plane along the normal.
		 * \param	width			 	The width of the plane.
		 * \param	height			 	The height of the plane.
		 * \param	xSegments		 	The number segments in the x coordinate.
		 * \param	ySegments		 	The number segments in the y coordinate.
		 * \param	uTile			 	The texture tiling in the u direction.
		 * \param	vTile			 	The texture tiling in the v direction.
		 * 								
		 */
		void				createPlaneEntity( std::string identifier, std::string meshName, 
								Ogre::Vector3 normal, float changeAlongNormal, float width, float height, 
								int xSegments, int ySegments, float uTile, float vTile, std::string material = NULL );

		/**
		 * \fn	void OgreGraphics::createDirectionalLight( std::string name, float posX, float posY,
		 *  float posZ, float dirX, float dirY, float dirZ );
		 *
		 * \brief	Creates a directional light at the position specified facing in the input direction.
		 *
		 * \param	name	The name.
		 * \param	posX	The position x coordinate.
		 * \param	posY	The position y coordinate.
		 * \param	posZ	The position z coordinate.
		 * \param	dirX	The direction x coordinate.
		 * \param	dirY	The direction y coordinate.
		 * \param	dirZ	The direction z coordinate.
		 */
		void				createDirectionalLight( std::string name, float posX, float posY, float posZ, 
								float dirX, float dirY, float dirZ );
		
		void				createEmptyEntity( std::string identifier );
		void				createChildEntity( std::string parentID, std::string childID );

		void				setEntityYaw( std::string identifier, float angle ); // using radians
		void				setEntityPitch( std::string identifier, float angle ); // using radians
		void				setEntityRoll( std::string identifier, float angle ); // using radians
		void				translateEntity( std::string identifier, float x, float y, float z );
		void				translateEntity( std::string identifier, Ogre::Vector3 translateVector );
		void				setEntityPosition( std::string identifier, float x, float y, float z );
		Ogre::Quaternion	getEntityOrientation( std::string identifier );
		void				setEntityOrientation( std::string identifier, Ogre::Quaternion quat );
		void				setEntityScale( std::string identifier, Ogre::Vector3 scale );
		Ogre::Vector3		getEntityScale(std::string identifier);

		Ogre::Entity*		getEntity( std::string identifier );
		DebugDrawer*		getDebugDrawer();
		Ogre::SceneManager* GetSceneManager();
	private:
		MapSceneNode		m_sceneNodes;
		
		Ogre::Root*			m_root;
		Ogre::RenderWindow*	m_renderWindow;
		Ogre::SceneManager*	m_sceneManager;
		Ogre::Camera*		m_camera;
		Ogre::Viewport*		m_viewport;
		
		FrameListener*		m_frameListener;
	};
}
