#ifndef BATK_H
#define BATK_H
#include "potion.h"


class BoostATK : public Potion {
	static bool known;
public:
	static bool isKnown();
	static void becomeKnown();
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
