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

//is cell2 in some direction dir of cell1
bool inDir(char dir, Cell *cell1, Cell *cell2){
	Coordinate pos1 = cell1->getPos();
	Coordinate pos2 = cell2->getPos();
	
	if(dir == 'n'){
		return pos2.X < pos1.X && pos2.Y == pos1.Y;
	}
	else if(dir == 's'){
		return pos2.X > pos1.X && pos2.Y == pos1.Y;
	}
	else if(dir == 'e'){
		return pos2.X == pos1.X && pos2.Y > pos1.Y;
	}
	else if(dir == 'w'){
		return pos2.X == pos1.X && pos2.Y < pos1.Y;
	}
	else{
		return false;
	}
}

#include<iostream>
void Cell::send(char dir){
	
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
			std::cout<<changed<<std::endl;
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
	//if we can get position
	/*if(myChar->getPos() == position){
		characterHere = myChar;
		characterHere->changeCell(this);
		return true;
	}*/
	
	
	//empty cell means place
	if(!characterHere && !itemHere){
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
