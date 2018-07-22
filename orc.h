#ifndef ORC_H
#define ORC_H
#include "enemyrace.h"


class Orc : public EnemyRace {
public:
	Orc(Coordinate &p, Cell &c);
	void specialEffect(Goblin &to) override;
	char getAvatar() override;
};


#endif
