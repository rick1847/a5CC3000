#include "dwarf.h"

Dwarf::Dwarf(Coordinate &p, Cell &c) : EnemyRace(*(new Stats(100, 100, 20, 30)), *(new Stats(100, 100, 20, 30)), p, c)
{}

void Dwarf::specialEffect(Vampire &to) {
	Stats *newS = new Stats(to.getStats());
	newS->addHP(-10);
	to.changeStats(*newS);
}

char Dwarf::getAvatar() {
	return 'W';
}
