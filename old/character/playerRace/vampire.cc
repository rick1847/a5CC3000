#include "vampire.h"


Vampire::Vampire(Coordinate &p, Cell &c) : 
	PlayerRace(*(new Stats(50, 2147483647, 25, 25)), *(new Stats(50, 2147483647, 25, 25)), p, c)
{}

void Vampire::specialEffect(Vampire &to) {
	(void)to;
	getStats().addHP(5);
}
