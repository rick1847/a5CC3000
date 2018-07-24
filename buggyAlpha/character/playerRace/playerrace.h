#ifndef PLAYERRACE_H
#define PLAYERRACE_H
#include "../character.h"
#include <string>


class PlayerRace : public Character {
public:
	PlayerRace(Stats &s, Stats &bs, Coordinate &p, Cell &c);
	virtual ~PlayerRace() = 0;
	char getAvatar() override;
	void takeHit(Character &from) override;

	void move(std::string dir);
	Cell *getCell();
	void setCell(Cell *newCell);
	
	bool isPlayable() override;
	
	void usePot(std::string dir);
	void attackInDir(std::string dir);
};


#endif
