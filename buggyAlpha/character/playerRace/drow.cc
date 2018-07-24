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

#include <iostream>
using namespace std;
/*
void Drow::takeHit(Character &from) {
	//necessary as c++ treats 100 as an integer
	double test = 100;
	
	int dmg = ceil(test / (test + stats->getDEF()) * from.getStats().getATK());
	stats->addHP(-1 * dmg);
	
	cout<<dmg<<endl;
	printStats();
}

*/
