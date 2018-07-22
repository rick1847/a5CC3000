#ifndef ITEM_H
#define ITEM_H
#include "playerrace.h"
#include <string>
#include "cell.h"


class Item {
	Coordinate *position;
	Cell *cell;
public:
	Item(Coordinate &p, Cell &c);
	virtual ~Item() = 0;
	virtual void myEffect(PlayerRace &pl);
	virtual std::string giveType();
	virtual char getAvatar();
};


#endif
