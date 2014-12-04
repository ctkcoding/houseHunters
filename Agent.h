//class declaration

#ifndef AGENT_H
#define AGENT_H
#include "Thing.h"

class Agent: public Thing
{
	public:
		virtual bool act() = 0;//pure virtual function, used by grue and player
		bool moveTo(Room * r);//moves agent to a room
		virtual vector <Thing*> getThings();//return list of things
		bool escape();//escape from room
	protected:
		Agent (string _name, string _description, int _size);//constructor for agent
		virtual bool walk(string exit);//moves agent from room to room
		bool enter(Room * r);//enter new room
		void leave();//leave current room
};
#endif