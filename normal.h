#ifndef NORMAL_H
#define NORMAL_H
#include "treasure.h"


class Normal : public Treasure {
	static const int amount = 2;
public:
	static int getAmount();
	void giveTreasure(PlayerRace &pl) override;
};


#endif
