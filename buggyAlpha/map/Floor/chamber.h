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
	TextDisplay *myTd;
public:
	Chamber(TextDisplay *td, std::vector<Coordinate*> &reqCells, const std::vector<Cell*> &theCells);
	Coordinate *genLoc(char whatChar);
	Item *genPotionLoc();
	Item *genGoldLoc();
	Character *genMonsterLoc();
	Cell *genPlayerLoc();
	Coordinate *genStairLoc();
	Cell *getCellAt(Coordinate &pos);
//	bool InChamber(Coordinate &coord);
//	void deleteItem(Item *which);
	bool ValidMove(Coordinate coord);
	bool moveEnemies();
	void bloom();
	void printChamber();
	void readEntities(std::vector<std::string> plan);

};


//void reqCellsInChamber(Coordinate coord, std::vector<std::string> plan, std::vector<Coordinate*> &chamberCoords);
#endif
