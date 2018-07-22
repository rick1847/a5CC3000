#ifndef DWARF_H
#define DWARF_H
#include "enemyrace.h"


class Dwarf : public EnemyRace {
public:
	Dwarf(Coordinate &p, Cell &c);
	void specialEffect(Vampire &to) override;
	char getAvatar() override;
};


#endif
