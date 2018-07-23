#include "woundatk.h"

bool WoundATK::known = false;

WoundATK::WoundATK(Coordinate &p, Cell &c) : Potion(p, c)
{}

bool WoundATK::isKnown() {
	return known;
}

void WoundATK::becomeKnown() {
	known = true;
}

void WoundATK::myEffect(PlayerRace &pl) {
	becomeKnown();
	pl.getStats().addATK(-5);
	disappear();
}

std::string WoundATK::giveType() {
	if (isKnown()) {
		return "a potion of weakness (-5 to ATK)";
	}
	else {
		return "an unknown potion";
	}
}
