//class declaration

#ifndef GAME_H
#define GAME_H

#include "Grue.h"
#include "Player.h"
#include "Room.h"
#include <set>
#include <typeinfo>


class Player;
class Grue;
class Thing;
class Agent;

class Game
{
	public:
		Game();//game constructor
		void addAgent(Agent * agent);//adds to list of agents
		bool step();//runs through agents calling their act functions
		bool defense(Agent * p, Agent * g, int c);//if player and grue in same room
		bool noAgents();//check if agents are empty
	protected:
		vector <Agent *> agents;//vector of agents
};
#endif