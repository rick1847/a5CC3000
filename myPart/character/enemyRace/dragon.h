#ifndef DRAGON_H
#define DRAGON_H
#include "enemyrace.h"
//#include "../../item/gold/dhoard.h"

class DragonHoard;

class Dragon : public EnemyRace {
	//assign each dragon a special gold stash
	DragonHoard *stash;
public:
	Dragon(Coordinate &p, Cell &c, DragonHoard &dh);
	char getAvatar() override;
	//this should do nothing
	void move() override;
};


#endif
