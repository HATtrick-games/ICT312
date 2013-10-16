#include "stdafx.h"
#include "OgreBulletDraw.h"

OgreBulletDraw::OgreBulletDraw()
:m_debugMode(0)
{
   
}

void    OgreBulletDraw::setDebugMode(int debugMode)
{
   m_debugMode = debugMode;
}

void    OgreBulletDraw::drawLine(const btVector3& from,const btVector3& to,const btVector3& fromColor, const btVector3& toColor)
{
	
//	Core::Game::getGraphics()->getDebugDrawer()->drawLine(Ogre::Vector3(from.x(),from.y(),from.z()), Ogre::Vector3(to.x(),to.y(),to.z()), Ogre::ColourValue(1,1,1));
	
}


void    OgreBulletDraw::draw3dText(const btVector3& location,const char* textString)
{
}

void    OgreBulletDraw::reportErrorWarning(const char* warningString)
{
   printf(warningString);
}

void    OgreBulletDraw::drawContactPoint(const btVector3& pointOnB,const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color)
{

}

void    OgreBulletDraw::drawLine(const btVector3& from,const btVector3& to,const btVector3& color)
{
	
 	Core::Game::getGraphics()->getDebugDrawer()->drawLine(Ogre::Vector3(from.x(),from.y(),from.z()), Ogre::Vector3(to.x(),to.y(),to.z()), Ogre::ColourValue(1,1,1));
}
