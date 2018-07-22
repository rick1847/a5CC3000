#ifndef TROLL_H
#define TROLL_H
#include "playerrace.h"


class Troll : public PlayerRace {
public:
	Troll(Coordinate &p, Cell &c);
	virtual void specialEffect(Character &to) override;
};


#endif
