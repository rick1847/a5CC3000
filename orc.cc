#include "orc.h"

Orc::Orc(Coordinate &p, Cell &c) : EnemyRace(*(new Stats(180, 180, 30, 25)), *(new Stats(180, 180, 30, 25)), p, c)
{}

void Orc::specialEffect(Goblin &to) {

}

char Orc::getAvatar() {
	return 'O';
}
