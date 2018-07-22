#include "dragon.h"


Dragon::Dragon(Coordinate &p, Cell &c, DragonHoard &dh) : 
	EnemyRace(*(new Stats(150, 150, 20, 20)), *(new Stats(150, 150, 20, 20)), p, c), stash(&dh) 
{
	dh.addGuardian(*this);
}

char Dragon::getAvatar() {
	return 'D';
}

void Dragon::move() {
	//this is supposed to do nothing
}
