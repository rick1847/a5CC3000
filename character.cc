#include "character.h"



Character::Character(Stats &s, Stats &bs, Coordinate &p, Cell &c) : stats(&s), baseStats(&bs), position(&p), cell(&c)
{}

Character::~Character() {
	delete stats;
	delete baseStats;
}

void Character::specialEffect(Vampire &to) {
	(void)to;
}

void Character::specialEffect(Goblin &to) {
	(void)to;
}

void Character::specialEffect(Drow &to) {
	(void)to;
}

void Character::specialEffect(Character &to) {
	(void)to;
}

void Character::receiveEffect(Character &from) {
	from.specialEffect(*this);
}

char Character::getAvatar() {
	return '.';
}

void Character::attack(Character &who) {
	who.takeHit(*this);
}

void Character::takeHit(Character &from) {
	int dmg = ceil(100 / (100 + stats->getDEF()) * from.getStats().getATK());
	stats->addHP(-dmg);
}

Stats &Character::getStats() {
	return *stats;
}

Stats &Character::getBaseStats() {
	return *baseStats;
}

void Character::changeStats(Stats &newS) {
	delete stats;
	stats = &newS;
}
