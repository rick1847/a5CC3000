#ifndef PHEALTH_H
#define PHEALTH_H
#include "potion.h"


class PoisonHealth : public Potion {
	static bool known;
public:
	PoisonHealth(Coordinate &p, Cell &c);
	static bool isKnown();
	static void becomeKnown();
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
