#ifndef MHOARD_H
#define MHOARD_H
#include "treasure.h"


class MerchHoard : public Treasure {
	static const int amount = 4;
public:
	static int getAmount();
	void giveTreasure(PlayerRace &pl) override;
};


#endif
