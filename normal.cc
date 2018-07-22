#include "normal.h"


int Normal::getAmount() {
	return amount;
}

void Normal::giveTreasure(PlayerRace &pl) {
	pl.getStats.addGold(amount);
}
