#include "Thing.h"
#include "Room.h"

//public:
//constructor
Thing::Thing(string _name, string _description, int _size)//creates thing w/set values
{
	name = _name;
	description = _description;
	size = _size;
}

//returns current room of thing
Room * Thing::getCurrent()
{

	return (current);
}

bool Thing::moveTo(Room * r)//moves thing to new room
{

	//cout<<endl<<"about to move the "<<this->getName()<<endl;

	//if thing can be added to new room
	if (r->add(this))
	{
		//cout<<"sup"<<endl;
		if(current!=NULL)
		{
			current->remove(this);
		}
		current = r;
		//cout<<"moved"<<endl;
		return (true);
	}

	return (false);
}

string Thing::getName()//returns thing's name
{

	return (name);
}

string Thing::getDesc()//returns thing's description
{

	return (description);
}

int Thing::getSize()//returns thing's size
{

	return (size);
}

void Thing::setCurrent(Room * r)//set current room
{

	current = r;
}







