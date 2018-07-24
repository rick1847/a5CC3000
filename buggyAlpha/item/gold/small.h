#ifndef SMALL_H
#define SMALL_H
#include "treasure.h"


class Small : public Treasure {
	static const int amount = 1;
public:
	Small(Coordinate &p, Cell &c);
	static int getAmount();
	//give gold to player
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
