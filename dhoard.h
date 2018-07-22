#ifndef DHOARD_H
#define DHOARD_H
#include "treasure.h"
#include "dragon.h"


class DragonHoard : public Treasure {
	static const int amount = 6;
	Dragon *guardian;
public:
	DragonHoard(Coordinate &p, Cell &c);
	static int getAmount();
	void notifyDeath();
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
