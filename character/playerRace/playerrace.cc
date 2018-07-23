#include "playerrace.h"
#include <cstdlib>

using namespace std;

PlayerRace::PlayerRace(Stats &s, Stats &bs, Coordinate &p, Cell &c) : Character(s, bs, p, c)
{}

PlayerRace::~PlayerRace() {
}

void PlayerRace::takeHit(Character &from) {
	int hitChance = rand() % 2;
	if (hitChance == 0) {
		double c100 = 100;
		int dmg = ceil(c100 / (c100 + getStats().getDEF()) * from.getStats().getATK());
		getStats().addHP(-dmg);
	}
}

char PlayerRace::getAvatar() {
	return '@';
}

void PlayerRace::move(string dir){
	cell->send(dir);
	position = cell->getPosPtr();
}

Cell *PlayerRace::getCell(){
	return cell;
}
