/**
 * \file	DebugDrawerOg.h
 *
 * \brief	An implementation of the Bullet debug drawer taken from the Ogre Wiki http://www.ogre3d.org/tikiwiki/BulletDebugDrawer&structure=Cookbook
 */

#ifndef DebugDrawer_h__

/**
 * \def	DebugDrawer_h__
 *
 * \brief	A macro that defines debug drawer h.
 *
 * \author	Ogre Wiki
 * \date	31/10/2013
 */

#define DebugDrawer_h__
 
#include "CollisionWorldSingleton.h"
#include "boost\range\detail\common.hpp"
 
class OgreDebugDrawer: public btIDebugDraw, public Ogre::FrameListener{
public:

    /**
     * \fn	OgreDebugDrawer::OgreDebugDrawer( Ogre::SceneManager *scm );
     *
     * \brief	Constructor.
     *
     * \author	Ogre Wiki
     * \date	31/10/2013
     *
     * \param [in,out]	scm	If non-null, the scm.
     */

    OgreDebugDrawer( Ogre::SceneManager *scm );

    /**
     * \fn	OgreDebugDrawer::~OgreDebugDrawer ();
     *
     * \brief	Destructor.
     *
     * \author	Ogre Wiki
     * \date	31/10/2013
     */

    ~OgreDebugDrawer ();

    /**
     * \fn	virtual void OgreDebugDrawer::drawLine (const btVector3 &from, const btVector3 &to,
     * 		const btVector3 &color);
     *
     * \brief	Draw line.
     *
     * \author	Ogre Wiki
     * \date	31/10/2013
     *
     * \param	from 	Source for the.
     * \param	to   	to.
     * \param	color	The color.
     */

    virtual void     drawLine (const btVector3 &from, const btVector3 &to, const btVector3 &color);

    /**
     * \fn	virtual void OgreDebugDrawer::drawTriangle (const btVector3 &v0, const btVector3 &v1,
     * 		const btVector3 &v2, const btVector3 &color, btScalar);
     *
     * \brief	Draw triangle.
     *
     * \author	Ogre Wiki
     * \date	31/10/2013
     *
     * \param	v0		  	The v 0.
     * \param	v1		  	The first btVector3.
     * \param	v2		  	The second btVector3.
     * \param	color	  	The color.
     * \param	parameter5	The fifth parameter.
     */

    virtual void     drawTriangle (const btVector3 &v0, const btVector3 &v1, const btVector3 &v2, const btVector3 &color, btScalar);

    /**
     * \fn	virtual void OgreDebugDrawer::drawContactPoint (const btVector3 &PointOnB,
     * 		const btVector3 &normalOnB, btScalar distance, int lifeTime, const btVector3 &color);
     *
     * \brief	Draw contact point.
     *
     * \author	Ogre Wiki
     * \date	31/10/2013
     *
     * \param	PointOnB 	The point on b.
     * \param	normalOnB	The normal on b.
     * \param	distance 	The distance.
     * \param	lifeTime 	Time of the life.
     * \param	color	 	The color.
     */

    virtual void     drawContactPoint (const btVector3 &PointOnB, const btVector3 &normalOnB, btScalar distance, int lifeTime, const btVector3 &color);

    /**
     * \fn	virtual void OgreDebugDrawer::reportErrorWarning (const char *warningString);
     *
     * \brief	Reports error warning.
     *
     * \author	Ogre Wiki
     * \date	31/10/2013
     *
     * \param	warningString	The warning string.
     */

    virtual void     reportErrorWarning (const char *warningString);

    /**
     * \fn	virtual void OgreDebugDrawer::draw3dText (const btVector3 &location,
     * 		const char *textString);
     *
     * \brief	Draw 3D text.
     *
     * \author	Ogre Wiki
     * \date	31/10/2013
     *
     * \param	location  	The location.
     * \param	textString	The text string.
     */

    virtual void     draw3dText (const btVector3 &location, const char *textString);

    /**
     * \fn	virtual void OgreDebugDrawer::setDebugMode (int debugMode);
     *
     * \brief	Sets debug mode.
     *
     * \author	Ogre Wiki
     * \date	31/10/2013
     *
     * \param	debugMode	The debug mode.
     */

    virtual void     setDebugMode (int debugMode);

    /**
     * \fn	virtual int OgreDebugDrawer::getDebugMode () const;
     *
     * \brief	Gets debug mode.
     *
     * \author	Ogre Wiki
     * \date	31/10/2013
     *
     * \return	The debug mode.
     */

    virtual int     getDebugMode () const;
protected:

    /**
     * \fn	bool OgreDebugDrawer::frameStarted(const Ogre::FrameEvent& evt);
     *
     * \brief	Frame started.
     *
     * \author	Ogre Wiki
     * \date	31/10/2013
     *
     * \param	evt	The event.
     *
     * \return	true if it succeeds, false if it fails.
     */

    bool frameStarted(const Ogre::FrameEvent& evt);

    /**
     * \fn	bool OgreDebugDrawer::frameEnded(const Ogre::FrameEvent& evt);
     *
     * \brief	Frame ended.
     *
     * \author	Ogre Wiki
     * \date	31/10/2013
     *
     * \param	evt	The event.
     *
     * \return	true if it succeeds, false if it fails.
     */

    bool frameEnded(const Ogre::FrameEvent& evt);
private:

    /**
     * \struct	ContactPoint
     *
     * \brief	Contact point.
     *
     * \author	Ogre Wiki
     * \date	31/10/2013
     */

    struct ContactPoint{

        /**
         * \brief	Source for the.
         */

        Ogre::Vector3 from;
        Ogre::Vector3 to;

        /**
         * \brief	The color.
         */

        Ogre::ColourValue   color;
        size_t        dieTime;
    };

    /**
     * \brief	The debug modes.
     */

    DebugDrawModes               mDebugModes;

    /**
     * \brief	The lines.
     */

    Ogre::ManualObject          *mLines;

    /**
     * \brief	The triangles.
     */

    Ogre::ManualObject          *mTriangles;

    /**
     * \brief	The contact points.
     */

    std::vector< ContactPoint > *mContactPoints;

    /**
     * \brief	The first m contact points.
     */

    std::vector< ContactPoint >  mContactPoints1;

    /**
     * \brief	The second m contact points.
     */

    std::vector< ContactPoint >  mContactPoints2;
};
 
#endif // DebugDrawer_h__