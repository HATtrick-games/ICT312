/**
 * \file	OgreBulletDraw.h
 *
 * \brief	Declares the ogre bullet draw class.
 */

#pragma once
#include "Game.h"
#include "btBulletDynamicsCommon.h"
#include "LinearMath/btIDebugDraw.h"

/**
 * \namespace	std
 *
 * \brief	.
 */

using namespace std;

/**
 * \class	OgreBulletDraw
 *
 * \brief	Ogre bullet draw.
 *
 * \author	Arran Ford
 * \date	31/10/2013
 */

class OgreBulletDraw :public btIDebugDraw
{
	/**
	 * \brief	The debug mode.
	 */

	int m_debugMode;
public:

	/**
	 * \fn	OgreBulletDraw::OgreBulletDraw();
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 */

	OgreBulletDraw();

	/**
	 * \fn	virtual OgreBulletDraw::~OgreBulletDraw()
	 *
	 * \brief	Destructor.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 */

	virtual ~OgreBulletDraw(){};

	/**
	 * \fn	virtual void OgreBulletDraw::drawLine(const btVector3& from, const btVector3& to,
	 * 		const btVector3& fromColor, const btVector3& toColor);
	 *
	 * \brief	Draw line.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * \param	from	 	Source for the.
	 * \param	to		 	to.
	 * \param	fromColor	from color.
	 * \param	toColor  	to color.
	 */

	virtual void drawLine(const btVector3& from, const btVector3& to, const btVector3& fromColor, const btVector3& toColor);

	/**
	 * \fn	virtual void OgreBulletDraw::drawLine(const btVector3& from,const btVector3& to,
	 * 		const btVector3& color);
	 *
	 * \brief	Draw line.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * \param	from 	Source for the.
	 * \param	to   	to.
	 * \param	color	The color.
	 */

	virtual void   drawLine(const btVector3& from,const btVector3& to,const btVector3& color);

	/**
	 * \fn	virtual void OgreBulletDraw::setDebugMode(int debugMode);
	 *
	 * \brief	Sets debug mode.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * \param	debugMode	The debug mode.
	 */

	virtual void   setDebugMode(int debugMode);

    /**
     * \fn	virtual int OgreBulletDraw::getDebugMode() const
     *
     * \brief	Gets debug mode.
     *
     * \author	Arran Ford
     * \date	31/10/2013
     *
     * \return	The debug mode.
     */

    virtual int      getDebugMode() const { return m_debugMode;}

	/**
	 * \fn	virtual void OgreBulletDraw::drawContactPoint(const btVector3& PointOnB,
	 * 		const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color);
	 *
	 * \brief	Draw contact point.
	 *
	 * \author	Arran Ford
	 * \date	31/10/2013
	 *
	 * \param	PointOnB 	The point on b.
	 * \param	normalOnB	The normal on b.
	 * \param	distance 	The distance.
	 * \param	lifeTime 	Time of the life.
	 * \param	color	 	The color.
	 */

	virtual void   drawContactPoint(const btVector3& PointOnB,const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color);

    /**
     * \fn	virtual void OgreBulletDraw::reportErrorWarning(const char* warningString);
     *
     * \brief	Reports error warning.
     *
     * \author	Arran Ford
     * \date	31/10/2013
     *
     * \param	warningString	The warning string.
     */

    virtual void   reportErrorWarning(const char* warningString);

    /**
     * \fn	virtual void OgreBulletDraw::draw3dText(const btVector3& location,const char* textString);
     *
     * \brief	Draw 3D text.
     *
     * \author	Arran Ford
     * \date	31/10/2013
     *
     * \param	location  	The location.
     * \param	textString	The text string.
     */

    virtual void   draw3dText(const btVector3& location,const char* textString);

};