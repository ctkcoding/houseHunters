#include "Room.h"

//constructs a room to parameters
Room::Room(string _name, string _description, int _size)
{
	name = _name;
	description = _description;
	size = _size;
}

//retrieves name
string Room::getName()
{

	return (name);
}

//retrieves description
string Room::getDescription()
{

	return(description);
}

//links an exit to a room
void Room::link(string direction, Room * r)
{
	//sets link between exit and room pointer
	exits[direction] = r;
}

//returns the pointer (used to switch rooms)
Room * Room::getLinked(string direction)
{

	return(exits[direction]);
}

//prints all rooms linked to current room
void Room::printLinked()
{
	//iterates through all linked rooms
	map<string, Room*>::iterator dx;
	
	int n = exits.size();//counts number of exits

	int i (0);//index of exits
	
	cout<<"There is an exit to the ";
	
	for (dx = exits.begin(); dx!= exits.end(); ++dx)
	{
		//print out the direction and where it leads
		cout<<dx->first<<" ("<<dx->second->name<<")";
		i++;
		
		//print something between list items
		if (i<(n))
		{
			//if more than 2 exits, use commas between exits
			if ((n > 2) && (i < (n-1)))
				{
					cout<<", ";
				}
			//if n = 2, then ignore the comma
			else
			{
				cout<<" and ";
			}
		}
	}
			
	//print a period at the end of the list 		
	cout<<"."<<endl;
}

//prints all occupants of room
void Room::printPeeps(Agent * ignore)
{
	set<Agent*>::iterator qq;//iterator for occupants set
	int i (0);//index set for punctuation
	cout<<"You see ";
	for (qq=occupants.begin(); qq!=occupants.end(); ++qq)
	{
		//ignore listed object if it is the specified ingored object
		if ((*qq)->getName() != ignore->getName())
		{
			//print the object and what it does
			cout<<(*qq)->getName()<<" ("<<(*qq)->getDesc()<<")";
			i = 1 + i;
			//print something between list items
			if ((i + 1)<(occupants.size()))
			{
				//if more than 2 exits, use commas between exits
				if (occupants.size() > 2)
				{
					cout<<", ";
				}
				//if n = 2, then ignore the comma
				else
				{
					cout<<" and";
				}
			}
		}
	}
	if (i<1)
	{
		cout<<"nobody else";
	}
	//period at the end of the list
	cout<<"."<<endl;
}

//prints all items but specified ignored thing
void Room::printThings()
{
	int i(0);//index for things
	int n = things.size();//number of objects in room
	cout<<"In the room you find";

	set<Thing*>::iterator cc;//iterator for list of things
	for (cc = things.begin(); cc!= things.end(); ++cc)
	{
		//print the object and what it does
		cout<<" a "<<(*cc)->getName()<<" that "<<(*cc)->getDesc();
		i++;

		//print something between list items
		if (i<(n))
		{
			//if more than 2 exits, use commas between exits
			if (n > 2)
			{
				cout<<", ";
			}
			//if n = 2, then ignore the comma
			else
			{
				cout<<" and";
			}
		}
	}
	if (i==0)
	{
		cout<<" nothing you can take with you";
	}
	
	//period at the end of the list
	cout<<"."<<endl;
}

//adds thing to room
bool Room::add(Thing * thing)
{
	//tries adding to the room
	things.insert(thing);
	return(true);
}

//removes thing from room
void Room::remove(Thing * thing)
{

	things.erase(thing);
}

//leave the room
void Room::leave(Agent * a)
{
	//remove self from occupants list
	occupants.erase(a);
}

//enter a new room
bool Room::enter(Agent * a)
{
	// cout<<a->getName()<<" is entering a new room"<<endl;

	//check if room is locked
	if (checkLock() && (a->getSize() != 5))
	{	
		bool open = false;
		cout<<"The room is locked,";
		//look for the key in player's things
		int k (0);//index players objects
		while ( k < (a->getThings()).size() )
		{
			if ((a->getThings())[k]->getName() == "key")
				{
					//unlock the room
					cout<<" but you had a key and unlocked the room."<<endl;
					locked(0);

					//enter the room
					open = true;
				}
			k++;
		}

		if (open)
		{
			enter (a);
			return (true);
		}
		else
		{
			cout<<" you need to go find the key."<<endl;
			return(false);
		}
	}
	else
	{
		//add self to occupants and continue
		occupants.insert(a);
				
		return (true);
	}


}

//locks or unlocks room
void Room::locked(int a)
{
	if (a)
	{
		lock = true;
	}
	else
	{
		lock = false;
	}
}

//checks the lock
bool Room::checkLock()
{

	return(lock);
}

//returns occupants list
set <Agent*> Room::peeps()
{

	return(occupants);
}

//returns list of things
set <Thing*> Room::getThings()
{

	return(things);
}

//returns list of exits
map <string,Room *> Room::getExits()
{

	return(exits);
}

//returns size of room
int Room::getSize()
{

	return(size);
}






