#include "chamber.h"
#include <algorithm>
#include <iostream>
#include "../Display/textDisplay.h"
#include "../../character/character.h"
#include "../../item/item.h"

#include<stdlib.h>

using namespace std;


bool invalidTile(char test){return (test == ' ' || test == '|' || test == '-' || test == '#' || test == '+'); }



bool oneTileAway(Coordinates obj1, Coordinates obj2){
	int diffX = obj1.x - obj2.x;
	int diffY = obj1.y - obj2.y;
	
	diffX = abs(diffX);
	diffY = abs(diffY);
	
	return diffX <= 1 && diffY <= 1 && !(diffX == 0 && diffY == 0);
}

bool detAddCoord(vector<Coordinates> &chamberCoords, vector<string> &plan, int xOff, int yOff, auto &i){
	if(!invalidTile(plan.at(i.x + xOff)[i.y + yOff])){
		if(chamberCoords.end() == find_if(chamberCoords.begin(), chamberCoords.end(), [&](Coordinates inCoord){return inCoord.x == i.x + xOff && inCoord.y == i.y + yOff; })){
			chamberCoords.emplace_back(Coordinates{i.x + xOff, i.y + yOff});
			return true;
		}
	}
	
	return false;
}
Chamber::Chamber(TextDisplay *td, vector<string> plan, Coordinates coord, bool whatGen):myTd{td}{
	vector<Coordinates> chamberCoords;
	
	chamberCoords.emplace_back(coord);
	
	bool newTile = true;
	
	while(newTile){
		newTile = false;
		for (auto i : chamberCoords){
			newTile = detAddCoord(chamberCoords, plan, 1, 0, i) || newTile;
			newTile = detAddCoord(chamberCoords, plan, 0, 1, i) || newTile;
			newTile = detAddCoord(chamberCoords, plan, -1, 0, i) || newTile;
			newTile = detAddCoord(chamberCoords, plan, 0, -1, i) || newTile;
		}
	}
	/*
	for(int i = 2; i < 8; ++i){
		for(auto pos : chamberCoords){
			if(pos.x == i)
			cout<<"("<<pos.x<<" "<<pos.y<<")";
		}
		cout<<endl;
	}
	cout<<"I work 2 "<<chamberCoords.size()<<endl<<endl;*/
	
	// creates the cells
	for(auto i : chamberCoords)
		cells.emplace_back(new Cell(td, '.', i));
	
	//adds the observers
	for(auto curCell : cells){
		for(auto observerCell : cells){
			if(oneTileAway(curCell->getPos(), observerCell->getPos())){
				curCell->addObserver(observerCell);
			}
		}
		curCell->addObserver(td);
		
	}
	
}

bool dragonPileChar(char test){
	return test == '9';
}
bool enemyChar(char test){
	return test == 'H' || test == 'W' || test == 'E' || test == 'O' || test == 'M' || test == 'L'; 
}
bool itemChar(char test){
	
	for(char a = '0' ; a <= '8' ; ++a){
		if(test == a) return true;
	}
	
	return false;
}
void Chamber::readEntities(std::vector<std::string> plan){
	for(size_t i = 0; i < plan.size(); ++i){
		for(size_t j = 0; j < plan.at(0).size(); ++j){
			Coordinates candidate = Coordinates{i, j};
			if(ValidMove(candidate)){
				if(dragonPileChar(plan.at(i)[j])){
					Item *newDragPile = new Item(myTd, candidate);
					
					const char dragChar = 'D';
					
					//assume that dragon hoards are well spaced out
					if(plan.at(i+1)[j] == dragChar){
						++(candidate.x);
					}
					else if(plan.at(i+1)[j+1] == dragChar){
						++(candidate.x);
						++(candidate.y);
					}
					else if(plan.at(i)[j+1] == dragChar){
						
						++(candidate.y);
					}
					else if(plan.at(i-1)[j+1] == dragChar){
						--(candidate.x);
						++(candidate.y);
					}
					else if(plan.at(i-1)[j] == dragChar){
						--(candidate.x);
					}
					else if(plan.at(i-1)[j-1] == dragChar){
						--(candidate.x);
						--(candidate.y);
					}
					else if(plan.at(i)[j-1] == dragChar){
						--(candidate.y);
					}
					else if(plan.at(i+1)[j-1] == dragChar){
						++(candidate.x);
						--(candidate.y);
					}
					
					enemies.emplace_back(new EnemyRace(myTd, candidate));

				}
				else if(enemyChar(plan.at(i)[j])){
					enemies.emplace_back(new EnemyRace(myTd, candidate));
				}
				else if((plan.at(i)[j])){
					items.emplace_back(new Item(myTd, candidate));
				}
			}
		}
	}
	
}

void Chamber::printChamber(){
	for(int i = 0; i < 30; ++i){
		for(auto cell : cells){
			
			cout<<cell->getDispChar();
			
			/*
			Coordinates pos = cell->getPos();
			if(pos.x == i)
				cout<<"("<<pos.x<<" "<<pos.y<<")";
				* */
		}
		cout<<endl;
	}
}


Coordinates Chamber::genLoc(char whatChar){
	bool occupied = true;
	
	while(occupied){
		int whichLoc = rand() % cells.size();
		Coordinates candidateLoc = cells.at(whichLoc)->getPos();
		occupied = cells.at(whichLoc)->getOccupy();
		
		//cout<<"123123"<<endl;
		
/*		for(auto i : enemies){
			if(i->getPos() == candidateLoc){
				occupied = true;
				break;
			}
		}
		
		for(auto i : items){
			if(i->getPos() == candidateLoc){
				occupied = true;
				break;
			}
		}*/
		
		if(!occupied){
			cells.at(whichLoc)->setOccupy(true);
			cells.at(whichLoc)->setChar(whatChar);
			return cells.at(whichLoc)->getPos();
		}
	}
	
}
Coordinates Chamber::genNextFloorLoc(){
	return genLoc('/');
	
}

Coordinates Chamber::genPlayerLoc(){
	return genLoc('.');
}

void Chamber::genMonsterLoc(){
	//cout<<"111"<<endl;
	Coordinates newLoc = genLoc('.');
	enemies.emplace_back(new EnemyRace(myTd, newLoc));
	
}

void Chamber::genPotionLoc(){
	//cout<<"222"<<endl;
	Coordinates newLoc = genLoc('.');
	items.emplace_back(new Item(myTd, newLoc));
}

void Chamber::genGoldLoc(){
	//cout<<"333"<<endl;
	Coordinates newLoc = genLoc('.');
	items.emplace_back(new Item(myTd, newLoc));
}

void Chamber::genChamber(){
	
}

bool Chamber::InChamber(Coordinates coord){
	
}

void Chamber::deleteItem(Item *which){
	
}

bool Chamber::ValidMove(Coordinates coord){
	bool test = cells.end() == find_if(cells.begin(), cells.end(), 
		[&coord](Cell *inCell)
			{return inCell->getPos().x == coord.x && inCell->getPos().y == coord.y; });
	
	return !test;
	
}

bool Chamber::moveEnemies(){
	
	for(auto i : enemies) {
		i->notifyObservers();
		
	}
	
}

void Chamber::notifyItems(){
	
	for(auto i : items) {
		i->notifyObservers();
		
	}
	
}

void Chamber::bloom(){
	cells.at(0)->notifyObservers();
	for(auto i : cells) i->notifyObservers();
}
