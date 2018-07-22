#ifndef TREASURE_H
#define TREASURE_H
#include "item.h"


class Treasure : public Item {
public:
	Treasure(Coordinate &p, Cell &c);
	virtual ~Treasure() = 0;
	char getAvatar() override;
};


#endif
