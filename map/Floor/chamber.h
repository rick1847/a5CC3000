#ifndef ___CHAMBER___H___
#define ___CHAMBER___H___

#include <vector>
#include <string>
#include "../coordinates.h"
#include "../Cell/cell.h"

class Item;
class EnemyRace;
class TextDisplay;

class Chamber{
	std::vector<Cell*> cells;
	std::vector<EnemyRace*> enemies;
	

	void genPotionLoc();
	void genGoldLoc();
	void genNextFloorLoc();
	void genPlayerLoc();
	void genMonsterLoc();
	

	public:
	
	Chamber(TextDisplay *td, std::vector<std::string> plan, Coordinates coord);
	
	void genChamber();
	bool InChamber(Coordinates coord);
	void deleteItem(Item *which);
	
	bool ValidMove(Coordinates coord);
	
	bool moveEnemies();
	
	
	void bloom();
	void printChamber();

};

#endif
