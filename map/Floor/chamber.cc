#include "chamber.h"
#include <algorithm>
#include <iostream>

#include "../../character/enemyRace/dragon.h"
#include "../../character/enemyRace/dwarf.h"
#include "../../character/enemyRace/elf.h"
#include "../../character/enemyRace/halfling.h"
#include "../../character/enemyRace/human.h"
#include "../../character/enemyRace/merchant.h"
#include "../../character/enemyRace/orc.h"

#include "../../item/potions/boostatk.h"
#include "../../item/potions/boostdef.h"
#include "../../item/potions/poisonhealth.h"
#include "../../item/potions/restorehealth.h"
#include "../../item/potions/woundatk.h"
#include "../../item/potions/wounddef.h"

#include "../../item/gold/dhoard.h"
#include "../../item/gold/mhoard.h"
#include "../../item/gold/normal.h"
#include "../../item/gold/small.h"


#include<stdlib.h>

using namespace std;



Chamber::Chamber(TextDisplay *td, vector<Coordinate*> &reqCells, const vector<Cell*> &theCells):myTd{td}{
	for(auto i : reqCells){
		for(auto cell : theCells){
			if((*i) == cell->getPos()){
				cells.emplace_back(cell);
				break;
			}
		}
	}
}

void Chamber::readEntities(std::vector<std::string> plan){
	/*
	for(int i = 0; i < plan.size(); ++i){
		for(int j = 0; j < plan.at(0).size(); ++j){
			Coordinate candidate = Coordinate{i, j};
			if(ValidMove(candidate)){
				if(dragonPileChar(plan.at(i)[j])){
					Item *newDragPile = new Item(myTd, candidate);
					
					const char dragChar = 'D';
					
					//assume that dragon hoards are well spaced out
					if(plan.at(i+1)[j] == dragChar){
						++(candidate.X);
					}
					else if(plan.at(i+1)[j+1] == dragChar){
						++(candidate.X);
						++(candidate.Y);
					}
					else if(plan.at(i)[j+1] == dragChar){
						
						++(candidate.Y);
					}
					else if(plan.at(i-1)[j+1] == dragChar){
						--(candidate.X);
						++(candidate.Y);
					}
					else if(plan.at(i-1)[j] == dragChar){
						--(candidate.X);
					}
					else if(plan.at(i-1)[j-1] == dragChar){
						--(candidate.X);
						--(candidate.Y);
					}
					else if(plan.at(i)[j-1] == dragChar){
						--(candidate.Y);
					}
					else if(plan.at(i+1)[j-1] == dragChar){
						++(candidate.X);
						--(candidate.Y);
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
	*/
}
/*
void Chamber::printChamber(){
	;
}
*/

Coordinate Chamber::genLoc(char whatChar){
	bool occupied = true;
	
	while(occupied){
		int whichLoc = rand() % cells.size();
		Coordinate candidateLoc = cells.at(whichLoc)->getPos();
		occupied = cells.at(whichLoc)->isOccupiedEnemy();
		
		
		if(!occupied){
			//cells.at(whichLoc)->setOccupy(true);
			cells.at(whichLoc)->setChar(whatChar);
			return cells.at(whichLoc)->getPos();
		}
	}
}
Coordinate Chamber::genNextFloorLoc(){
	return genLoc('/');
	
}

Cell *Chamber::genPlayerLoc(){
	
	
	Coordinate tmp = genLoc('.');
	
	for(auto i : cells){
		if(i->getPos() == tmp){
			return i;
		}
	}
	
	//should not be possible
	return nullptr;
}

Cell *Chamber::getCellAt(Coordinate pos){
	for(auto cell : cells){
		if(cell->getPos() == pos){
			return cell;
		}
	}
	return nullptr;
}

Character *Chamber::genMonsterLoc(){
	Coordinate newLoc = genLoc('.');
	Cell *whichCell = getCellAt(newLoc);
	Human *newH = new Human(newLoc, *whichCell);
	
	whichCell->setCharacterHere(newH);
	
	return newH;
	//for now, will have a factory later
//	enemies.emplace_back(new Human(newLoc, Cell{myTd, 'H', newLoc} ));
	
}

Item *Chamber::genPotionLoc(){
	
	Coordinate newLoc = genLoc('.');
	Cell *whichCell = getCellAt(newLoc);
	BoostATK *newBATK = new BoostATK(newLoc, *whichCell);
	
	whichCell->setItemHere(newBATK);
	
	return newBATK;
	
}

Item *Chamber::genGoldLoc(){
	Coordinate newLoc = genLoc('.');
	Cell *whichCell = getCellAt(newLoc);
	Normal *newNormal = new Normal(newLoc, *whichCell);
	
	whichCell->setItemHere(newNormal);
	return newNormal;
	
}


bool Chamber::ValidMove(Coordinate coord){
	
	Cell *candCell = nullptr;
	for(auto cell : cells){
		//cout<<"asdfasdfasdf"<<endl;
		if(cell->getPos() == coord){
			candCell = cell;
		}
	}
	
	bool test = cells.end() == find_if(cells.begin(), cells.end(), 
		[&coord](Cell *inCell)
			{return inCell->getPos().X == coord.X && inCell->getPos().Y == coord.Y; });
	
	
	if(candCell) {
		return !(candCell->isOccupiedEnemy());
	}
	
	else {
		return false;
	}
	
}

void Chamber::bloom(){
	for(auto i : cells){
		i->setChar('b');
		myTd->notify(*i);
	}
	cout<<"size: "<<cells.size()<<endl;
}

void Chamber::printChamber(){
	for(auto cell: cells){
		cout<<cell->getPos().X<<" "<<cell->getPos().Y;
	}
	cout<<endl;
}
