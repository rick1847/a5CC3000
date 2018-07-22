#ifndef ELF_H
#define ELF_H
#include "enemyrace.h"


class Elf : public EnemyRace {
public:
	Elf(Coordinate &p, Cell &c);
	//attack each of the following races a second time
	void specialEffect(Vampire &to) override;
	void specialEffect(Goblin &to) override;
	//due to dynamic dispatch, this method is not used for drows - specialEffect(drow &) is used, and it does nothing
	void specialEffect(Character &to) override;
	char getAvatar() override;
	//call specialEffect() at end of this method
	void attack(Character &who) override;
};


#endif
