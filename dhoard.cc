#include "dhoard.h"


int DragonHoard::getAmount() {
	return amount;
}

void DragonHoard::notifyDeath() {
	guardian = nullptr;
}

void DragonHoard::giveTreasure(PlayerRace &pl) {
	pl.getStats.addGold(amount);
}
