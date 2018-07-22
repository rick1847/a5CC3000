#ifndef BDEF_H
#define BDEF_H
#include "potion.h"


class BoostDEF : public Potion {
	static bool known;
public:
	BoostDEF(Coordinate &p, Cell &c);
	static bool isKnown();
	static void becomeKnown();
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
