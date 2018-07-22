#ifndef SMALL_H
#define SMALL_H
#include "treasure.h"


class Small : public Treasure {
	static const int amount = 1;
public:
	static int getAmount();
	void giveTreasure(PlayerRace &pl) override;
};


#endif
