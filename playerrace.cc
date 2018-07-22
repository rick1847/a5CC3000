#include "playerrace.h"
#include <cstdlib>


PlayerRace::PlayerRace(Stats &s, Stats &bs, Coordinate &p, Cell &c) : Character(s, bs, p, c)
{}

PlayerRace::~PlayerRace() {
}

void PlayerRace::potionEffect(Potion &p) {
	p.myEffect(stats);
}

void PlayerRace::takeHit(Character &from) {
	int hitChance = rand() % 2;
	if (hitChance == 0) {
		int dmg = ceil(100 / (100 + stats->getDEF()) * from.getStats().getATK());
		stats->addHP(-dmg);
	}
}

char PlayerRace::getAvatar() {
	return '\@';
}

void PlayerRace::move() {

}
