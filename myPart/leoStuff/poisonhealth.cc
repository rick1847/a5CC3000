#include "poisonhealth.h"


PoisonHealth::PoisonHealth(Coordinate &p, Cell &c) : Potion(p, c)
{}

bool PoisonHealth::isKnown() {
	return known;
}

void PoisonHealth::becomeKnown() {
	known = true;
}

void PoisonHealth::myEffect(PlayerRace &pl) {
	becomeKnown();
	pl.getStats().addHP(-10);
	pl.getBaseStats().addHP(-10);
}

std::string PoisonHealth::giveType() {
	if (isKnown()) {
		return "a poisonous potion (-10 to HP)";
	}
	else {
		return "an unknown potion";
	}
}
