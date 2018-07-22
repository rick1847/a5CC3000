#ifndef CHARACTER_H
#define CHARACTER_H
#include "stats.h"
#include "coordinate.h"
#include "cell.h"


class Character {
	Stats *stats;
	Stats *baseStats;
	Coordinate *position;
	Cell *cell;
public:
	Character(Stats &s, Stats &bs, Coordinate &p, Cell &c);
	virtual ~Character() = 0;
	virtual void specialEffect(Vampire &to);
	virtual void specialEffect(Goblin &to);
	virtual void specialEffect(Drow &to);
	virtual void specialEffect(Character &to);
	void receiveEffect(Character &from);
	virtual char getAvatar();
	void attack(Character &who);
	virtual void takeHit(Character &from);
	Stats &getStats();
	Stats &getBaseStats();
	void changeStats(Stats &newS);
	virtual void die();
};


#endif
