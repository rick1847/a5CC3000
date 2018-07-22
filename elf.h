#ifndef ELF_H
#define ELF_H
#include "enemyrace.h"


class Elf : public EnemyRace {
public:
	Elf(Coordinate &p, Cell &c);
	void specialEffect(Vampire &to) override;
	void specialEffect(Goblin &to) override;
	void specialEffect(Character &to) override;
	char getAvatar() override;
};


#endif
