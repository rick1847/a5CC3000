#include "wounddef.h"


WoundDEF::WoundDEF(Coordinate &p, Cell &c) : Potion(p, c)
{}

bool WoundDEF::isKnown() {
	return known;
}

void WoundDEF::becomeKnown() {
	known = true;
}

void WoundDEF::myEffect(PlayerRace &pl) {
	becomeKnown();
	pl.getStats().addDEF(-5);
}

std::string WoundDEF::giveType() {
	if (isKnown()) {
		return "a potion of frailty (-5 to DEF)";
	}
	else {
		return "an unknown potion";
	}
}
