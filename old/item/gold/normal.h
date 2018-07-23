#ifndef NORMAL_H
#define NORMAL_H
#include "treasure.h"


class Normal : public Treasure {
	static const int amount = 2;
public:
	Normal(Coordinate &p, Cell &c);
	static int getAmount();
	//give gold to player
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
