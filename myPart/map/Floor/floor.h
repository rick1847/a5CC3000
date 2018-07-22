#ifndef ___FLOOR___H___
#define ___FLOOR___H___

#include "../subject.h"
#include "../observer.h"
#include "../Cell/cell.h"
#include "chamber.h"
#include "../coordinates.h"
#include "../Display/textDisplay.h"

#include<vector>
#include<string>

class Item;
class EnemyRace;
class PlayerRace;


class Floor: public Observer{
	
	bool randGen;
	
	const int maxEnemies = 20;
	const int maxPotions = 10;
	const int maxTreasure = 10;
	std::vector<Cell*> passages;
	std::vector<Item*> items;
	std::vector<EnemyRace*> enemies;
	std::vector<Chamber*> chambers;

	TextDisplay *td;
	
	int spawnRoom = 0;
	
	void genPotionLoc();
	void genGoldLoc();
	void genMonsterLoc();

	Coordinates spawnLoc;
	Coordinates nextFloorLoc;
	
	void readEntities(std::vector<std::string> plan);
	public:
	
	Floor(std::vector<std::string> plan, TextDisplay *td, bool whatGen);
	
	void react(PlayerRace *player);
	void notifyItem(Coordinates nextPos, PlayerRace *player);
	void print();
	void notify(Subject &whoFrom) override;
	void genFloor();
	void moveEnemies();
	void deleteEnemy(EnemyRace *which);
	void deleteItem(Item *which);
	void NotifyCell(Coordinates coord);
	void NotifyGold(Coordinates coord);
	void NotifyItems();
	bool ValidMove(Coordinates coord);
	Coordinates getRandCoords();
	
	void printChamber(int i);
	void notifyChamber();
	
	
	Coordinates genNextFloorLoc();
	Coordinates genPlayerLoc();

};

#endif
