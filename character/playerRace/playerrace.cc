#include "playerrace.h"
#include <cstdlib>


PlayerRace::PlayerRace(Stats &s, Stats &bs, Coordinate &p, Cell &c) : Character(s, bs, p, c)
{}

PlayerRace::~PlayerRace() {
}

void PlayerRace::takeHit(Character &from) {
	int hitChance = rand() % 2;
	if (hitChance == 0) {
		int dmg = ceil(100 / (100 + getStats().getDEF()) * from.getStats().getATK());
		getStats().addHP(-dmg);
	}
}

char PlayerRace::getAvatar() {
	return '@';
}

void PlayerRace::move(char dir){
	cell->send(dir);
	position = cell->getPosPtr();
}
