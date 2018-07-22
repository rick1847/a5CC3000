#ifndef WDEF_H
#define WDEF_H
#include "potion.h"


class WoundDEF : public Potion {
	static bool known;
public:
	static bool isKnown();
	static void becomeKnown();
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
