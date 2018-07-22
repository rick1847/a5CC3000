#ifndef HUMAN_H
#define HUMAN_H
#include "enemyrace.h"


class Human : public EnemyRace {
public:
	Human(Coordinate &p, Cell &c);
	void specialEffect(Character &to) override;
	char getAvatar() override;
};


#endif
