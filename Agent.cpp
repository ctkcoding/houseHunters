#include "Agent.h"
#include "Room.h"

//protected:
//constructor for agent
Agent::Agent (string _name, string _description, int _size):Thing(_name, _description, _size)
{

}

//moves agent from room to room
bool Agent::walk(string exit)
{

	bool things = false;//initialize boolean for return
	//add player to new room's occupants list
	// cout<<"bout 2 walk the agent"<<endl;
	if((getCurrent()->getLinked(exit))->enter(this))
	{
		//if that works, remove player from current room
		getCurrent()->leave(this);
		setCurrent((getCurrent()->getLinked(exit)));//set new current room
		// cout<<endl<<"walking agent into a new room"<<endl;
		// cout<<"grue is moved into "<<getCurrent()->getName()<<"."<<endl;
		things = true;//set the 
	}

	// cout<<"ending grue's walk, returning ";
	// if (things)
	// {
	// 	cout<<"true"<<endl;
	// }
	// else
	// {
	// 	cout<<"false"<<endl;
	// }

	// cout<<"end walk"<<endl;

	return (things);
}

//moves agent to initial room
bool Agent::moveTo(Room * r)
{

	//if thing not already in room and can be added to new room
	if ((current == NULL) && (r->enter(this)))
	{
		current = r;
		return (true);
	}

	return (false);
}

//placeholder
vector <Thing*> Agent::getThings()
{
	vector <Thing*> a;
	return (a);
}

bool Agent::escape()//moves grue
{

	int i (0);//index for exits
	//create vector to list exits
	vector <string> options;

	// cout<<"new vector was created"<<endl;

	map<string,Room*> escapes = getCurrent()->getExits();

	//create iterator
	map<string,Room*>::iterator rm;

	// cout<<"iterator was created"<<endl;

	//run through all exits and push into vector
	for (rm = escapes.begin(); rm != escapes.end(); ++rm)
	{
		options.push_back(rm->first);
		i++;
	}

	//create random number 
	int a = rand() % (i);
	
	//decide on the room to enter
	string newRoom = options[a];
	if (getSize() != 5)
	{
		cout<<"You escaped to "<<newRoom<<endl;
	}
	
	//attempt walking into new room
	if (walk(newRoom))
	{
		return(true);
	}

	return (false);
}