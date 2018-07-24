#include "character.h"
#include <cstdlib>
#include <string>

#include<iostream>
using namespace std;

string whatDir(){
	
	int whichDir = rand() % 8;
	if(whichDir == 0){
		return "no";
	}
	else if(whichDir == 1){
		return "so";
	}
	else if(whichDir == 2){
		return "ea";
	}
	else if(whichDir == 3){
		return "we";
	}
	else if(whichDir == 4){
		return "ne";
	}
	else if(whichDir == 5){
		return "nw";
	}
	else if(whichDir == 6){
		return "se";
	}
	else if(whichDir == 7){
		return "sw";
	}
	
	//should never reach here
	return "";
	
}

Character::Character(Stats &s, Stats &bs, Coordinate &p, Cell &c) : stats(&s), baseStats(&bs), position(&p), cell(&c)
{}

Character::~Character() {
	delete stats;
	delete baseStats;
}

void Character::specialEffect(Vampire &to) {
	(void)to;
}

void Character::specialEffect(Goblin &to) {
	(void)to;
}

void Character::specialEffect(Drow &to) {
	(void)to;
}

void Character::specialEffect(Character &to) {
	(void)to;
}

void Character::receiveEffect(Character &from) {
	from.specialEffect(*this);
}

char Character::getAvatar() {
	return '.';
}

void Character::attack(Character &who) {
	//cout<<"I work"<<endl;
	who.takeHit(*this);
}

void Character::takeHit(Character &from) {
	int dmg = ceil(100 / (100 + stats->getDEF()) * from.getStats().getATK());
	stats->addHP(-dmg);
	
	//printStats();
}

Stats &Character::getStats() {
	return *stats;
}

Stats &Character::getBaseStats() {
	return *baseStats;
}

void Character::changeStats(Stats &newS) {
	delete stats;
	stats = &newS;
}

void Character::changeCell(Cell *whatCell){
	cell = whatCell;
}

void Character::die(){
	int whichDrop = rand() % 2;
	if (whichDrop == 0) {
		Small *drop = new Small(*position, *cell);
		cell->setItem(drop);
		cell->killCharacter();
	} else {
		Normal *drop = new Normal(*position, *cell);
		cell->setItem(drop);
		cell->killCharacter();
	}
}

void Character::move(){

	string dir = whatDir();

	cell->send(dir);
	position = cell->getPos();
}

Coordinate Character::getPos(){
	return *position;
}

void Character::printStats(){
	cout<<"Health: "<<stats->getHP()<<"/"<<stats->getMaxHP()<<"|";
	
	cout<<"Attack: "<<stats->getATK()<<"|";
	cout<<"Defense: "<<stats->getDEF()<<"|";
	cout<<"Gold: "<<stats->getGold()<<"|";
	cout<<"Position: ("<<position->getX()<<" "<<position->getY()<<")"<<endl;
}

bool Character::isPlayable(){
	return false;
}

bool Character::getActive(){
	return active;
}

void Character::setInactive(){
	//remove references
	cell->setCharacter(nullptr);
	cell = nullptr;
	delete stats;
	delete baseStats;
	position = nullptr;
	
	active = false;
}
	
