#include "Grue.h"
#include "Room.h"

//public:
bool Grue::act()//moves grue
{
	// cout<<"GRUE MOVING"<<endl;
	int i (0);//index for exits
	//create vector to list exits
	vector <string> options;

	// cout<<"new vector was created"<<endl;

	map<string,Room*> gruePaths = getCurrent()->getExits();

	//create iterator
	map<string,Room*>::iterator gr;
	// cout<<"iterator was created"<<endl;

	//run through all exits and push into vector
	for (gr = gruePaths.begin(); gr != gruePaths.end(); ++gr)
	{
		options.push_back(gr->first);
		i++;
	}

	// int dd = 0;

	// while(dd < i)
	// {
	// 	cout<<"grue can move to the "<<options[dd]<<"."<<endl;
	// 	dd++;
	// }


	// cout<<"successfully listed grue movement options"<<endl;

	//create random number 
	int a = rand() % (i+1);

	// cout<<"got random movement"<<endl;

	if (a == i)
	{
		//cout<<"Grue is staying"<<endl;
		return true;
	}
	else
	{
		//decide on the room to enter
		string newRoom = options[a];
		cout<<"You hear noises. It might be a monster!"<<endl;


		//attempt walking into new room
		if (walk(newRoom))
		{
			// cout<<"Grue is in "<<newRoom<<"."<<endl;
			return(true);
		}
	}

	return (false);
}



Grue::Grue(string _name, string _description):Agent(_name,_description,5)//create grue with name
{

}


bool Grue::moveTo(Room * r)//moves thing to new room
{



	//if thing can be added to new room
	if (r->enter(this))
	{
		setCurrent(r);//make new room the grue's current room
		return (true);
	}

	return (false);
}




