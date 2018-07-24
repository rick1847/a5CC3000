#include "human.h"


Human::Human(Coordinate &p, Cell &c) : EnemyRace(*(new Stats(1, 140, 20, 20)), *(new Stats(140, 140, 20, 20)), p, c)
{}

void Human::specialEffect(Character &to) {
	(void)to;

}

char Human::getAvatar() {
	return 'H';
}

#include<iostream>
using namespace std;

void Human::attack(Character &who) {
	cout<<"I work"<<endl;
	who.printStats();
	who.takeHit(*this);
}

void Human::takeHit(Character &from) {
	int dmg = ceil(100 / (100 + stats->getDEF()) * from.getStats().getATK());
	
	dmg = 100;
	stats->addHP(-1 * dmg);
	
	if(stats->getHP() < 1) setInactive();
	printStats();
}
