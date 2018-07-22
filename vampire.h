#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "playerrace.h"


class Vampire : public PlayerRace {
public:
	Vampire(Coordinate &p, Cell &c);
	virtual void specialEffect(Vampire &to) override;
};


#endif
