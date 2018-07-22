#include "dragon.h"


Dragon::Dragon(Coordinate &p, Cell &c, DragonHoard &dh) : 
	EnemyRace(*(new Stats(150, 150, 20, 20)), *(new Stats(150, 150, 20, 20)), p, c), stash(&dh)
{}

Dragon::~Dragon() {
	stash->notifyDeath();
}

char Dragon::getAvatar() {
	return 'D';
}
