#include "stdafx.h"
#include "IScene.h"

using namespace Scenes;

void IScene::update( float deltaTime )
{
	for( MapObjectsItr itr = m_objects.begin(); itr != m_objects.end(); ++itr )
	{
		itr->second->update( deltaTime );
	}
}

void IScene::addObject( std::string identifier, Objects::IObject* object )
{
	//cout<<identifier<<"\n";
	m_objects[identifier] = object;
	m_objects[identifier]->initialise();
}

void IScene::removeObject( std::string identifier )
{
	m_objects.erase( identifier );
}

Objects::IObject* IScene::getObject( std::string identifier )
{
	return m_objects[identifier];
}