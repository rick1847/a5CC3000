#include "goblin.h"


Goblin::Goblin(Coordinate &p, Cell &c) : 
	PlayerRace(*(new Stats(110, 110, 15, 20)), *(new Stats(110, 110, 15, 20)), p, c)
{}

void Goblin::specialEffect(Character &to) {
	(void)to;
	getStats().addGold(5);
}
