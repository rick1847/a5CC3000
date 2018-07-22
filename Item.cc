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

std::string Item::giveType() {
	return "a thing";
}

char Item::getAvatar() {
	return '.';
}
