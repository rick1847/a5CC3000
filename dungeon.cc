#include <iostream>
#include "dungeon.h"

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

Dungeon::Dungeon(ifstream &mapFile, bool whatGen){
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
	level = 1;
	td = new TextDisplay(FloorMaps.at(level));
	
	currentFloor = new Floor(FloorMaps.at(0), td, whatGen);
	
	
	//for now just use drow
	Cell* tmp = currentFloor->genPlayerLoc();
	Coordinate *tmpCoord = tmp->getPosPtr();
	player = new Drow(*tmpCoord, *tmp);
	tmp->setCharacterHere(player);
	
	//player->notifyObservers();

	nextFloorLoc = currentFloor->genNextFloorLoc();
	
	currentFloor->genFloor();
	
	
	
}

void Dungeon::play(){
	
	int i = 0;
	
	int moveTile;
	char cmd = 0;
	
	
	
	while(cmd != 'q'){
		currentFloor->refresh();
		currentFloor->print();
		cin>>cmd;
		
	//	if(cmd == 'b'){
//			currentFloor->bloom();
			
		//}
	/*	
		currentFloor->notifyChamber();
		currentFloor->moveEnemies();
		currentFloor->NotifyItems();
		player->notifyObservers();
		
		currentFloor->print();
		std::cout<<"("<<player->getPos().X << " "<< player->getPos().Y<<")\t";
		std::cout<<"("<<nextFloorLoc.X << " "<< nextFloorLoc.Y<<")\n";
		cout<<"nextCommand: ";
		cin>>cmd;
		
		if(cmd == 'm'){
			cin>>cmd;
			Coordinate curPos = player->getPos();
			Coordinate nextPos = player->getPos();
			
			if(cmd == 'n'){
				nextPos.X = nextPos.X - 1;
				
			}
			if(cmd == 's'){
				nextPos.X = nextPos.X + 1;
				
			}
			if(cmd == 'e'){
				nextPos.Y = nextPos.Y - 1;
				
			}
			if(cmd == 'w'){
				nextPos.Y = nextPos.Y + 1;
				
			}
			
			//std::cout<<"("<<nextPos.X << " "<< nextPos.Y<<")"<<currentFloor->ValidMove(nextPos)<<"\n";
			if(currentFloor->ValidMove(nextPos)){
				player->move(nextPos);
				
				td->notify(*player);
			}
			
			if(nextPos == nextFloorLoc){
				if(level == 5) victory();
				
				else nextFloor();
			}
			
			std::cout<<"("<<player->getPos().X << " "<< player->getPos().Y<<")|\t|";
			std::cout<<"("<<nextPos.X << " "<< nextPos.Y<<")\n";
			
			currentFloor->react(player);
		}
		
		else if(cmd == 'p'){
			cin>>cmd;
			
			Coordinate curPos = player->getPos();
			Coordinate nextPos = player->getPos();
			
			if(cmd == 'n'){
				nextPos.X = nextPos.X - 1;
				
			}
			if(cmd == 's'){
				nextPos.X = nextPos.X + 1;
				
			}
			if(cmd == 'e'){
				nextPos.Y = nextPos.Y - 1;
				
			}
			if(cmd == 'w'){
				nextPos.Y = nextPos.Y + 1;
					
			}
			
			currentFloor->notifyItem(nextPos, player);
		}
		
		cmd = 0;
		else if(cmd == 'p'){ 
			//player->notifyObservers();
			currentFloor->print();
			std::cout<<"("<<player->getPos().X << " "<< player->getPos().Y<<")\n";
			std::cout<<"("<<nextFloorLoc.X << " "<< nextFloorLoc.Y<<")\n";
		}
		
		else if(cmd == 'n') nextFloor();
		
		//else if(cmd == 'c') currentFloor->notifyChamber();
		
		else if(cmd == 'd'){
			int i;
			cin>>i;
			currentFloor->printChamber(i);
		}
		
		
		//system("clear");*/
	}
}

void Dungeon::chooseChar(){
	
}

void Dungeon::moveEnemies(){
	
}

void Dungeon::nextFloor(){
/*	delete currentFloor;
	currentFloor = new Floor(FloorMaps.at(level), td, randGen);
	
	player->move(currentFloor->genPlayerLoc());
	
	nextFloorLoc = currentFloor->genNextFloorLoc();
	
	currentFloor->genFloor();
	
	td->load(FloorMaps.at(level));
	++level;*/
}

void Dungeon::victory(){
	throw "victory";
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
