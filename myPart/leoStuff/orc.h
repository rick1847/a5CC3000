#ifndef ORC_H
#define ORC_H
#include "enemyrace.h"


class Orc : public EnemyRace {
public:
	Orc(Coordinate &p, Cell &c);
	//do 1.5x damage
	void specialEffect(Goblin &to) override;
	char getAvatar() override;
	//call specialEffect() at end of this method
	void attack(Character &who) override;
};


#endif
