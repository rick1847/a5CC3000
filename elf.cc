#include "elf.h"

Elf::Elf(Coordinate &p, Cell &c) : EnemyRace(*(new Stats(140, 140, 30, 10)), *(new Stats(140, 140, 30, 10)), p, c)
{}

void Elf::specialEffect(Vampire &to) {
	attack(to);
}

void Elf::specialEffect(Goblin &to) {
	attack(to);
}

void Elf::specialEffect(Character &to) {
	attack(to);
}

char Elf::getAvatar() {
	return 'E';
}
