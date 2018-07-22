#include "troll.h"


Troll::Troll(Coordinate &p, Cell &c) : 
	PlayerRace(*(new Stats(120, 120, 25, 25)), *(new Stats(120, 120, 25, 25)), p, c)
{}

void Troll::specialEffect(Character &to) {
	(void)to;
	getStats().addHP(5);
}
