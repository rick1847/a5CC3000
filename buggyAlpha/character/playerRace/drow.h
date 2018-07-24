#ifndef DROW_H
#define DROW_H
#include "playerrace.h"


class Drow : public PlayerRace {
public:
	Drow(Coordinate &p, Cell &c);
	~Drow();
	//param is itself
	virtual void specialEffect(Drow &to) override;

	//void takeHit(Character &from);
	void die() override;
	//NOT IMPLEMENTED YET, MUST BE OVERRIDDEN FOR EACH CONCRETE CLASS
	void move() override;
};


#endif
