//class declaration

#ifndef PLAYER_H
#define PLAYER_H
#include "Agent.h"
#include <vector>

class Player: public Agent
{
	public:
		Player (string _name, string _description, int _size);//creates player
		bool act();//move rooms or take object
		bool take();//takes object in room
		bool pockets();//prints what you're carrying
		void help();//prints help/info message
		vector <Thing*> getThings();//returns the list of things
		bool walk(string exit);//moves player from room to room
		bool moveTo(Room * r);//moves player to new room
		bool escape();//helps player escape from grue

	private:
		vector <Thing *> myThings;//list of things carried by user
};
#endif