#ifndef MHOARD_H
#define MHOARD_H
#include "treasure.h"


class MerchHoard : public Treasure {
	static const int amount = 4;
public:
	MerchHoard(Coordinate &p, Cell &c);
	static int getAmount();
	//give gold to player
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
