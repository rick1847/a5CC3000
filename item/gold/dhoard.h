#ifndef DHOARD_H
#define DHOARD_H
#include "treasure.h"

//#include "../../character/enemyRace/dragon.h"

class Dragon;

class DragonHoard : public Treasure {
	static const int amount = 6;
	//each dragon hoard is guarded by exactly 1 dragon
	Dragon *guardian;
public:
	DragonHoard(Coordinate &p, Cell &c);
	static int getAmount();
	void addGuardian(Dragon &d);
	//remove dragon
	void notifyDeath();
	//give gold only if not guarded
	void myEffect(PlayerRace &pl) override;
	std::string giveType() override;
};


#endif
