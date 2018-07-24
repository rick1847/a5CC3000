#ifndef ___FLOOR___H___
#define ___FLOOR___H___

#include "../Cell/cell.h"
#include "chamber.h"
#include "../../coordinate.h"
#include "../../display/textDisplay.h"
#include "../../character/character.h"

#include<vector>
#include<string>

class Item;
class EnemyRace;
class PlayerRace;

const int maxEnemies = 20;
const int maxPotions = 10;
const int maxTreasure = 10;

class Floor{
	//read floor layout from file, or randomly generate it?
	bool randGen;
	std::vector<Cell*> cells;
	std::vector<Item*> items;
	std::vector<Character*> enemies;
	std::vector<Chamber*> chambers;
	TextDisplay *td;
	int spawnRoom = 0;
	Coordinate spawnLoc;
	Coordinate nextFloorLoc;

	void genPotionLoc();
	void genGoldLoc();
	void genMonsterLoc();
public:
	Floor(std::vector<std::string> plan, TextDisplay *td, bool whatGen);
	Cell *genPlayerLoc();
	void genFloor();
	Coordinate *genStairCase();
	void deleteEnemy(EnemyRace *which);
	void deleteItem(Item *which);
	void NotifyCell(Coordinate coord);
	void NotifyGold(Coordinate coord);
	void NotifyItems();
	bool ValidMove(Coordinate coord);
	void moveEnemies();
	void bloom();
	void readEntities(std::vector<std::string> plan);
	void refresh();
	void reactEnemies(Character *character);
	void cleanup();
};

void reqCellsInChamber(Coordinate *coord, std::vector<std::string> plan, std::vector<Coordinate*> &chamberCoords);

#endif
