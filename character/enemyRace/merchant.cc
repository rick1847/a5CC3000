#include "merchant.h"
#include <math.h>

bool Merchant::hostile = false;
Merchant::Merchant(Coordinate &p, Cell &c) : EnemyRace(*(new Stats(30, 30, 70, 5)), *(new Stats(30, 30, 70, 5)), p, c)
{}

bool Merchant::isHostile() {
	return hostile;
}

void Merchant::becomeHostile() {
	hostile = true;
}

void Merchant::takeHit(Character &from) {
	becomeHostile();
	int dmg = ceil(100 / (100 + getStats().getDEF()) * from.getStats().getATK());
	getStats().addHP(-dmg);
}

char Merchant::getAvatar() {
	return 'M';
}
