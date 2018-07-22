#ifndef ITEM_H
#define ITEM_H
#include "playerrace.h"
#include <string>
#include "cell.h"


class Item {
	Coordinate *position;
	//the cell the item is on
	Cell *cell;
public:
	Item(Coordinate &p, Cell &c);
	virtual ~Item() = 0;
	//adjust player stats
	virtual void myEffect(PlayerRace &pl);
	//text display will say what the player is looking at
	virtual std::string giveType();
	//text display represents item using a char - see CC3K specification
	virtual char getAvatar();
};


#endif
