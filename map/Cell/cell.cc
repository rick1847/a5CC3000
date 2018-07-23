#include<iostream>
#include "cell.h"
#include "../../display/textDisplay.h"
#include "../../character/character.h"
#include "../../item/item.h"


Cell::Cell(TextDisplay *display, char type, Coordinate &coord):position{*coord},td{display}{
	
	dispChar = type;
	
}

Coordinates &Cell::getPos() {
	return position;
}

char Cell::getDisplayChar() {
	if (characterHere) {
		return characterHere->getAvatar();
	}
	else if (itemHere) {
		return itemHere->getAvatar();
	}
	else {
		return dispChar;
	}
}

void Cell::setDisplayChar(char a) {
	dispChar = a;
}

Item *Cell::getItem() {
	return itemHere;
}

Character *Cell::getCharacter() {
	return characterHere;
}

void Cell::setItem(Item *item) {
	itemHere = item;
}

void Cell::setCharacter(Character *character) {
	characterHere = character;
}

void Cell::killCharacter(Character *character) {
	delete characterHere;
	characterHere = nullptr;
}

void Cell::removeItem(Item *item) {
	delete itemHere;
	itemHere = nullptr;
}

bool Cell::isOccupied() {
	return itemHere || characterHere;
}

void Cell::addNeighbour(Cell *neighbour){
	neighbours.emplace_back(neighbour);
}

std::vector<Cell *> &Cell::getNeighbours() {
	return neighbours;
}

void Cell::notify(Subject &fromWho){
	if(dispChar != '.'){
	//	notifyObservers();
	}
	//if(dispChar != 'b'){
	//	dispChar = 'b';
	//	notifyObservers();
	//}
}

void Cell::alertDisplayOfChange() {
	char tmp;
	//set to default dispChar
	td->notify(*this);

	//overwrite to item dispChar
	if (itemHere) {
		tmp = dispChar;
		dispChar = itemHere->getAvatar();
		td->notify(*this);
		dispChar = tmp;
	}
	//if there was gold and a player want to ovewrite gold
	if (characterHere) {
		tmp = dispChar;
		dispChar = characterHere->getAvatar();
		td->notify(*this);
		dispChar = tmp;
	}
}

void Cell::send() {
	for (i : neighbours) {
		i->receive(this);
	}
}

void Cell::send(std::string dir) {
	bool changed = false;
	for (auto cell : neighbours) {
		changed = false;
		if (inDir(dir, this, cell)) {
			changed = cell->receive(characterHere);

			//character moved
			if (changed) {

				characterHere = nullptr;
			}
			//characterHere = nullptr;
			std::cout << changed << std::endl;
			return;
		}

		//if we can get position
		/*
		changed = cell->receive(characterHere);
		if(changed){
		characterHere = nullptr;
		return;
		}*/
	}
}

void Cell::receive(Cell *neighbour) {
	if (dispChar < 122) {
		++dispChar;
		send();
	}
	else {
		//td->notify(*this);
	}


}

bool Cell::receive(Character *myChar) {
	//if we can get position
	/*if(myChar->getPos() == position){
	characterHere = myChar;
	characterHere->changeCell(this);
	return true;
	}*/


	//empty cell means place
	if (!characterHere && !itemHere) {
		characterHere = myChar;
		characterHere->changeCell(this);

		return true;
	}
	//nothing changed
	return false;
}
void Cell::bloom() {
	send();
}