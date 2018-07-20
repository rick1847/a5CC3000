#ifndef ___DUNGEON___H___
#define ___DUNGEON___H___

#include <vector>
#include <string>
#include <fstream>
#include "Floor/floor.h"
#include "Display/textDisplay.h"
#include "direction.h"


class TextDisplay;
class PlayerRace;

class Dungeon{
	TextDisplay *td;
	std::vector<std::vector<std::string>> FloorMaps;
	
	Floor *currentFloor;
	PlayerRace *player;
	std::string playerType;
	int level;
	
	void setup();
	
	public:
	Dungeon(std::ifstream &mapFile);
	
	void play();	
	void print();
	void chooseChar();
	void moveEnemies();
	void nextFloor();
	void victory();
	void reset();
	void moveChar(Direction dir);
	void usePot(Direction dir);
	void attack(Direction dir);
	void magic(Direction dir);
};

#endif
