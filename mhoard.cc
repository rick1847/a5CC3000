#include "mhoard.h"


MerchHoard::MerchHoard(Coordinate &p, Cell &c) : Treasure(p, c)
{}

int MerchHoard::getAmount() {
	return amount;
}

void MerchHoard::myEffect(PlayerRace &pl) {
	pl.getStats.addGold(getAmount());
}

std::string MerchHoard::giveType() {
	return "a gold stash belonging to a dead merchant";
}
