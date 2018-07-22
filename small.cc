#include "small.h"


int Small::getAmount() {
	return amount;
}

void Small::giveTreasure(PlayerRace &pl) {
	pl.getStats.addGold(amount);
}
