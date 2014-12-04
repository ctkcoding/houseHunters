#include "Player.h"
#include "Grue.h"
#include "Game.h"
#include "Room.h"

int main ()
{
	//cout<<"this is the "<<++debug<<"line working."<<endl;

	//initialize game
	Game newGame;//initialize game


	//set up rooms
		//room 1: dining room
		//name,description
		Room * dining = new Room ("Dining room","an ornate eating room with a large oak table with fancy settings. Plush chairs surround the table.",25);

		//room 2 : loft
		//name,description
		Room * loft = new Room ("Loft","a large area filled with bean bags and comfortable looking chairs, with a television against the north wall.",35);

		//room 3: bedroom
		//name,description
		Room * bedroom = new Room ("Bedroom","and see a large four-poster bed covered in a soft blanket. Open windows look out onto the behind the house.",40);

		//room 4: kitchen
		//name,description
		Room * kitchen = new Room ("Kitchen","the walls are covered in high-tech appliances and walnut cabinets. You wonder what the cabinets are hiding.",45);

		//room 5: entry
		//name,description
		Room * entry = new Room ("Entry","there is a large rug and a table by the front door, a wine rack on the interior side, and a hallway leading off to the south.",15);

		//room 6: living
		//name,description
		Room * living = new Room ("Living Room","the room has bookcases filled with old books and art, surrounded by a large couch and plush chairs.",25);

		//room 7: hallway
		//name,description
		Room * hallway = new Room ("Hallway","a hallway with no real furnishings, but doors to every side.",10);

		//room 8: center
		//name,description
		Room * center = new Room ("Central Area","the central area between the dining room, living room, and entry. It has no furnishings but dark wood floors, and has access to almost all of the downstairs.",10);

		//room 9: sun room
		//name,description
		Room * sun = new Room ("Sun Room","the room is filled with furniture of various bright colors and ringed with big windows showing views of the backyard and garden.",35);

		//room 10: atrium
		//name,description
		Room * atrium = new Room ("Atrium","an open-air garden with a dining table surrounded by lemon trees and ivy climbing the walls of the house.",30);

		//room 11: office
		//name,description
		Room * office = new Room ("Office","the walls are ringed with desks covered in  and stacks of documents.",35);

		//room 12: garage
		//name,description
		Room * garage = new Room ("Garage","there is a rack of bikes at the opposite end of the garage, past two cars sitting in the center of the garage, and a ping pong table just in front of you.",55);

		//room 13: sun room
		//name,description
		Room * downBath = new Room ("Bathroom","a small bathroom that has just barely crammed in a sink, toilet, and shower.",25);

		//room 14: sun room
		//name,description
		Room * smallBed = new Room ("Small Bedroom","a small room with just enough space for a bed and a dresser with a vanity mirror.",20);

		//room 15: sun room
		//name,description
		Room * masterBath = new Room ("Master Bathroom","which is large and has a glass shower, a tub, and two sinks.",35);

		//room 16: sun room
		//name,description
		Room * bigBed = new Room ("Large Bedroom","which has windows looking over the atrium and is decorated with a nautical theme.",25);

		//room 17: sun room
		//name,description
		Room * shareBath = new Room ("Shared Bathroom","with adjacent sinks below a mirror, and an attached shower.",15);

		//room 18: sun room
		//name,description
		Room * laundry = new Room ("Laundry Room","you see bright white laundry machines and cabinets. This room is quite spartan.",15);

		//room 19: sun room
		//name,description
		Room * guestBath = new Room ("Guest Bathroom","a window in the shower looks towards the sky, and the room is filled with light.",15);

		//room 20: sun room
		//name,description
		Room * guestBed = new Room ("Guest Bedroom","you see a large bed sitting next to one wall, the other is covered by a large wooden bookcase and a comfortable-looking chair.",20);

		//room 21: mCloset
		//name,description
		Room * mCloset = new Room ("Master Closet","a walk-in closet full of women's clothes and shoes.",15);

		//room 22: mHall
		//name,description
		Room * mHall = new Room ("Hallway","a hallway between the master bedroom and bathroom.",15);

		//room 23: gHall
		//name,description
		Room * gHall = new Room ("Guest Hallway","a hallway with windows towards the front of the house.",15);

		//room 24: dCloset
		//name,description
		Room * dCloset = new Room ("Master Closet","a walk-in closet full of men's clothes and shoes.",15);




	//link rooms
		//dining exits: up stairs, kitchen
		dining->link ("north", center);
		dining->link ("west", kitchen);

		//loft exits: down stairs, bedroom
		loft->link ("downstairs", center);
		loft->link ("west", bedroom);
		loft->link ("east", gHall);
		loft->link ("south", smallBed);

		//bedroom exits: loft
		bedroom->link ("east", loft);
		bedroom->link ("south", mHall);

		//kitchen exits: dining
		kitchen->link ("east", dining);
		kitchen->link ("north", sun);
		kitchen->link ("outside", atrium);

		//entry exits: hallway, living
		entry->link ("west", center);
		entry->link ("south", hallway);

		//living exits: up stairs, kitchen
		living->link ("south", center);

		//hallway exits: up stairs, kitchen
		hallway->link ("north", entry);
		hallway->link ("west", downBath);
		hallway->link ("south", office);
		hallway->link ("east", garage);

		//center exits: 
		center->link ("upstairs", loft);
		center->link ("west", sun);
		center->link ("east", entry);
		center->link ("south", dining);
		center->link ("north", living);

		//sun exits: 
		sun->link ("south", kitchen);
		sun->link ("east", center);

		//atrium exits:
		atrium->link ("inside", kitchen);
		atrium->link ("pathway", garage);

		//office exits: up stairs, kitchen
		office->link ("north", hallway);

		//garage exits:
		garage->link ("west", hallway);
		garage->link ("pathway", atrium);
		
		//downBath exits: 
		downBath->link ("east", hallway);
		
		//smallBed exits: 
		smallBed->link ("north", loft);
		smallBed->link ("east", shareBath);

		//masterBath exits: 
		masterBath->link ("north", mHall);
		
		//bigBed exits: 
		bigBed->link ("north", gHall);
		bigBed->link ("west", shareBath);
		
		//shareBath exits: 
		shareBath->link ("east", bigBed);
		shareBath->link ("west", smallBed);
		
		//laundry exits: 
		laundry->link ("east", gHall);
		
		//guestBath exits: 
		guestBath->link ("north", guestBed);
		
		//guestBed exits: 
		guestBed->link ("south", guestBath);
		guestBed->link ("west", gHall);
				
		//mCloset exits:
		mCloset->link ("east", mHall);

		//gHall exits: 
		gHall->link ("north", loft);
		gHall->link ("west", laundry);
		gHall->link ("south", bigBed);
		gHall->link ("east", guestBed);

		//mHall exits: 
		mHall->link ("north", bedroom);
		mHall->link ("south", masterBath);
		mHall->link ("east", dCloset);
		mHall->link ("west", mCloset);

		//dCloset  exits: 
		dCloset->link ("west", mHall);



	//lock bedroom
		bedroom->locked(1);


	//set up objects
		Thing * key = new Thing ("key","can be used to open a door",1);
		key->moveTo(guestBed);

		Thing * rifle = new Thing("rifle","can be used to kill monstes",2);
		rifle->moveTo(bedroom);

		// Thing * bat = new Thing("bat","can be used to beat up Grues",2);
		// bat->moveTo(garage);

		Thing * pistol = new Thing("pistol","can be used to shoot monsters",2);
		pistol->moveTo(garage);

		Thing * knife = new Thing("knife","can be used to shank monsters",1);
		knife->moveTo(kitchen);

		Thing * plate = new Thing("plate","can be used to serve food",2);
		plate->moveTo(dining);

	//set up agents
		//set up player
		Player * p = new Player("You","looks just like you",3);
		if(p->moveTo(atrium))//move player to loft
		{
			newGame.addAgent(p);//add player to list of agents
			cout<<p->getName()<<" awoke."<<endl;
		}
		cout<<"There are monsters wandering around the house with you."<<endl;
		cout<<"You must kill them all and get the rifle from the bedroom to protect yourself and secure the house."<<endl;

		//set up grue #1
		Grue * g1 = new Grue("Ben","a bald, bearded old man, throwing hundred dollar bills all over the place");
		if(g1->moveTo(downBath))//move grue to kitchen
		{
			newGame.addAgent(g1);//add grue to list of agents
			cout<<"A monster is in the maze."<<endl;
		}

		// //set up grue #2
		Grue * g2 = new Grue("Mario","an old Italian carrying a bazooka, waving it around and threatening but never firing it");
		if(g2->moveTo(loft))//move grue to kitchen
		{
			newGame.addAgent(g2);//add grue to list of agents
			cout<<"Another monster is in the maze."<<endl;
		}

		// //set up grue #3
		Grue * g3 = new Grue("Janet","a frail grandmotherly figure, carried around by a flock of doves");
		if(g3->moveTo(mHall))//move grue to kitchen
		{
			newGame.addAgent(g3);//add grue to list of agents
			cout<<"Another monster is in the maze."<<endl;
		}

		// //set up grue #4
		Grue * g4 = new Grue("Kuroda","ambling about, complaining that he's been stuck here for fifteen years");
		if(g4->moveTo(bigBed))//move grue to kitchen
		{
			newGame.addAgent(g4);//add grue to list of agents
			cout<<"Another monster is in the maze."<<endl;
		}


	cout<<"Good luck."<<endl;

	bool blair = true;//false if step function returns false
	int round (1);

	//run game
	while(blair)
	{
		cout<<endl<<"Beginning Round "<<round<<endl;
		if(newGame.step())
		{
			blair = true;//continues running game
			//cout<<"this is the "<<++debug<<"line working."<<endl;

		}
		else
		{
			blair = false;//ends game
		}

		//end game when grues are dead and bedroom is unlocked

		if (newGame.noAgents() && !(bedroom->checkLock()))
		{
    	    cout<<"You have killed every monster and secured the house."<<endl;
    	    cout<<"Congratulations. You are safe."<<endl;
    	    blair = false;
    	}

		round ++;
	}






	//int main
	return (0);
}

