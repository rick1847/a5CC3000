#include <iostream>
#include "dungeon.h"
	
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

Dungeon::Dungeon(ifstream &mapFile){
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
	
	level = 0;
	td = new TextDisplay(FloorMaps.at(level));
	
	currentFloor = new Floor(FloorMaps.at(0));
}

void Dungeon::play(){
	
	int i = 0;
	
	char cmd = '1';
	while(cmd != 'q'){
		/*if(cmd == 'p'){
			for(auto v : FloorMaps){
				for(auto i: v){
					cout<<i<<endl;
				}
			}
		}
		
		cin>>cmd;*/
		
		if(cmd == 'p') currentFloor->print();
		
		if(cmd == 'n') nextFloor();
		
		if(cmd == 'c') currentFloor->notifyChamber();
		
		if(cmd == 'd'){
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
	delete td;
	td = new TextDisplay(FloorMaps.at(1));
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
