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
			if((*i) == *(cell->getPos())){
				cells.emplace_back(cell);
				break;
			}
		}
	}
}

Coordinate *Chamber::genLoc(char whatChar){
	bool occupied = true;
	
	while(occupied){
		int whichLoc = rand() % cells.size();
		//Coordinate candidateLoc = *(cells.at(whichLoc)->getPos();
		occupied = cells.at(whichLoc)->isOccupied();
		
		if(!occupied){
			//cells.at(whichLoc)->setOccupy(true);
			cells.at(whichLoc)->setDisplayChar(whatChar);
			return cells.at(whichLoc)->getPos();
		}
	}
}

////////////////////////////////////////////////////////////////////////////
//courtesy of Leo Huang
Item *Chamber::genPotionLoc() {
	Coordinate *newLoc = genLoc('.');
	Cell *whichCell = getCellAt(*newLoc);
	int potionToSpawn = rand() % 6;
	if (potionToSpawn == 0) {
		BoostATK *potion = new BoostATK(*newLoc, *whichCell);
		whichCell->setItem(potion);
		return potion;
	}
	else if (potionToSpawn == 1) {
		WoundATK *potion = new WoundATK(*newLoc, *whichCell);
		whichCell->setItem(potion);
		return potion;
	}
	else if (potionToSpawn == 2) {
		BoostDEF *potion = new BoostDEF(*newLoc, *whichCell);
		whichCell->setItem(potion);
		return potion;
	}
	else if (potionToSpawn == 3) {
		WoundDEF *potion = new WoundDEF(*newLoc, *whichCell);
		whichCell->setItem(potion);
		return potion;
	}
	else if (potionToSpawn == 4) {
		PoisonHealth *potion = new PoisonHealth(*newLoc, *whichCell);
		whichCell->setItem(potion);
		return potion;
	}
	else {
		RestoreHealth *potion = new RestoreHealth(*newLoc, *whichCell);
		whichCell->setItem(potion);
		return potion;
	}
}

Item *Chamber::genGoldLoc() {
	Coordinate *newLoc = genLoc('.');
	Cell *whichCell = getCellAt(*newLoc);
	int goldToSpawn = rand() % 8;
	if (goldToSpawn <= 4) {
		Normal *gold = new Normal(*newLoc, *whichCell);
		whichCell->setItem(gold);
		return gold;
	}
	else if (goldToSpawn <= 6) {
		Small *gold = new Small(*newLoc, *whichCell);
		whichCell->setItem(gold);
		return gold;
	}
	else {
		DragonHoard *gold = new DragonHoard(*newLoc, *whichCell);
		for (auto i : whichCell->getNeighbours()) {
			if (!i->isOccupied()) {
				Dragon *guard = new Dragon(*newLoc, *whichCell, *gold);
				i->setCharacter(guard);
				break;
			}
		}
		whichCell->setItem(gold);
		return gold;
	}
}

Character *Chamber::genMonsterLoc() {
	Coordinate *newLoc = genLoc('.');
	Cell *whichCell = getCellAt(*newLoc);
	int enemyToSpawn = 1;//rand() % 18;
	if (enemyToSpawn <= 3) {
		Human *enemy = new Human(*newLoc, *whichCell);
		whichCell->setCharacter(enemy);
		return enemy;
	}
	else if (enemyToSpawn <= 6) {
		Dwarf *enemy = new Dwarf(*newLoc, *whichCell);
		whichCell->setCharacter(enemy);
		return enemy;
	}
	else if (enemyToSpawn <= 11) {
		Halfling *enemy = new Halfling(*newLoc, *whichCell);
		whichCell->setCharacter(enemy);
		return enemy;
	}
	else if (enemyToSpawn <= 13) {
		Elf *enemy = new Elf(*newLoc, *whichCell);
		whichCell->setCharacter(enemy);
		return enemy;
	}
	else if (enemyToSpawn <= 15) {
		Orc *enemy = new Orc(*newLoc, *whichCell);
		whichCell->setCharacter(enemy);
		return enemy;
	}
	else {
		Merchant *enemy = new Merchant(*newLoc, *whichCell);
		whichCell->setCharacter(enemy);
		return enemy;
	}
}
//courtesy of Leo Huang
////////////////////////////////////////////////////////////////////////////


Cell *Chamber::genPlayerLoc(){
	
	Coordinate *tmp = genLoc('.');
	
	for(auto i : cells){
		if(*(i->getPos()) == *tmp){
			return i;
		}
	}
	
	//should not be possible
	return nullptr;
}


bool Chamber::ValidMove(Coordinate coord){
	Cell *candCell = nullptr;
	for (auto cell : cells) {
		//cout<<"asdfasdfasdf"<<endl;
		if (*(cell->getPos()) == coord) {
			candCell = cell;
		}
	}
	/*
	bool test = cells.end() == find_if(cells.begin(), cells.end(),
	[&coord](Cell *inCell)
	{return inCell->getPos().getX() == coord.getX() && inCell->getPos().getY() == coord.getY(); });
	*/

	if (candCell) {
		return !(candCell->isOccupied());
	}

	else {
		return false;
	}	
}

Coordinate *Chamber::genStairLoc(){
	return genLoc('/');
	
}

Cell *Chamber::getCellAt(Coordinate &pos){
	for(auto cell : cells){
		if(*(cell->getPos()) == pos){
			return cell;
		}
	}
	return nullptr;
}

bool Chamber::moveEnemies() {
	return true;
}

void Chamber::bloom() {
	for (auto i : cells) {
		i->setDisplayChar('b');
		myTd->notify(*i);
	}
	cout << "size: " << cells.size() << endl;
}

void Chamber::printChamber() {
	for(auto cell: cells){
		cout<<cell->getPos()->getX()<<" "<<cell->getPos()->getY();
	}
	cout<<endl;
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
						++(candidate.getX());
					}
					else if(plan.at(i+1)[j+1] == dragChar){
						++(candidate.getX());
						++(candidate.getY());
					}
					else if(plan.at(i)[j+1] == dragChar){
						
						++(candidate.getY());
					}
					else if(plan.at(i-1)[j+1] == dragChar){
						--(candidate.getX());
						++(candidate.getY());
					}
					else if(plan.at(i-1)[j] == dragChar){
						--(candidate.getX());
					}
					else if(plan.at(i-1)[j-1] == dragChar){
						--(candidate.getX());
						--(candidate.getY());
					}
					else if(plan.at(i)[j-1] == dragChar){
						--(candidate.getY());
					}
					else if(plan.at(i+1)[j-1] == dragChar){
						++(candidate.getX());
						--(candidate.getY());
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
