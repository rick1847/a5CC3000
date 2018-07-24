#ifndef POTION_H
#define POTION_H
#include "../item.h"
#include "../../stats.h"


class Potion : public Item {
public:
	Potion(Coordinate &p, Cell &c);
	virtual ~Potion() = 0;
	char getAvatar() override;

	void pickupEffect(PlayerRace &pl) override;
	//virtual bool isKnown() = 0;
};


#endif
