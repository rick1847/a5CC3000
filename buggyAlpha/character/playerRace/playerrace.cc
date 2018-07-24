#include "playerrace.h"
#include "../../item/item.h"
#include <cstdlib>

using namespace std;

PlayerRace::PlayerRace(Stats &s, Stats &bs, Coordinate &p, Cell &c) : Character(s, bs, p, c)
{}

PlayerRace::~PlayerRace() {
}

void PlayerRace::takeHit(Character &from) {
	int hitChance = rand() % 2;
	if (hitChance == 0) {
		double c100 = 100;
		int dmg = ceil(c100 / (c100 + getStats().getDEF()) * from.getStats().getATK());
		getStats().addHP(-dmg);
	}
}

char PlayerRace::getAvatar() {
	return '@';
}

void PlayerRace::move(string dir){
	cell->send(dir);
	position = cell->getPos();
}

Cell *PlayerRace::getCell(){
	return cell;
}

void PlayerRace::setCell(Cell *newCell){
	cell = newCell;
	position = cell->getPos();
}

bool PlayerRace::isPlayable(){
	return true;
}

#include<iostream>
void PlayerRace::usePot(std::string dir){
	Item *item = cell->getItemInDir(dir);
	
	std::cout<<item->isSteppableByPlayer();
	if(item){
		item->pickupEffect(*this);
	}
}

void PlayerRace::attackInDir(string dir){
	Character *character = cell->getCharacterInDir(dir);
	
	if(character){
		this->attack(*character);
	}
}
