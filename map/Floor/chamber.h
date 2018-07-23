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

	
	
	Coordinate genLoc(char whatChar);
	public:
	
	Item *genPotionLoc();
	Item *genGoldLoc();
	Character *genMonsterLoc();
	Cell *getCellAt(Coordinate pos);
	Chamber(TextDisplay *td, std::vector<Coordinate*> &reqCells, const std::vector<Cell*> &theCells);
	
	Cell *genPlayerLoc();
	Coordinate genNextFloorLoc();
	
	bool ValidMove(Coordinate coord);
	
	void react(PlayerRace *player);
	
	
	void bloom();
	void printChamber();
	void readEntities(std::vector<std::string> plan);

};


//void reqCellsInChamber(Coordinate coord, std::vector<std::string> plan, std::vector<Coordinate*> &chamberCoords);
#endif
