#include "floor.h"

#include<iostream>
#include<stdlib.h>

std::ostream &operator<<(std::ostream &out, Coordinates &coord){
	out<<"("<<coord.x<<" "<<coord.y<<")";

	return out;
}

using namespace std;
Floor::Floor(std::vector<std::string> plan, TextDisplay *newDisp, bool whatGen):td{newDisp},randGen{whatGen}{
	
	
	size_t i = 0;
	
	for(auto row : plan){
		for(size_t j = 0; row[j]; ++j){
			if(row[j] == '#' || row[j] == '+') passages.emplace_back(new Cell(td, row[j], Coordinates{i,j}));
			
			else if(row[j] == ' ' || row[j] == '|' || row[j] == '-'){
				
			}
			
			else{
				bool newChamber = true;
				for(auto oldChamber : chambers){
					//cout<<chambers.size()<<"("<<i<<" "<<j<<")"<<"I work\n";
					if(oldChamber->ValidMove(Coordinates{i,j})){
						newChamber = false;
						
					}
					
				}
				
				//cout<<"("<<i<<" "<<j<<")"<<"I work2\n";
				if(newChamber) chambers.emplace_back(new Chamber(td, plan, Coordinates{i,j}, randGen));
				
				
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

void Floor::readEntities(std::vector<std::string> plan){
		for (auto chamber : chambers){
			chamber->readEntities(plan);
		}
}


void Floor::genMonsterLoc(){
	
	for(int i = 0; i < maxEnemies; ++i){
		int whichChamber = rand() % chambers.size();
		
		chambers.at(whichChamber)->genMonsterLoc();
	}
}

void Floor::genPotionLoc(){
	
	for(int i = 0; i < maxPotions; ++i){
		int whichChamber = rand() % chambers.size();
		
		chambers.at(whichChamber)->genPotionLoc();
	}
}

void Floor::genGoldLoc(){
	
	for(int i = 0; i < maxTreasure; ++i){
		int whichChamber = rand() % chambers.size();
		
		chambers.at(whichChamber)->genGoldLoc();
	}
}

Coordinates Floor::genNextFloorLoc(){
	int whichChamber = rand() % chambers.size();
	
	while(whichChamber == spawnRoom){
		whichChamber = rand() % chambers.size();
	}
	
	
	return chambers.at(whichChamber)->genNextFloorLoc();
}

Coordinates Floor::genPlayerLoc(){
	int whichChamber = 	rand() % chambers.size();
	
	spawnRoom = whichChamber;
	
	return chambers.at(whichChamber)->genPlayerLoc();
}


void Floor::genFloor(){
	genMonsterLoc();
	genPotionLoc();
	genGoldLoc();
	
}




void Floor::deleteEnemy(EnemyRace *which){
	
}

void Floor::deleteItem(Item *which){
	
}

void Floor::NotifyCell(Coordinates coord){
	
}

void Floor::NotifyGold(Coordinates coord){
	for(auto i : chambers){
		i->notifyItems();
	}
}

void Floor::react(PlayerRace *player){
	for(auto i : chambers){
		i->react(player);
	}
}

void Floor::notifyItem(Coordinates nextPos, PlayerRace *player){
	for(auto i : chambers){
		i->notifyItem(nextPos, player);
	}
}

void Floor::moveEnemies(){
	for(auto i : chambers){
		i->moveEnemies();
	}
}
void Floor::NotifyItems(){
	for(auto i : chambers){
		i->notifyItems();
	}
}

bool Floor::ValidMove(Coordinates coord){
	for(auto i : passages){
		if(i->getPos() == coord){
			return true;
		}
	}
	
	int a = 0;
	for (auto chamber : chambers){
		//cout<<"asfd"<<a<<"\n";
		if(chamber->ValidMove(coord)){
			
			//cout<<"asfd"<<a<<"\n";
			//chamber->printChamber();
			return true;
			
			
		}
		++a;
	}
	
	return false;
}

Coordinates Floor::getRandCoords(){
	/* random chamber position here*/
	
	//for testing
	return chambers.at(0)->genPlayerLoc();
}

void Floor::notifyChamber(){
	for(auto i : chambers){
		i->bloom();
	}
	
	for(auto i : passages){
		td->notify(*i);
	}
}
