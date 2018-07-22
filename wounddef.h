#ifndef WDEF_H
#define WDEF_H
#include "potion.h"


class WoundDEF : public Potion {
	static bool known;
public:
	WoundDEF(Coordinate &p, Cell &c);
	static bool isKnown();
	static void becomeKnown();
	//change player stats
	void myEffect(PlayerRace &pl) override;
	//reveal the type of potion if player has used it before
	std::string giveType() override;
};


#endif
