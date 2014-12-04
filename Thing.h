//class declaration

#ifndef THING_H
#define THING_H

#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Room;

class Game;


class Thing
{
	public:
		Thing(string _name, string _description, int _size);//creates thing w/set values
		virtual bool moveTo(Room * r);//moves thing to new room
		string getName();//returns thing's name
		string getDesc();//returns thing's description
		int getSize();//returns thing's size
		Room * getCurrent();//returns current room
		void setCurrent(Room * r);//set current room
	protected:
		Room * current;//where the thing is
	private:
		string name;//thing's name
		string description;//thing's description
		int size;//thing's size
};
#endif