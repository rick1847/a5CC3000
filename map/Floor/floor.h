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


class Floor: public Observer{
	const int maxEnemies = 20;
	const int maxPotions = 10;
	std::vector<Cell*> passages;
	std::vector<Item*> items;
	std::vector<EnemyRace*> enemies;
	std::vector<Chamber*> chambers;

	TextDisplay *td;
	
	void genPotionLoc();
	void genGoldLoc();
	void genNextFloorLoc();
	void genPlayerLoc();
	void genMonsterLoc(); 

	public:
	
	Floor(std::vector<std::string> plan);
	
	void print();
	void notify(Subject &whoFrom) override;
	void genFloor();
	void moveEnemies();
	void deleteEnemy(EnemyRace *which);
	void deleteItem(Item *which);
	void NotifyCell(Coordinates coord);
	void NotifyGold(Coordinates coord);
	bool ValidMove(Coordinates coord);
	Coordinates getRandCoords();
	
	void printChamber(int i);
	void notifyChamber();

};

#endif
