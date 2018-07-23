#include <iostream>
#include "dungeon.h"
#include <string>
//may put in sep func
#include "character/playerRace/drow.h"
#include "character/playerRace/goblin.h"
#include "character/playerRace/troll.h"
#include "character/playerRace/vampire.h"
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
	td = nullptr;
	nextFloor();
		
	
	
	
}

void Dungeon::play(){
	
	int i = 0;
	
	int moveTile;
	string cmd = "";
	
	
	system("clear");
	
	while(cmd != "q"){
		currentFloor->refresh();
		currentFloor->print();
		player->printStats();
		
		cout<<"command: ";
		cin>>cmd;
		
	//	if(cmd == 'b'){
//			currentFloor->bloom();
			
		//}
		
		if(cmd == "m"){
			cin>>cmd;
			
			player->move(cmd);
			
			Coordinate curCoord = player->getPos();
			cout<<curCoord.X<<" "<<curCoord.Y<<endl;
		}
		else if(cmd == "n") nextFloor();
		
		currentFloor->reactEnemies(player);
//		player->getCell()->notifyEnemies();
		moveEnemies();
			
//		system("clear");
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
	Coordinate *tmpCoord = tmp->getPosPtr();
	
	//want this line out###########################################################################################################################################
	player = new Drow(*tmpCoord, *tmp);
	tmp->setCharacterHere(player);
	
	//player->notifyObservers();

	nextFloorLoc = currentFloor->genNextFloorLoc();
	
	currentFloor->genFloor();
	
	
	++level;
}

void Dungeon::victory(){
	system("clear");
	
	cout<<"YAY YOU WON OR SOMETHING"<<endl;
	//cout<<player->get
}

void Dungeon::reset(){
	
}

void Dungeon::moveChar(Direction dir){
	
}

void Dungeon::usePot(Direction dir){
	
}

void Dungeon::attack(Direction dir){
	
}

void Dungeon::magic(Direction dir){
	
}
