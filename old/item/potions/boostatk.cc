#include "boostatk.h"

bool BoostATK::known = false;

BoostATK::BoostATK(Coordinate &p, Cell &c) : Potion(p, c)
{}

bool BoostATK::isKnown() {
	return known;
}

void BoostATK::becomeKnown() {
	known = true;
}

void BoostATK::myEffect(PlayerRace &pl) {
	becomeKnown();
	pl.getStats().addATK(5);
}

std::string BoostATK::giveType() {
	if (isKnown()) {
		return "a potion of strength (+5 to ATK)";
	}
	else {
		return "an unknown potion";
	}
}

