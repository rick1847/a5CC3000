#include "cell.h"

Cell::Cell(Observer *display, char type, Coordinates coord):Subject(coord){
	observers.emplace_back(display);
	
	dispChar = type;
	
	
}

bool Cell::isOccupiedEnemy(){
	return true;
}

bool Cell::isOccupiedPlayer(){
	return true;
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

void Cell::notify(Subject &fromWho){
	if(dispChar < 57){
		++dispChar;
		notifyObservers();
	}
}





