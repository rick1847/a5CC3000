#include "cell.h"
#include "../../display/textDisplay.h"
#include "../../character/character.h"
#include "../../item/item.h"
#include "../../item/gold/treasure.h"

#include <iostream>
using namespace std;

Cell::Cell(TextDisplay *display, char type, Coordinate *coord):position{coord},td{display}{
	
	dispChar = type;
	
}

Coordinate *Cell::getPos(){
	return position;
}

char Cell::getDisplayChar(){
	return dispChar;
}

void Cell::setDisplayChar(char a){
	dispChar = a;
}

Item *Cell::getItem(){
	return itemHere;
}

Character *Cell::getCharacter(){
	return characterHere;
}

void Cell::setItem(Item *item){
	itemHere = item;
}

void Cell::setCharacter(Character *character){
	characterHere = character;
}

void Cell::killCharacter() {
	delete characterHere;
	characterHere = nullptr;
}

void Cell::removeItem() {
	delete itemHere;
	itemHere = nullptr;
}

bool Cell::isOccupied() {
	return itemHere || characterHere || dispChar == '/';
}

void Cell::addNeighbour(Cell *neighbour){
	neighbours.emplace_back(neighbour);
}

std::vector<Cell *> &Cell::getNeighbours() {
	return neighbours;
}

void Cell::alertDisplayOfChange(){
	char tmp;
	//set to default dispChar
	td->notify(*this);
	
	//overwrite to item dispChar
	if(itemHere){
		tmp = dispChar;
		dispChar = itemHere->getAvatar();
		td->notify(*this);
		dispChar = tmp;
	}
	//if there was gold and a player want to ovewrite gold
	if(characterHere){
		tmp = dispChar;
		dispChar = characterHere->getAvatar();
		td->notify(*this);
		dispChar = tmp;
	}
}

void Cell::send(){
	for(auto i : neighbours){
		i->receive(this);
	}
}

void Cell::send(string dir){
	
	bool changed = false;
	for(auto cell : neighbours){
		changed = false;
		if(inDir(dir, *(this->getPos()), *(cell->getPos()))){
			changed = cell->receive(characterHere);
			
			//character moved
			if(changed){
				
				characterHere = nullptr;
			}
			//characterHere = nullptr;
			//std::cout<<changed<<std::endl;
			return;
		}
	}
}

void Cell::receive(Cell *neighbour){
	if(dispChar < 122){
		++dispChar;
		send();
	}
	else{
		//td->notify(*this);
	}
}

bool Cell::receive(Character *myChar){
	
	//case we have a playerRace and a Gold
	//note never the case we have an enemy and item in the same spot
	//so this is safe
	if(itemHere){
		if(myChar->isPlayable() && itemHere->isSteppableByPlayer()){ 
			characterHere = myChar;
			characterHere->changeCell(this);
			return true;
		}
	}
	if(dispChar == '+' && !(myChar->isPlayable())){ //enemies can't enter passages
		return false;
	}
	if(!isOccupied()){
		characterHere = myChar;
		characterHere->changeCell(this);		
		return true;
	}
	//nothing changed
	return false;
}

Item *Cell::getItemInDir(std::string dir){
	for(auto cell : neighbours){
		if(inDir(dir, *(this->getPos()), *(cell->getPos()))){
			return cell->getItem();
		}
	}
}
Character *Cell::getCharacterInDir(std::string dir){
	for(auto cell : neighbours){
		if(inDir(dir, *(this->getPos()), *(cell->getPos()))){
			return cell->getCharacter();
		}
	}
}

void Cell::bloom(){
	send();
}

void Cell::autoLootGold(){
	//guarenteed that this will be a player and a treasure as
	// this is the combination that allows two things on one tile
	if(characterHere && itemHere){
		itemHere->myEffect(*static_cast<PlayerRace*>(characterHere));
		itemHere->setInactive();
	}
}
