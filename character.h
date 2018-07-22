#ifndef CHARACTER_H
#define CHARACTER_H
#include "stats.h"
#include "coordinate.h"
#include "cell.h"
#include <math.h>


class Character {
	Stats *stats;
	//stats will reset to base values at the end of the floor
	//(permanent modifiers will modify baseStats in addition to stats)
	Stats *baseStats;
	Coordinate *position;
	//the cell the character is standing on
	Cell *cell;
public:
	Character(Stats &s, Stats &bs, Coordinate &p, Cell &c);
	virtual ~Character() = 0;
	virtual void specialEffect(Vampire &to);
	virtual void specialEffect(Goblin &to);
	virtual void specialEffect(Drow &to);
	//execute only if none of the above methods can be used
	virtual void specialEffect(Character &to);
	//enable double dispatch
	void receiveEffect(Character &from);
	//char used to represent character in text display - see CC3K specifications to know the avatars for each race
	virtual char getAvatar();
	virtual void attack(Character &who);
	//not for double dispatch, but for damage calculation
	virtual void takeHit(Character &from);
	Stats &getStats();
	Stats &getBaseStats();
	void changeStats(Stats &newS);
	//NOT IMPELEMENTED YET, MUST BE OVERRIDDEN FOR EACH CONCRETE CLASS
	virtual void die();
	//NOT IMPLEMENTED YET, MUST BE OVERRIDDEN FOR EACH CONCRETE CLASS
	virtual void move();
};


#endif
