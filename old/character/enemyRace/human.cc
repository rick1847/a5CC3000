#include "human.h"

Human::Human(Coordinate &p, Cell &c) : EnemyRace(*(new Stats(140, 140, 20, 20)), *(new Stats(140, 140, 20, 20)), p, c)
{}

void Human::specialEffect(Character &to) {
	(void)to;

}

char Human::getAvatar() {
	return 'H';
}