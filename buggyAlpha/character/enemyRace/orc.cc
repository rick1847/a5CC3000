#include "orc.h"
#include "../playerRace/goblin.h"
Orc::Orc(Coordinate &p, Cell &c) : EnemyRace(*(new Stats(180, 180, 30, 25)), *(new Stats(180, 180, 30, 25)), p, c)
{}

void Orc::specialEffect(Goblin &to) {
	int half_dmg = ceil(100 / (100 + getStats().getDEF()) * to.getStats().getATK());
	to.getStats().addHP(-half_dmg);
}

char Orc::getAvatar() {
	return 'O';
}

void Orc::attack(Character &who){
	
}
