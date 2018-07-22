#ifndef GOBLIN_H
#define GOBLIN_H
#include "playerrace.h"


class Goblin : public PlayerRace {
public:
	Goblin(Coordinate &p, Cell &c);
	//param is itself
	virtual void specialEffect(Character &to) override;
};


#endif
