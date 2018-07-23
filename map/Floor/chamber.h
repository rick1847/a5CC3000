#ifndef ___CHAMBER___H___
#define ___CHAMBER___H___

#include <vector>
#include <string>

#include "../../coordinate.h"
#include "../Cell/cell.h"
#include "../../display/textDisplay.h"
#include "../../character/character.h"
#include "../../item/item.h"

#include "../../character/enemyRace/enemyrace.h"

/*
class Item;
class EnemyRace;
class PlayerRace;
class Item;
class TextDisplay;
*/

class Chamber{
	bool randGen;
	
	std::vector<Cell*> cells;
	std::vector<Item*> items;
	std::vector<EnemyRace*> enemies;
	
	TextDisplay *myTd;

	
	
	Coordinate genLoc(char whatChar);
	public:
	
	Item *genPotionLoc();
	Item *genGoldLoc();
	Character *genMonsterLoc();
	Cell *getCellAt(Coordinate pos);
	Chamber(TextDisplay *td, std::vector<Coordinate*> &reqCells, const std::vector<Cell*> &theCells);
	
	void genChamber();
	Cell *genPlayerLoc();
	Coordinate genNextFloorLoc();
	
	bool InChamber(Coordinate coord);
	void deleteItem(Item *which);
	
	bool ValidMove(Coordinate coord);
	
	void react(PlayerRace *player);
	void notifyItem(Coordinate nextPos, PlayerRace *player);
	bool moveEnemies();
	
	void setOccupy(Coordinate pos, bool toWhat);
	
	void bloom();
	void printChamber();
	void notifyItems();
	void readEntities(std::vector<std::string> plan);

};


//void reqCellsInChamber(Coordinate coord, std::vector<std::string> plan, std::vector<Coordinate*> &chamberCoords);
#endif
