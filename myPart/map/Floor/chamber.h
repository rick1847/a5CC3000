#ifndef ___CHAMBER___H___
#define ___CHAMBER___H___

#include <vector>
#include <string>
#include "../coordinates.h"
#include "../Cell/cell.h"

class Item;
class EnemyRace;
class PlayerRace;
class Item;
class TextDisplay;

class Chamber{
	bool randGen;
	
	std::vector<Cell*> cells;
	std::vector<Item*> items;
	std::vector<EnemyRace*> enemies;
	
	TextDisplay *myTd;

	
	
	Coordinates genLoc(char whatChar);
	public:
	
	void genPotionLoc();
	void genGoldLoc();
	void genMonsterLoc();
	
	Chamber(TextDisplay *td, std::vector<std::string> plan, Coordinates coord, bool whatGen);
	
	void genChamber();
	Coordinates genPlayerLoc();
	Coordinates genNextFloorLoc();
	
	bool InChamber(Coordinates coord);
	void deleteItem(Item *which);
	
	bool ValidMove(Coordinates coord);
	
	void react(PlayerRace *player);
	void notifyItem(Coordinates nextPos, PlayerRace *player);
	bool moveEnemies();
	
	void setOccupy(Coordinates pos, bool toWhat);
	
	void bloom();
	void printChamber();
	void notifyItems();
	void readEntities(std::vector<std::string> plan);

};

#endif
