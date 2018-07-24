#ifndef HUMAN_H
#define HUMAN_H
#include "enemyrace.h"


class Human : public EnemyRace {
public:
	Human(Coordinate &p, Cell &c);
	//drop a second gold pile on death
	void specialEffect(Character &to) override;
	char getAvatar() override;

	void attack(Character &who) override;
	void takeHit(Character &from) override;
};


#endif
