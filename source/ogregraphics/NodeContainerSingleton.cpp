#include "stdafx.h"
#include "NodeContainerSingleton.h"

NodeContainerSingleton* NodeContainerSingleton::Instance()
{
	static NodeContainerSingleton instance;

	return &instance;
}




MapNode* NodeContainerSingleton::FindNearestNode(Math::Vector3 pos)
{
	float min = 100000;

	
	
	if(1)//between this range)
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

	}
	else if(1)//between next range)
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
	}

	return TempNode;
}