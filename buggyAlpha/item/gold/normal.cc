#include "normal.h"


Normal::Normal(Coordinate &p, Cell &c) : Treasure(p, c)
{}

int Normal::getAmount() {
	return amount;
}

void Normal::myEffect(PlayerRace &pl) {
	pl.getStats().addGold(getAmount());
}

std::string Normal::giveType() {
	return "a moderate pile of gold";
}
