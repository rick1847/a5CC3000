#include "halfling.h"
#include <cstdlib>

Halfling::Halfling(Coordinate &p, Cell &c) : EnemyRace(*(new Stats(100, 100, 15, 20)), *(new Stats(100, 100, 15, 20)), p, c)
{}

void Halfling::takeHit(Character &from) {
	int hitChance = rand() % 2;
	if (hitChance == 0) {
		int dmg = ceil(100 / (100 + getStats().getDEF()) * from.getStats().getATK());
		getStats().addHP(-dmg);
	}
}

char Halfling::getAvatar() {
	return 'L';
}
