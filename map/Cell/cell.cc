#include "cell.h"
#include "../../display/textDisplay.h"
#include "../../character/character.h"
#include "../../item/item.h"

Cell::Cell(TextDisplay *display, char type, Coordinate coord):position{coord},td{display}{
	
	dispChar = type;
	
}

void Cell::addNeighbour(Cell *neighbour){
	neighbours.emplace_back(neighbour);
}

bool Cell::isOccupiedEnemy(){
	return itemHere || characterHere || treasureHere;
}

bool Cell::isOccupiedPlayer(){
	return itemHere || characterHere;
}

/*
Coordinates Cell::getPos(){
	return position;
}
*/

void Cell::deleteChar(Character *character){
	
}

void Cell::deleteItem(Item *item){
	
}

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

void Cell::notify(Subject &fromWho){
	if(dispChar != '.'){
	//	notifyObservers();
	}
	//if(dispChar != 'b'){
	//	dispChar = 'b';
	//	notifyObservers();
	//}
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

void Cell::send(){
	for(auto i : neighbours){
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
