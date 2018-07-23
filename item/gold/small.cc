#include "small.h"


Small::Small(Coordinate &p, Cell &c) : Treasure(p, c)
{}

int Small::getAmount() {
	return amount;
}

void Small::myEffect(PlayerRace &pl) {
	pl.getStats().addGold(getAmount());
	disappear();
}

std::string Small::giveType() {
	return "a small pile of gold";
}
