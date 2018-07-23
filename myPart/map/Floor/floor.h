#ifndef ___FLOOR___H___
#define ___FLOOR___H___

#include "../../subject.h"
#include "../../observer.h"
#include "../Cell/cell.h"
#include "chamber.h"
#include "../../coordinate.h"
#include "../../display/textDisplay.h"

#include<vector>
#include<string>

class Item;
class EnemyRace;
class PlayerRace;


class Floor{
	
	bool randGen;
	
	const int maxEnemies = 20;
	const int maxPotions = 10;
	const int maxTreasure = 10;
	std::vector<Cell*> cells;
	std::vector<Item*> items;
	std::vector<EnemyRace*> enemies;
	std::vector<Chamber*> chambers;

	TextDisplay *td;
	
	int spawnRoom = 0;
	
	void genPotionLoc();
	void genGoldLoc();
	void genMonsterLoc();

	Coordinate spawnLoc;
	Coordinate nextFloorLoc;
	
	void readEntities(std::vector<std::string> plan);
	public:
	
	Floor(std::vector<std::string> plan, TextDisplay *td, bool whatGen);
	
	void react(PlayerRace *player);
	void notifyItem(Coordinate nextPos, PlayerRace *player);
	void print();
	//void notify(Subject &whoFrom) override;
	void genFloor();
	void moveEnemies();
	void deleteEnemy(EnemyRace *which);
	void deleteItem(Item *which);
	void NotifyCell(Coordinate coord);
	void NotifyGold(Coordinate coord);
	void NotifyItems();
	bool ValidMove(Coordinate coord);
	
	void printChamber(int i);
	void bloom();
	
	
	Coordinate genNextFloorLoc();
	Cell *genPlayerLoc();

};

#endif
