#include "stdafx.h"
#include "NodeContainerSingleton.h"
#include "Vector3.h"

NodeContainerSingleton* NodeContainerSingleton::Instance()
{
	static NodeContainerSingleton instance;

	return &instance;
}

void NodeContainerSingleton::BuildMap()
{
	Hallway.push_back(new MapNode(1, Ogre::Vector3(1,0,0)));
	Hallway.push_back(new MapNode(2, Ogre::Vector3(2,0,0)));
	Hallway.push_back(new MapNode(3, Ogre::Vector3(2,0,1)));
	Hallway.push_back(new MapNode(4, Ogre::Vector3(1,0,-1)));
	Hallway[0]->Partners.push_back(Hallway[1]);
	Hallway[1]->Partners.push_back(Hallway[0]);
	Hallway[1]->Partners.push_back(Hallway[2]);
	Hallway[1]->Partners.push_back(Hallway[3]);
	Hallway[2]->Partners.push_back(Hallway[1]);
	Hallway[3]->Partners.push_back(Hallway[1]);
	
}


MapNode* NodeContainerSingleton::FindNearestNode(Ogre::Vector3 pos)
{
	float min = 100000;

	
	cout<<"Position = "<<pos.x<<pos.y<<pos.z<<"\n";
	//if(1)//between this range)
	//{
		for(int i = 0; i< Hallway.size(); i++)
		{
			DisVec.x = pos.x - Hallway[i]->GetLocation().x;
			DisVec.y = pos.y - Hallway[i]->GetLocation().y;
			DisVec.z = pos.z - Hallway[i]->GetLocation().z;
			Distance = ((DisVec.x * DisVec.x) + (DisVec.y * DisVec.y) + (DisVec.z * DisVec.z));
			if(Distance < min)
			{
				min = Distance;
				TempNode = Hallway[i];
			}
		}

	//}
	/*else if(1)//between next range)
	{
		for(int i = 0; i<CommonRoom.size(); i++)
		{
			DisVec.x = pos.x - CommonRoom[i]->GetLocation().x;
			DisVec.y = pos.y - CommonRoom[i]->GetLocation().y;
			DisVec.z = pos.z - CommonRoom[i]->GetLocation().z;
			Distance = ((DisVec.x * DisVec.x) + (DisVec.y * DisVec.y) + (DisVec.z * DisVec.z));
			if(Distance < min)
			{
				min = Distance;
				TempNode = CommonRoom[i];
			}
		}
	}
	else if(1)//between last range)
	{
		for(int i = 0; i<ItRoom.size(); i++)
		{
			DisVec.x = pos.x - ItRoom[i]->GetLocation().x;
			DisVec.y = pos.y - ItRoom[i]->GetLocation().y;
			DisVec.z = pos.z - ItRoom[i]->GetLocation().z;
			Distance = ((DisVec.x * DisVec.x) + (DisVec.y * DisVec.y) + (DisVec.z * DisVec.z));
			if(Distance < min)
			{
				min = Distance;
				TempNode = ItRoom[i];
			}
		}
	}
	else//check all
	{
		for(int i = 0; i< Hallway.size(); i++)
		{
			DisVec.x = pos.x - Hallway[i]->GetLocation().x;
			DisVec.y = pos.y - Hallway[i]->GetLocation().y;
			DisVec.z = pos.z - Hallway[i]->GetLocation().z;
			Distance = ((DisVec.x * DisVec.x) + (DisVec.y * DisVec.y) + (DisVec.z * DisVec.z));
			if(Distance < min)
			{
				min = Distance;
				TempNode = Hallway[i];
			}
		}
		for(int i = 0; i<CommonRoom.size(); i++)
		{
			DisVec.x = pos.x - CommonRoom[i]->GetLocation().x;
			DisVec.y = pos.y - CommonRoom[i]->GetLocation().y;
			DisVec.z = pos.z - CommonRoom[i]->GetLocation().z;
			Distance = ((DisVec.x * DisVec.x) + (DisVec.y * DisVec.y) + (DisVec.z * DisVec.z));
			if(Distance < min)
			{
				min = Distance;
				TempNode = CommonRoom[i];
			}
		}
		for(int i = 0; i<ItRoom.size(); i++)
		{
			DisVec.x = pos.x - ItRoom[i]->GetLocation().x;
			DisVec.y = pos.y - ItRoom[i]->GetLocation().y;
			DisVec.z = pos.z - ItRoom[i]->GetLocation().z;
			Distance = ((DisVec.x * DisVec.x) + (DisVec.y * DisVec.y) + (DisVec.z * DisVec.z));
			if(Distance < min)
			{
				min = Distance;
				TempNode = ItRoom[i];
			}
		}
	}*/
	cout<<"Temp node id = "<<TempNode->GetId()<<"\n";
	return TempNode;
}