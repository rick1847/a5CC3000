#ifndef DWARF_H
#define DWARF_H
#include "enemyrace.h"


class Dwarf : public EnemyRace {
public:
	Dwarf(Coordinate &p, Cell &c);
	//if there is a vampire, hurt it
	void specialEffect(Vampire &to) override;
	char getAvatar() override;
	//call specialEffect at the end of this method
	//void move() override;
};


#endif
