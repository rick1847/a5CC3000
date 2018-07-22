#ifndef HALFLING_H
#define HALFLING_H
#include "enemyrace.h"


class Halfling : public EnemyRace {
public:
	Halfling(Coordinate &p, Cell &c);
	//implement 50% chance to miss
	void takeHit(Character &from) override;
	char getAvatar() override;
};


#endif
