#ifndef ENEMYRACE_H
#define ENEMYRACE_H
#include "../character.h"


class EnemyRace: public Character {
public:
	EnemyRace(Stats &s, Stats &bs, Coordinate &p, Cell &c);
	virtual ~EnemyRace() = 0;
};


#endif

