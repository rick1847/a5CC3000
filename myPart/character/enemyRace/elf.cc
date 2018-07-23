#include "elf.h"

#include<iostream>
Elf::Elf(Coordinate &p, Cell &c) : EnemyRace(*(new Stats(140, 140, 30, 10)), *(new Stats(140, 140, 30, 10)), p, c)
{}

void Elf::specialEffect(Vampire &to) {
	std::cout<<"not working"<<std::endl;
	//attack(to);
}

void Elf::specialEffect(Goblin &to) {
	std::cout<<"not working"<<std::endl;
	//attack(to);
}

void Elf::specialEffect(Character &to) {
	std::cout<<"not working"<<std::endl;
	//attack(to);
}

char Elf::getAvatar() {
	return 'E';
}

void Elf::attack(Character &who) {
	who.takeHit(*this);
	specialEffect(who);
}
