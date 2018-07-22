#include "restorehealth.h"


bool RestoreHealth::isKnown() {
	return known;
}

void RestoreHealth::becomeKnown() {
	known = true;
}

void RestoreHealth::myEffect(PlayerRace &pl) {
	becomeKnown();
	pl.getStats().addHP(10);
	pl.getBaseStats().addHP(10);
}

std::string RestoreHealth::giveType() {
	if (isKnown()) {
		return "a healing potion (+10 to HP)";
	}
	else {
		return "an unknown potion";
	}
}
