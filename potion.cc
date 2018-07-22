#include "potion.h"


Potion::Potion(Coordinate &p, Cell &c) : Item(p, c)
{}

Potion::~Potion() {
}

char Potion::getAvatar() {
	return 'P';
}
