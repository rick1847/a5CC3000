#ifndef SMALL_H
#define SMALL_H
#include "treasure.h"


class Small : public Treasure {
	static const int amount = 1;
public:
	Small(Coordinate &p, Cell &c);
	static int getAmount();
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
