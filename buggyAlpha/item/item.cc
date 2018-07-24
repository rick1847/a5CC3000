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

Coordinate Item::getPos(){
	return *position;
}

void Item::pickupEffect(PlayerRace &pl){
	
}

bool Item::isSteppableByPlayer(){
	return false;;
}

bool Item::getActive(){
	return active;
}

void Item::setInactive(){
	//remove references
	cell->setItem(nullptr);
	cell = nullptr;
	position = nullptr;
	
	active = false;
}
