#include <iostream>
#include "dungeon.h"
#include "Floor/floor.h"
#include "../character/character.h"
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
	
	level = 1;
	td = new TextDisplay(FloorMaps.at(level));
	
	currentFloor = new Floor(FloorMaps.at(0), td, whatGen);
	
//	player = new PlayerRace(td, currentFloor->getRandCoords());
	
//	player->notifyObservers();

	player = new PlayerRace(td, currentFloor->genPlayerLoc());
	
	nextFloorLoc = currentFloor->genNextFloorLoc();
	
	currentFloor->genFloor();
	
	
	
}

void Dungeon::play(){
	
	int i = 0;
	
	int moveTile;
	char cmd = '1';
	
	currentFloor->moveEnemies();
	currentFloor->NotifyItems();
	player->notifyObservers();
	
	while(cmd != 'q'){
		
		if(cmd == 'm'){
				cin>>cmd;
				Coordinates curPos = player->getPos();
				Coordinates nextPos = player->getPos();
				
				if(cmd == 'n'){
					nextPos.x = nextPos.x - 1;
					
				}
				if(cmd == 's'){
					nextPos.x = nextPos.x + 1;
					
				}
				if(cmd == 'e'){
					nextPos.y = nextPos.y - 1;
					
				}
				if(cmd == 'w'){
					nextPos.y = nextPos.y + 1;
					
				}
				
				//std::cout<<"("<<nextPos.x << " "<< nextPos.y<<")"<<currentFloor->ValidMove(nextPos)<<"\n";
				if(currentFloor->ValidMove(nextPos)){
					player->move(nextPos);
					
					td->notify(*player);
				}
				
				
		}
		else if(cmd == 'p'){ 
			//player->notifyObservers();
			currentFloor->print();
			std::cout<<"("<<player->getPos().x << " "<< player->getPos().y<<")\n";
			std::cout<<"("<<nextFloorLoc.x << " "<< nextFloorLoc.y<<")\n";
		}
		
		else if(cmd == 'n') nextFloor();
		
		else if(cmd == 'c') currentFloor->notifyChamber();
		
		else if(cmd == 'd'){
			int i;
			cin>>i;
			currentFloor->printChamber(i);
		}
		cout<<"nextCommand: ";
		cin>>cmd;
	}
}

void Dungeon::chooseChar(){
	
}

void Dungeon::moveEnemies(){
	
}

void Dungeon::nextFloor(){
	delete currentFloor;
	currentFloor = new Floor(FloorMaps.at(level), td, randGen);
	
	td->load(FloorMaps.at(level));
	++level;
}

void Dungeon::victory(){
	
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
