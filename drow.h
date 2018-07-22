#ifndef DROW_H
#define DROW_H
#include "playerrace.h"


class Drow : public PlayerRace {
public:
	Drow(Coordinate &p, Cell &c);
	//param is itself
	virtual void specialEffect(Drow &to) override;
};


#endif
