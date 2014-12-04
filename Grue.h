//class declaration

#ifndef GRUE_H
#define GRUE_H
#include "Agent.h"

class Grue: public Agent
{
	public:
		bool act();//pure virtual function, used by grue and player
		Grue(string _name, string _description);//create grue with name and description
		bool moveTo(Room * r);//moves grue to new room
};
#endif