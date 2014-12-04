#include "Player.h"
#include "Room.h"
#include <set>

//public:
Player::Player(string _name, string _description, int _size):Agent(_name,_description,_size)
{

	
}

bool Player::act()//move rooms or take object
{
	//print out the room and description
	cout<<"You find yourself in the "<<current->getName()<<", "<<current->getDescription()<<endl;

	//print out exits and their rooms
	current->printLinked();

	//print out objects in your room
	current->printThings();


	//print people in the room
	current->printPeeps(this);


	//alert user if there are grues in adjacent rooms
	//count grues in nearby rooms
	int gCount = 0;

	//create list of nearby rooms
	map <string,Room*> gCheck = current->getExits();

	//iterate through nearby rooms
	map <string,Room*> :: iterator gc;
	for (gc = gCheck.begin(); gc != gCheck.end(); ++gc)
	{
		//create list of agents in each adjacent room
		set <Agent*> friends = (current->getLinked(gc->first))->peeps();

		//iterate through room's agents
		set <Agent*>::iterator gm;

		if (friends.size() > 0)
		{
			//iterator for loop
			for (gm=friends.begin(); gm!=friends.end(); ++gm)
			{
				//alert user to grue presence
				if ((*gm)->getSize() == 5)
				{
					if (gCount == 0)
					{
						cout<<"You can see a monster in an adjacent room."<<endl;
					}

					if (gCount > 0)
					{
						cout<<"You can see another monster in an adjacent room."<<endl;
					}

					//incrment number of nearby grues
					gCount++;
				}
			}
		}
	}

	bool things (0);//

	//take input
	string dir;
	cout<<"Do you want to move in a direction or take an item from the room?"<<endl;
	cin>>dir;
	if (dir == "move")
	{

		map <string,Room*> eList = current->getExits();

		//iterator to run through
		map <string,Room*> :: iterator ia;

		bool realDoor = false;

		//do-while makes sure user inputs a real exit
		do
		{
			//ask user for input
			cout<<"Where do you want to go?"<<endl;
			cin>>dir;

			for (ia = eList.begin(); ia != eList.end(); ++ia)
			{
				if (dir == (ia->first))
				{
					realDoor = true;
					break;
				}
			}
		}
		while (!realDoor);


		if(walk(dir))
		{
			things = true;
		}


	}
	else if (dir == "take")
	{
		if(take())
		{
			things = true;
		}
		else
		{
			act();
		}

	}
	else if (dir == "help")
	{
		help();
		if(act())
		{
			things = true;
		}

	}
	else if (dir == "pockets")
	{
		if (pockets())
		{
			if(act())
			things = true;
		}

	}
	else if (dir == "quit")
	{
		things = false;
		cout<<"Goodye. Thank you for playing."<<endl;
	}
	else if (dir == "wait")
	{
		things = true;
		cout<<"Better breathe quietly and hope the monsters don't get you!"<<endl;
	}
	else
	{
		cout<<endl<<"That was an invalid input. Here is some helpful advice:"<<endl;
		help();
		if(act())
		{
			things = true;
		}
		else
		{
			//cout<<"You might want to try that again."<<endl;
		}
	}

	cout<<endl;

	return (things);

}

bool Player::take()//takes object in room
{
	int pSize = 5;
	//ask user for input
	string o;
	cout<<"What object do you want to take?"<<endl;
	//take user input
	cin>>o;
	bool grab = false;//bool for if taking works or not
	
	//iterate through all objects
	set<Thing*>::iterator it;
	for (it = (current->getThings()).begin(); it!= (current->getThings()).end(); ++it)
	{
		//check if object is what user wants
		if(((*it)->getName()) == o)
		{
			//add object to user's things
			myThings.push_back(*it);

			//remove object from room list
			current->remove(*it);
			grab = true;
			break;
		}
	}

	if (grab)
	{
		cout<<endl<<"You took the "<<o<<" from the room."<<endl;
		return true;
	}
	else
	{
		cout<<endl<<"There is no "<<o<<" in this room"<<endl;
		return true;
	}
}

//checks users pockets
bool Player::pockets()
{

	if (myThings.size() == 0)
	{
		cout<<"Your pockets are empty."<<endl;
	}
	else
	{
		int i (0);//indexes pockets array
		cout<<"You have:"<<endl;
		while (i < myThings.size())
		{
			cout<<myThings[i]->getName()<<endl;
			i++;
		}
	}

	string c = " ";
	do
	{
		cout<<"Press c to continue"<<endl;
		cin>>c;
	}
	while(c!="c");


	return true;
}

void Player::help()//prints help/info message
{
	cout<<endl<<endl<<endl;
	cout<<"You are always in a room."<<endl;
	cout<<"Rooms adjacent to yours will be listed."<<endl;
	cout<<"Some rooms may contain objects."<<endl;
	cout<<"You can take certain objects with you."<<endl;
	cout<<"To see what objects you are carrying, type pockets"<<endl;
	cout<<"You can leave your room for another by typing the direction of the other room."<<endl;
	cout<<"There are some monsters wandering around these rooms with you, make sure to stay safe."<<endl;
	cout<<"Good luck!"<<endl;
	cout<<endl<<endl;
}

//returns the list of things
vector <Thing*> Player::getThings()
{
	
	return(myThings);
}

//moves player from room to room
bool Player::walk(string exit)
{
	bool stuff = false;//holds the 
	//add player to new room's occupants list
	if((getCurrent()->getLinked(exit))->enter(this))
	{
		//if that works, remove player from current room
		getCurrent()->leave(this);
		setCurrent((getCurrent()->getLinked(exit)));//set new current room
		// cout<<endl<<"walking player into a new room"<<endl;
		stuff = true;
	}
	else
	{
		cout<<"You must be trying to get into a room that does not exist."<<endl;
		cout<<"Better luck next time"<<endl;
		stuff = true;
	}

	// cout<<"ending player's walk, returning ";
	// if (stuff)
	// {
	// 	cout<<"true"<<endl;
	// }
	// else
	// {
	// 	cout<<"false"<<endl;
	// }

	// cout<<"end walk"<<endl;

	return (stuff);
}

bool Player::moveTo(Room * r)//moves thing to new room
{



	//if thing can be added to new room
	if (r->enter(this))
	{
		setCurrent(r);//make new room the player's current room
		return (true);
	}

	return (false);
}


