#include "potion.h"


Potion::Potion(Coordinate &p, Cell &c) : Item(p, c)
{}

Potion::~Potion() {
}

char Potion::getAvatar() {
	return 'P';
}

void Potion::pickupEffect(PlayerRace &pl){
	this->myEffect(pl);
	setInactive();
}
