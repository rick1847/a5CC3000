#include "shade.h"


Shade::Shade(Coordinate &p, Cell &c) : 
	PlayerRace(*(new Stats(125, 125, 25, 25)), *(new Stats(125, 125, 25, 25)), p, c)
{}
