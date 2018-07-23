#include "floor.h"

#include<iostream>
#include<stdlib.h>
#include<algorithm>
std::ostream &operator<<(std::ostream &out, Coordinate &coord){
	out<<"("<<coord.X<<" "<<coord.Y<<")";

	return out;
}

using namespace std;

bool oneTileAway(Coordinate obj1, Coordinate obj2){
	int diffX = obj1.X - obj2.X;
	int diffY = obj1.Y - obj2.Y;
	
	diffX = abs(diffX);
	diffY = abs(diffY);
	
	return diffX <= 1 && diffY <= 1 && !(diffX == 0 && diffY == 0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool invalidTile(char test){return (test == ' ' || test == '|' || test == '-' || test == '#' || test == '+'); }

bool detAddCoord(vector<Coordinate*> &chamberCoords, vector<string> plan, int xOff, int yOff, Coordinate *i){
	if(!invalidTile(plan.at(i->X + xOff)[i->Y + yOff])){
		if(chamberCoords.end() == find_if(chamberCoords.begin(), chamberCoords.end(), 
			[&](Coordinate *inCoord){return inCoord->X == i->X + xOff && inCoord->Y == i->Y + yOff; })){
				
			chamberCoords.emplace_back(new Coordinate{i->X + xOff, i->Y + yOff});
			return true;
		}
	}
	
	return false;
}

//gives the cells in a chamber
bool reqCellsInChamber(Coordinate *coord, vector<string> plan, vector<Coordinate*> &chamberCoords){
	
	
	chamberCoords.emplace_back(coord);
	
	bool newTile = true;
	
	while(newTile){
		newTile = false;
		
		for (auto i : chamberCoords){
		//	cout<<"I am error"<<endl;
			newTile = detAddCoord(chamberCoords, plan, 1, 0, i) || newTile;
			newTile = detAddCoord(chamberCoords, plan, 0, 1, i) || newTile;
			newTile = detAddCoord(chamberCoords, plan, -1, 0, i) || newTile;
			newTile = detAddCoord(chamberCoords, plan, 0, -1, i) || newTile;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Floor::Floor(std::vector<std::string> plan, TextDisplay *newDisp, bool whatGen):td{newDisp},randGen{whatGen}{
	
	
	int i = 0;
	//make cells
	for(auto row : plan){
		for(int j = 0; row[j]; ++j){
			//if(row[j] == '#' || row[j] == '+' || row[j] == '.') passages.emplace_back(new Cell(td, row[j], Coordinate{i,j}));
			if(row[j] == ' ' || row[j] == '|' || row[j] == '-'){
				
			}
			
			else{
				cells.emplace_back(new Cell(td, row[j], Coordinate{i,j}));
			}
		}
		++i;
	}
	
	//adds the neighbours
	for(auto curCell : cells){
		for(auto neighbourCell : cells){
			if(oneTileAway(curCell->getPos(), neighbourCell->getPos())){
				curCell->addNeighbour(neighbourCell);
			}
		}
	}
	
	//make chambers
	i = 0;
	for(auto row : plan){
		//cout<<"asdfasdf"<<i<<"\n";
		for(int j = 0; row[j]; ++j){
			if(!(invalidTile(row[j]))){
				bool newChamber = true;
				for(auto oldChamber : chambers){
					
					if(oldChamber->ValidMove(Coordinate{i,j})){
						newChamber = false;
					}
				}
				
				if(newChamber){
					
					vector<Coordinate *> reqCells;
					
					
					
					Coordinate *newCoord = new Coordinate(i, j);
					
					
					//cout<<reqCells.size()<<" ";
					//for some reason there is a vector ou of range error here which resolves itself?
					try{
						reqCellsInChamber(newCoord, plan, reqCells);
						chambers.emplace_back(new Chamber(td, reqCells, cells));
//						cout<<"I ran";
					}
					catch(...){
	//					cout<<"caught the error\n";
//						cout<<reqCells.size()<<endl;
	//					cout<<chambers.size()<<endl;
		//				for(auto i : chambers){
			//				i->printChamber();
				//		}
					}
					

				}
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

void Floor::readEntities(std::vector<std::string> plan){
		for (auto chamber : chambers){
			chamber->readEntities(plan);
		}
}


void Floor::genMonsterLoc(){
	
	for(int i = 0; i < maxEnemies; ++i){
		int whichChamber = rand() % chambers.size();
		
		enemies.emplace_back(chambers.at(whichChamber)->genMonsterLoc());
	}
}

void Floor::genPotionLoc(){
	
	for(int i = 0; i < maxPotions; ++i){
		int whichChamber = rand() % chambers.size();
		
		items.emplace_back(chambers.at(whichChamber)->genPotionLoc());
	}
}

void Floor::genGoldLoc(){
	
	for(int i = 0; i < maxTreasure; ++i){
		int whichChamber = rand() % chambers.size();
		
		items.emplace_back(chambers.at(whichChamber)->genGoldLoc());
	}
}

Coordinate Floor::genNextFloorLoc(){
	int whichChamber = rand() % chambers.size();
	
	while(whichChamber == spawnRoom){
		whichChamber = rand() % chambers.size();
	}
	
	
	return chambers.at(whichChamber)->genNextFloorLoc();
}

Cell *Floor::genPlayerLoc(){
	
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

void Floor::NotifyCell(Coordinate coord){
	
}

void Floor::NotifyGold(Coordinate coord){
	//for(auto i : chambers){
	//	i->notifyItems();
	//}
}

void Floor::react(PlayerRace *player){
	//for(auto i : chambers){
	//	i->react(player);
	//}
}

void Floor::notifyItem(Coordinate nextPos, PlayerRace *player){
	//for(auto i : chambers){
	//	i->notifyItem(nextPos, player);
	//}
}

void Floor::moveEnemies(){
	//for(auto i : chambers){
	//	i->moveEnemies();
	//}
	for(i : enemies){
		i->move();
	}
}
void Floor::NotifyItems(){
	//for(auto i : chambers){
	//	i->notifyItems();
	//}
}

bool Floor::ValidMove(Coordinate coord){
	for(auto i : cells){
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


void Floor::bloom(){
	for(auto i : chambers){
		i->bloom();
		i->printChamber();
	}
	
}
void Floor::refresh(){
	for(auto cell : cells){
		cell->alertDisplayOfChange();
	}
}

