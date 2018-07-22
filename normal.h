#ifndef NORMAL_H
#define NORMAL_H
#include "treasure.h"


class Normal : public Treasure {
	static const int amount = 2;
public:
	Normal(Coordinate &p, Cell &c);
	static int getAmount();
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
