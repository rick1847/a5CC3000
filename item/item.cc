#include "item.h"


Item::Item(Coordinate &p, Cell &c) : position(&p), cell(&c)
{}

Item::~Item(){
}

void Item::myEffect(PlayerRace &pl) {
	(void)pl;
}

void Item::myEffect(Character &c) {
	(void)pl;
}

std::string Item::giveType() {
	return "a thing";
}

char Item::getAvatar() {
	return '.';
}

Coordinate Item::getPos(){
	return position;
}

void Item::disappear() {
	cell->removeItem();
}
