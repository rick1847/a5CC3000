#ifndef ITEM_H
#define ITEM_H
#include "../character/playerRace/playerrace.h"
#include <string>
#include "../map/Cell/cell.h"


class Item {
	Coordinate *position;
	
	//the cell the item is on
	Cell *cell;
	//is the item unused
	bool active = true;
public:
	Item(Coordinate &p, Cell &c);
	virtual ~Item() = 0;
	//adjust player stats
	virtual void myEffect(PlayerRace &pl);
	//text display will say what the player is looking at
	virtual std::string giveType();
	//text display represents item using a char - see CC3K specification
	virtual char getAvatar();

	//virtual static bool isKnown() = 0;
	Coordinate getPos();
	
	//need a pickup effect for our potion
	virtual void pickupEffect(PlayerRace &pl);
	
	virtual bool isSteppableByPlayer();
	
	bool getActive();
	void setInactive(); //tells everyone its ready for cleanup
};


#endif
