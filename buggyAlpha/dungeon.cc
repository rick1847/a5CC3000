#include <iostream>
#include "dungeon.h"
#include <string>
//may put in sep func
#include "character/playerRace/drow.h"
#include "character/playerRace/goblin.h"
#include "character/playerRace/troll.h"
#include "character/playerRace/vampire.h"


using namespace std;

bool topWallBottomWall(const string & a){
	int i = 1;
	int end = a.size();
	
	if(a[0] != '|') return false;
	if(a[end - 1] != '|') return false;
	
	while(i < end - 1){
		if(a[i] != '-'){
			return false;
		}
		++i;
	}
	
	return true;
}

Dungeon::Dungeon(ifstream &mapFile, bool whatGen):randGen{whatGen}{
	string floorLine;
	int i = 0;
	
	//load a map File in
	while(getline(mapFile, floorLine)){
		
		if(topWallBottomWall(floorLine)){
			FloorMaps.emplace_back(vector<string>());
			FloorMaps.at(i).emplace_back(floorLine);
			
			getline(mapFile, floorLine);
			
			int j = 1;
			while(!topWallBottomWall(floorLine)){
				FloorMaps.at(i).emplace_back(floorLine);
				getline(mapFile, floorLine);
				
				++j;
				
				
			}
		
			FloorMaps.at(i).emplace_back(floorLine);
			
			++i;
		}
		
	}
	/*
	for(auto floor: FloorMaps){
		for(auto j : floor){
			cout<<j<<endl;
		}
	}*/
	level = 0;
	td = new TextDisplay(FloorMaps.at(level));
	
	currentFloor = new Floor(FloorMaps.at(level), td, randGen);
	
	
	//for now just use drow
	Cell* tmp = currentFloor->genPlayerLoc();
	Coordinate *tmpCoord = tmp->getPos();
	//want this line out###########################################################################################################################################
	player = new Drow(*tmpCoord, *tmp);
	tmp->setCharacter(player);
	
	nextFloorLoc = currentFloor->genStairCase();
	
	currentFloor->genFloor();
	
	
	++level;
	
}

//determines if the cmd was a direction
bool isDirection(string cmd){
	return cmd == "no" ||cmd == "so" || cmd == "ea" || cmd == "we" || 
			cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw";
}

void Dungeon::play(){
	string cmd = "";
	
	
	system("clear");
	
	while(cmd != "q"){
		currentFloor->refresh();
		td->print();
		player->printStats();
		
		cout<<"command: ";
		cin>>cmd;
		
		if(isDirection(cmd)){
			player->move(cmd);
			
			Coordinate curCoord = player->getPos();
			cout<<curCoord.getX()<<" "<<curCoord.getY()<<endl;
		}
		else if(cmd == "u"){//use potion
			cin>>cmd;
			
			player->usePot(cmd);
			
			Coordinate curCoord = player->getPos();
			cout<<curCoord.getX()<<" "<<curCoord.getY()<<endl;
		}
		else if(cmd == "a"){ //attack
			cin>>cmd;
			player->attackInDir(cmd);
		}
		else if(cmd == "n"){//auto next floor
			nextFloor();
			
			if(level == 5) victory();
		}
		else if(cmd == "f"){
			
		}
		else if(cmd == "r"){
			
		}
		
		currentFloor->cleanup();
		currentFloor->reactEnemies(player);
		moveEnemies();
			
		system("clear");
		
	}
}

void Dungeon::chooseChar(){
	
}


void Dungeon::moveEnemies(){
	currentFloor->moveEnemies();
}

void Dungeon::nextFloor(){
	td = new TextDisplay(FloorMaps.at(level));
	
	currentFloor = new Floor(FloorMaps.at(level), td, randGen);
	
	
	//for now just use drow
	Cell* tmp = currentFloor->genPlayerLoc();
	
	//want this line out###########################################################################################################################################
	player->setCell(tmp);
	tmp->setCharacter(player);
	
	nextFloorLoc = currentFloor->genStairCase();
	
	currentFloor->genFloor();
	
	
	++level;
}

void Dungeon::victory(){
	system("clear");
	
	cout<<"YAY YOU WON OR SOMETHING"<<endl;
	
	throw "asdf";
	//cout<<player->get
}

void Dungeon::reset(){
	
}
/*
void Dungeon::moveChar(Direction dir){
	
}

void Dungeon::usePot(Direction dir){
	
}

void Dungeon::attack(Direction dir){
	
}

void Dungeon::magic(Direction dir){
	
}
*/
