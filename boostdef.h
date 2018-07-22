#ifndef BDEF_H
#define BDEF_H
#include "potion.h"


class BoostDEF : public Potion {
	static bool known;
public:
	BoostDEF(Coordinate &p, Cell &c);
	static bool isKnown();
	static void becomeKnown();
	//change player stats
	void myEffect(PlayerRace &pl) override;
	//reveal the type of potion if player has used it before
	std::string giveType() override;
};


#endif
