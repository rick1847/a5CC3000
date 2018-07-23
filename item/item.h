#ifndef ITEM_H
#define ITEM_H
#include "../character/playerRace/playerrace.h"
#include <string>
#include "../map/Cell/cell.h"


class Item {
	Coordinate *position;
	//the cell the item is on
	Cell *cell;
public:
	Item(Coordinate &p, Cell &c);
	virtual ~Item() = 0;
	//adjust player stats
	virtual void myEffect(PlayerRace &pl);
	//handle non-player character interacting with item
	virtual void myEffect(Character &c);
	//text display will say what the player is looking at
	virtual std::string giveType();
	//text display represents item using a char - see CC3K specification
	virtual char getAvatar();
	//virtual static bool isKnown() = 0;
	Coordinate &getPos();
	void disappear();
};


#endif
