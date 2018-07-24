#ifndef ___DUNGEON___H___
#define ___DUNGEON___H___

#include <vector>
#include <string>
#include <fstream>
#include "map/Floor/floor.h"
#include "display/textDisplay.h"
#include "direction.h"
#include "character/character.h"

class Dungeon{
	bool randGen;
	TextDisplay *td;
	std::vector<std::vector<std::string>> FloorMaps;
	
	Floor *currentFloor;
	Coordinate *nextFloorLoc;
	PlayerRace *player;
	std::string playerType;
	int level;
	
	void setup();
	
	public:
	Dungeon(std::ifstream &mapFile, bool whatGen);
	
	void play();	
	void print();
	void chooseChar();
	void moveEnemies();
	void nextFloor();
	void victory();
	void reset();
	/*
	void moveChar(Direction dir);
	void usePot(Direction dir);
	void attack(Direction dir);
	void magic(Direction dir);*/
};

#endif
