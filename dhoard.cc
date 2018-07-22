#include "dhoard.h"


DragonHoard::DragonHoard(Coordinate &p, Cell &c) : Treasure(p, c)
{}

int DragonHoard::getAmount() {
	return amount;
}

void DragonHoard::notifyDeath() {
	guardian = nullptr;
}

void DragonHoard::myEffect(PlayerRace &pl) {
	if (guardian) {
		pl.getStats.addGold(getAmount());
	}
}

std::string DragonHoard::giveType() {
	return "a large gold pile belonging to a dragon";
}
