//class declaration

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <set>
#include "Agent.h"
#include "Grue.h"
#include "Player.h"
using namespace std;

class Room
{
	public:

		Room(string _name, string _description, int _size);//creates room to specifications
		string getName();//returns room name
		string getDescription();//returns room description
		void link(string direction, Room * r);//link current room to room a by exit x
		Room * getLinked(string direction);//returns room in direction x
		void printLinked();//prints all linked rooms
		void printThings();//print all things in room
		void printPeeps(Agent * ignore);//print occupants of room
		bool add(Thing * thing);//adds thing to room
		void remove(Thing * thing);//removes thing from room
		bool enter(Agent * a);//enter new room
		void leave(Agent * a);//leave current room
		void locked(int a);//lock or unlock room
		bool checkLock();//return if room is locked or not
		set <Agent*> peeps();//list of people in room
		map <string,Room*> getExits();//returns list of exits for Grue navigation
		set <Thing*> getThings();//returns list of things in room
		int getSize();//returns size of room



	private:
		bool lock;//true if room locked, false if open
		string name;//name of room
		string description;//description of room
		int size;//size of room
		map <string, Room*> exits;//list exits from room
		set <Thing*> things;//list of things in room
		set <Agent*> occupants;//list of people in room


};
#endif