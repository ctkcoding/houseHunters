#include <cstdlib>
#include <typeinfo>
#include "Game.h"

//game constructor
Game::Game()
{
	//initialize Grue movement number
	srand(time(NULL));
}

//adds agent to the list of agents playing game
void Game::addAgent(Agent * a)
{
	//add agent to game's vector
	agents.push_back(a);
}

//runs through the agents vector of the game
bool Game::step()
{
	bool death = false;

	bool boolio (false);//initialize return bool as false
	int i (0);//agents index
	// cout<<"This is agent "<<i + 1<<" of "<<agents.size()<<"."<<endl;
	while (i< agents.size())
	{
		if (death)
		{
			break;
		}

		//turn list of occupants into new set
		// set <Agent*> fellows = agents[i]->getCurrent()->peeps();
		// set <Agent*>::iterator it;

		//if act method does not execute properly or user quits
		if (!agents[i]->act())
		{
			//quit out with false return
			//cout<<"quit function worked correctly."<<endl;
			// cout<<"step malfunctioned"<<endl;
			break;
		}
		else
		{
			// cout<<"action successful!"<<endl;
			set <Agent*> fellows = agents[i]->getCurrent()->peeps();
			set <Agent*>::iterator it;

			if ((fellows.size() >=2) && (agents[i]->getSize() != 5))
			{
				//cout<<"you have company"<<endl;
				//runs through all thingsin room
				for (it=fellows.begin(); it!=fellows.end(); ++it)
				{
					//if agent is player and any other agent in room is a grue
					if ((*it)->getSize() == 5)
					{
						cout<<"Oh no! You encountered a monster!"<<endl;
						Agent * a = agents[i];//move player into agent
						Agent * b = (*it);//move grue into agent

						//cout<<"created agents"<<endl;

						int c = 0;
						// set<Agent*>::iterator aa;
						// for (aa=fellows.begin(); aa!=fellows.end(); ++aa)
						// {
						// 	if ((*aa)->getSize() == 5)
						// 	{
						// 		c++;
						// 	}
						// }

						// cout<<"You see "<< (c -1) <<" other Grues in the room"<<endl;

						if (!defense(a,b,c))
						{
							//cout<<"you got eaten by the Grue"<<endl;
							death = true;
							cout<<"The game is over, you are dead."<<endl;
							cout<<"My condolences."<<endl<<endl;
						}
						else
						{
							cout<<"You killed the monster!"<<endl;
							boolio = true;
						}
					}

					if(it==(agents[i]->getCurrent()->peeps()).end())
					{
						//something went really bad if this happens, but just in case
						cout<<"DANGER WILL ROBINSON"<<endl;
						break;
					}

					//cout<<"This guy was harmless"<<endl;
				}
			}

			i++;
			//otherwise, increment and continue searching for grues in the room
			boolio = true;
		}
	}

	if (death)
	{
		boolio = false;
	}

	return(boolio);
}

//if player and grue in same room
bool Game::defense(Agent * p, Agent * g, int c)
{
	//cout<<"defense program running"<<endl;
	bool knife = false;
	bool pistol = false;
	bool bat = false;
	bool rifle = false;

	//check the player's mythings vector for a defense object
	int k (0);//index players objects
	while ( k < (p->getThings()).size() )
	{
		if (((p->getThings())[k]->getName() == "knife") || ((p->getThings())[k]->getName() == "pistol") || ((p->getThings())[k]->getName() == "bat") || ((p->getThings())[k]->getName() == "rifle"))
		{
			if((p->getThings())[k]->getName() == "knife")
			{
				knife = true;
			}
			if((p->getThings())[k]->getName() == "bat")
			{
				bat = true;
			}
			if((p->getThings())[k]->getName() == "pistol")
			{
				pistol = true;
			}
			if((p->getThings())[k]->getName() == "rifle")
			{
				rifle = true;
			}

		}
		k++;
	}
	if (bat || knife || pistol || rifle)
	{
		//create integer for threshold of odds to kill grue
		int thresh = 5;
		//assign each weapon a number of thresh
		if (rifle)
			thresh = 0;
		else if (pistol)
			thresh = 2;
		else if (knife)
			thresh = 3;
		else if (bat)
			thresh = 4;
		int odds = rand () %11;


		//thresh increases as more grues appear
		thresh = thresh + (c * 2 / 3);

		//thresh increases as room size decreases
		thresh = thresh * 30 / (p->getCurrent()->getSize());

		if (odds > thresh)
		{
			//remove grue from people in that room
			(p->getCurrent())->leave(g);
			// cout<<"removed grue from game"<<endl;

			//remove grue from players' list
			int bb (0);//index agents
			while (bb < agents.size())
			{
				//ignore listed object if it is the specified ingored object
				if (agents[bb] == g)
				{
					//move object to end of vector, delete it
					agents.erase(remove(agents.begin(), agents.end(), g), agents.end());
				}
				bb++;
			}

			//nothing happens to player
			return (true);
		}
	}
	else
	{
		set <Thing*> roomThings = p->getCurrent()->getThings();
		set <Thing*>::iterator ii;//iterate through things
		for (ii = roomThings.begin(); ii != roomThings.end(); ++ii)
		{
			if (((*ii)->getName() == "knife") || ((*ii)->getName() == "pistol") || ((*ii)->getName() == "bat") || ((*ii)->getName() == "rifle"))
			{

				bool knife = false;
				bool pistol = false;
				bool bat = false;
				bool rifle = false;
				if((p->getThings())[k]->getName() == "knife")
				{
					knife = true;
				}
				if((p->getThings())[k]->getName() == "bat")
				{
					bat = true;
				}
				if((p->getThings())[k]->getName() == "pistol")
				{
					pistol = true;
				}
				if((p->getThings())[k]->getName() == "rifle")
				{
					rifle = true;
				}
			}
		}
		//create integer for threshold of odds to kill grue
		int thresh = 5;
		//assign each weapon a number of thresh
		if (rifle)
			thresh = 0;
		else if (pistol)
			thresh = 2;
		else if (knife)
			thresh = 3;
		else if (bat)
			thresh = 4;
		int odds = rand () %11;

		//thresh increases as more grues appear
		thresh = thresh + (c * 2 / 3);

		//thresh increases as room size decreases
		thresh = thresh * 30 / (p->getCurrent()->getSize());

		if (odds > thresh)
		{
			//remove grue from people in that room
			(p->getCurrent())->leave(g);
			// cout<<"removed grue from game"<<endl;

			//remove grue from players' list
			int bb (0);//index agents
			while (bb < agents.size())
			{
				//ignore listed object if it is the specified ingored object
				if (agents[bb] == g)
				{
					//move object to end of vector, delete it
					agents.erase(remove(agents.begin(), agents.end(), g), agents.end());
				}
				bb++;
			}

			//nothing happens to player
			return (true);
		}
		else if (p->getCurrent()->getSize() >= 30)
		{
			if(p->escape())
			{
				return(true);
			}
		
		}
	}
	
	cout<<"The monster ate you."<<endl;
	return (false);
}

//check if agents are empty
bool Game::noAgents()
{
	if (agents.size() == 1)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}




