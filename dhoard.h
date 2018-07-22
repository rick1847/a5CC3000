#ifndef DHOARD_H
#define DHOARD_H
#include "treasure.h"
#include "dragon.h"


class DragonHoard : public Treasure {
	static const int amount = 6;
	Dragon *guardian;
public:
	static int getAmount();
	void notifyDeath();
	void giveTreasure(PlayerRace &pl) override;
};


#endif
