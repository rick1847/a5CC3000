#ifndef PLAYERRACE_H
#define PLAYERRACE_H
#include "../character.h"



class PlayerRace : public Character {
public:
	PlayerRace(Stats &s, Stats &bs, Coordinate &p, Cell &c);
	virtual ~PlayerRace() = 0;
	char getAvatar() override;
	void takeHit(Character &from) override;
};


#endif
