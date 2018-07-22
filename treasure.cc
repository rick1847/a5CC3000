#include "treasure.h"


Treasure::Treasure(Coordinate &p, Cell &c) : Item(p, c)
{}

Treasure::~Treasure() {
}

void Treasure::giveTreasure(PlayerRace &pl) {
	(void)pl;
}
