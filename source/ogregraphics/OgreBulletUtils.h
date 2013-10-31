
#include "CollisionWorldSingleton.h"

/**
 * \fn	inline btVector3 cvt(const Ogre::Vector3 &V)
 *
 * \brief	Cvts the given v.
 *
 * \author	Functions taken from Ogre Wiki
 * \date	31/10/2013
 *
 * \param	V	The const Ogre::Vector3 &amp; to process.
 *
 * \return	.
 */

inline btVector3 cvt(const Ogre::Vector3 &V){
    return btVector3(V.x, V.y, V.z);
}

/**
 * \fn	inline Ogre::Vector3 cvt(const btVector3&V)
 *
 * \brief	Cvts the given v.
 *
 * \author	Functions taken from Ogre Wiki
 * \date	31/10/2013
 *
 * \param	V	The const btVector3&amp; to process.
 *
 * \return	.
 */

inline Ogre::Vector3 cvt(const btVector3&V){
    return Ogre::Vector3(V.x(), V.y(), V.z());
}

/**
 * \fn	inline btQuaternion cvt(const Ogre::Quaternion &Q)
 *
 * \brief	Cvts the given q.
 *
 * \author	Functions taken from Ogre Wiki
 * \date	31/10/2013
 *
 * \param	Q	The const Ogre::Quaternion &amp; to process.
 *
 * \return	.
 */

inline btQuaternion cvt(const Ogre::Quaternion &Q)
{
    return btQuaternion(Q.x, Q.y, Q.z, Q.w);
};

/**
 * \fn	inline Ogre::Quaternion cvt(const btQuaternion &Q)
 *
 * \brief	Cvts the given q.
 *
 * \author	Functions taken from Ogre Wiki
 * \date	31/10/2013
 *
 * \param	Q	The const btQuaternion &amp; to process.
 *
 * \return	.
 */

inline Ogre::Quaternion cvt(const btQuaternion &Q)
{
    return Ogre::Quaternion(Q.w(), Q.x(), Q.y(), Q.z());

/**
// End of OgreBulletUtils.h
 */

};