#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemyrace.h"


class Merchant : public EnemyRace {
	
public:
	static bool hostile;
	Merchant(Coordinate &p, Cell &c);
	static bool isHostile();
	static void becomeHostile();
	//make merchants hostile
	void takeHit(Character &from) override;
	char getAvatar() override;
};


#endif
