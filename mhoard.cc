#include "mhoard.h"


int MerchHoard::getAmount() {
	return amount;
}

void MerchHoard::giveTreasure(PlayerRace &pl) {
	pl.getStats.addGold(amount);
}
