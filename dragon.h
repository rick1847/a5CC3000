#ifndef DRAGON_H
#define DRAGON_H
#include "enemyrace.h"
#include "dhoard.h"


class Dragon : public EnemyRace {
	DragonHoard *stash;
public:
	Dragon(Coordinate &p, Cell &c, DragonHoard &dh);
	~Dragon();
	char getAvatar() override;
};


#endif
