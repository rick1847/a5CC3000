#include "stats.h"

Stats::Stats(int hp = 125, int mhp = 125, int a = 25, int d = 25):
	HP(hp), maxHP(mhp), attack(a), defence(d), gold(0) 
{}

Stats::Stats(Stats &s):
	HP(s.getHP()), maxHP(s.getMaxHP()), attack(s.getATK()), defence(s.getDEF()), gold(s.getGold())
{}

int Stats::getHP() {
	return HP;
}

int Stats::getMaxHP() {
	return maxHP;
}

int Stats::getATK() {
	return attack;
}

int Stats::getDEF() {
	return defence;
}

int Stats::getGold() {
	return gold;
}

void Stats::addHP(int amt) {
	HP += amt;
	if (HP > maxHP) {
		HP = maxHP;
	}
	if (HP < minHP) {
		HP = minHP;
	}
}

void Stats::addATK(int amt) {
	attack += amt;
	if (attack < minATK) {
		attack = minATK;
	}
}

void Stats::addDEF(int amt) {
	defence += amt;
	if (defence < minDEF) {
		defence = minDEF;
	}
}

void Stats::addGold(int amt) {
	gold += amt;
}