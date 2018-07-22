#include "potion.h"


Potion::Potion(Coordinate &p, Cell &c) : Item(p, c)
{}

Potion::~Potion() {
}

void myEffect(Stats *s) {
	(void)s;
}

std::string revealType() {
	return "an unknown potion";
}

char Potion::getAvatar() {
	return 'P';
}
