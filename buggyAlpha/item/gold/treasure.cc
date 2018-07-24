#include "treasure.h"


Treasure::Treasure(Coordinate &p, Cell &c) : Item(p, c)
{}

Treasure::~Treasure() {
}

char Treasure::getAvatar() {
	return 'G';
}

bool Treasure::isSteppableByPlayer(){
	return true;
}
