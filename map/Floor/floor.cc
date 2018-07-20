#include "floor.h"

#include<iostream>

std::ostream &operator<<(std::ostream &out, Coordinates &coord){
	out<<"("<<coord.x<<" "<<coord.y<<")";

	return out;
}

using namespace std;
Floor::Floor(std::vector<std::string> plan){
	td = new TextDisplay(plan);
	
	size_t i = 0;
	
	for(auto row : plan){
		for(size_t j = 0; row[j]; ++j){
			if(row[j] == '#') passages.emplace_back(new Cell(td, row[j], Coordinates{i,j}));
			
			else if(row[j] == ' ' || row[j] == '|' || row[j] == '-'){
				
			}
			
			else{
				bool newChamber = true;
				for(auto oldChamber : chambers){
					//cout<<chambers.size()<<"("<<i<<" "<<j<<")"<<"I work\n";
					if(!oldChamber->ValidMove(Coordinates{i,j})){
						newChamber = false;
						
					}
					
				}
				
				//cout<<"("<<i<<" "<<j<<")"<<"I work2\n";
				if(newChamber) chambers.emplace_back(new Chamber(td, plan, Coordinates{i,j}));
				
				
			}
		}
		++i;
	}
}

void Floor::printChamber(int i){
	chambers.at(i)->printChamber();
}
void Floor::print(){
	td->print();
}
void Floor::notify(Subject &whoFrom){
	
}

void Floor::genPotionLoc(){
	
}

void Floor::genGoldLoc(){
	
}

void Floor::genNextFloorLoc(){
	
}

void Floor::genPlayerLoc(){
	
}

void Floor::genMonsterLoc(){
	
}


void Floor::genFloor(){
	
}

void Floor::moveEnemies(){
	
}

void Floor::deleteEnemy(EnemyRace *which){
	
}

void Floor::deleteItem(Item *which){
	
}

void Floor::NotifyCell(Coordinates coord){
	
}

void Floor::NotifyGold(Coordinates coord){
	
}

bool Floor::ValidMove(Coordinates coord){
	
}

Coordinates Floor::getRandCoords(){
	return Coordinates{1, 1};
}

void Floor::notifyChamber(){
	for(auto i : chambers){
		i->bloom();
	}
}
