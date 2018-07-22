#ifndef RHEALTH_H
#define RHEALTH_H
#include "potion.h"


class RestoreHealth : public Potion {
	static bool known;
public:
	static bool isKnown();
	static void becomeKnown();
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
