#include "cell.h"
#include "../../display/textDisplay.h"

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
