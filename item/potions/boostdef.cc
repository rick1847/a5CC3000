#include "boostdef.h"

bool BoostDEF::known = false;

BoostDEF::BoostDEF(Coordinate &p, Cell &c) : Potion(p, c)
{}

bool BoostDEF::isKnown() {
	return known;
}

void BoostDEF::becomeKnown() {
	known = true;
}

void BoostDEF::myEffect(PlayerRace &pl) {
	becomeKnown();
	pl.getStats().addDEF(5);
}

std::string BoostDEF::giveType() {
	if (isKnown()) {
		return "a potion of fortitude (+5 to DEF)";
	}
	else {
		return "an unknown potion";
	}
}
