#include "stdafx.h"
#include "ItemStore.h"


ItemStore* ItemStore::Instance()
{
	static ItemStore instance;

	return &instance;
}

Objects::IObject* ItemStore::CheckVector(std::vector<Objects::IObject*> vec, Ogre::Vector3 pos, std::string affordance, int min )
{	
	
	//cout<<min<<"\n";
	int current = -1;
	for(int i = 0; i<vec.size(); i++)
		{
			//if the affordance value is greater than the min acceptable value
			if(vec[i]->GetAffodance(affordance) >= min)
			{
				//if this is not the first valid object
				if(current != -1)
				{
					if(vec[i]->getPosition().squaredDistance(pos) < vec[current]->getPosition().squaredDistance(pos))
					{
						current = i;
					}
				}
				else//if this is the first valid object set the current object index
				{
					current = i;
				}
				
			}
		}
		if(current == -1)
		{
			cout<<"Getting to here \n";
			return(NULL);
		}
		else
		{
			//cout<<"Getting to here \n";
			return vec[current];
		}

	
}

Objects::IObject* ItemStore::GetObject(Ogre::Vector3 pos, std::string affordance, int min)
{
	
	Objects::IObject* temp;
	temp = NULL;
	//return temp;
	// Ideally these if statements would contain boundaries pertaining to each of the main room areas.
	if(1)
	{
		if((temp = CheckVector(Hallway, pos, affordance, min)) ==  NULL)
		{
			if((temp = CheckVector(ItRoom, pos, affordance, min)) ==  NULL)
			{
				if((temp = CheckVector(CommonRoom, pos, affordance, min)) ==  NULL)
				{
					if((temp = CheckVector(Other, pos, affordance, min)) ==  NULL)
					{
						
					}
				}
			}
			
		}
		//temp = CheckVector(Hallway, pos, affordance, min);
		return temp;
				
	}
	else if(1)
	{
		if((temp = CheckVector(ItRoom, pos, affordance, min)) ==  NULL)
		{
			if((temp = CheckVector(Hallway, pos, affordance, min)) ==  NULL)
			{
				if((temp = CheckVector(CommonRoom, pos, affordance, min)) ==  NULL)
				{
					if((temp = CheckVector(Other, pos, affordance, min)) ==  NULL)
					{
						
					}
				}
			}
		}

		return temp;
	}
	else if(2)
	{
		if((temp = CheckVector(CommonRoom, pos, affordance, min)) ==  NULL)
		{
			if((temp = CheckVector(Hallway, pos, affordance, min)) ==  NULL)
			{
				if((temp = CheckVector(ItRoom, pos, affordance, min)) ==  NULL)
				{
					if((temp = CheckVector(Other, pos, affordance, min)) ==  NULL)
					{
						
					}
				}
			}
		}

		return temp;
	}
	else
	{
		if((temp = CheckVector(Other, pos, affordance, min)) ==  NULL)
		{
			if((temp = CheckVector(Hallway, pos, affordance, min)) ==  NULL)
			{
				if((temp = CheckVector(CommonRoom, pos, affordance, min)) ==  NULL)
				{
					if((temp = CheckVector(ItRoom, pos, affordance, min)) ==  NULL)
					{
						
					}
				}
			}
		}
		return temp;
	}



	return temp;
}

void ItemStore::AddObject(Objects::IObject* obj)
{
	//Ideally these ifs world be boundaries pertaining to each of the main room areas
	if(1)
	{
		cout<<"Object added to hallway \n";
		Hallway.push_back(obj);
	}
	else if(1)
	{
		cout<<"Object added to ItRoom \n";
		ItRoom.push_back(obj);
	}
	else if(2)
	{
		cout<<"Object added to CommonRoom \n";
		CommonRoom.push_back(obj);
	}
	else
	{
		cout<<"Object added to Other \n";
		Other.push_back(obj);
	}
	
}
