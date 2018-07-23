#include "drow.h"


Drow::Drow(Coordinate &p, Cell &c) : 
	PlayerRace(*(new Stats(150, 150, 25, 15)), *(new Stats(150, 150, 25, 15)), p, c)
{}

Drow::~Drow(){
	
}

void Drow::specialEffect(Drow &to){
	
}

void Drow::die(){
	
}

void Drow::move(){
	
}
