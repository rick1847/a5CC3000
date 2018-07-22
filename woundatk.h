#ifndef WATK_H
#define WATK_H
#include "potion.h"


class WoundATK : public Potion {
	static bool known;
public:
	WoundATK(Coordinate &p, Cell &c);
	static bool isKnown();
	static void becomeKnown();
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
