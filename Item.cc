#include "item.h"


Item::Item(Coordinate &p, Cell &c) : position(&p), cell(&c)
{}

Item::~Item(){
	delete position;
	delete cell;
}

void Item::myEffect(PlayerRace &pl) {
	(void)pl;
}

char Item::getAvatar() {
	return '.';
}
