#include "cell.h"
#include "../../display/textDisplay.h"
#include "../../character/character.h"
#include "../../item/item.h"

#include <iostream>
using namespace std;
Cell::Cell(TextDisplay *display, char type, Coordinate coord):position{coord},td{display}{
	
	dispChar = type;
	
}

void Cell::addNeighbour(Cell *neighbour){
	neighbours.emplace_back(neighbour);
}

bool Cell::isOccupiedEnemy(){
	return itemHere || characterHere || dispChar == '/';
}

bool Cell::isOccupiedPlayer(){
	return itemHere || characterHere;
}

<<<<<<< HEAD
=======
/*
Coordinates Cell::getPos(){
	return position;
}
*/

void Cell::killChar(Character *character){
	delete characterHere;
	characterHere = nullptr;
}

void Cell::removeItem(Item *item){
	delete itemHere;
	itemHere = nullptr;
}
>>>>>>> 96165da3ca5b6ae01dea71dc38cbdb1c06efb12f

void Cell::setItemHere(Item *item){
	itemHere = item;
}
void Cell::setCharacterHere(Character *character){
	characterHere = character;
}
Item *Cell::getItemHere(){
	return itemHere;
}
Character *Cell::getCharacterHere(){
	return characterHere;
}


void Cell::setChar(char a){
	dispChar = a;
}


Coordinate Cell::getPos(){
	return position;
}

Coordinate *Cell::getPosPtr(){
		return &position;
}

char Cell::getDispChar(){
	return dispChar;
}

//is pos2 east of pos1
bool isEast(Coordinate pos1, Coordinate pos2){
	return pos2.Y > pos1.Y;	
}
//is pos2 north of pos1 (note, north is less)
bool isNorth(Coordinate pos1, Coordinate pos2){
	return pos2.X < pos1.X;
}
bool sameNorthNess(Coordinate pos1, Coordinate pos2){
	return pos2.X == pos1.X;
}

bool sameEastNess(Coordinate pos1, Coordinate pos2){
	return pos2.Y == pos1.Y;
}
//is cell2 in some direction dir of cell1
bool inDir(string dir, Cell *cell1, Cell *cell2){
	Coordinate pos1 = cell1->getPos();
	Coordinate pos2 = cell2->getPos();
	
	if(dir == "no"){
		return isNorth(pos1, pos2) && sameEastNess(pos1, pos2);
	}
	else if(dir == "so"){
		return (!isNorth(pos1, pos2)) && sameEastNess(pos1, pos2);
	}
	else if(dir == "ea"){
		return isEast(pos1, pos2) && sameNorthNess(pos1, pos2);
	}
	else if(dir == "we"){
		return (!isEast(pos1, pos2)) && sameNorthNess(pos1, pos2);
	}
	else if(dir == "ne"){
		return isNorth(pos1, pos2) && isEast(pos1, pos2);
	}
	else if(dir == "nw"){
		return isNorth(pos1, pos2) && (!isEast(pos1, pos2));
	}
	else if(dir == "se"){
		return (!isNorth(pos1, pos2) && (!sameNorthNess(pos1, pos2))) && isEast(pos1, pos2);
	}
	else if(dir == "sw"){
		return (!isNorth(pos1, pos2) && (!sameNorthNess(pos1, pos2))) && (!isEast(pos1, pos2));
	}
	else{
		return false;
	}
}

#include<iostream>
void Cell::send(string dir){
	
	bool changed = false;
	for(auto cell : neighbours){
		changed = false;
		if(inDir(dir, this, cell)){
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

void Cell::send(){
	for(i : neighbours){
		i->receive(this);
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
	
	if(!isOccupiedEnemy()){
		characterHere = myChar;
		characterHere->changeCell(this);
		
		
		return true;
	}
	//nothing changed
	return false;
}
void Cell::bloom(){
	send();
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

