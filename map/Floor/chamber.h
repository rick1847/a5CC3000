#include <vector>
#include "../coordinates.h"

class Item;
class EnemyRace;

class Chamber{
	std::vector<Cell*> cells;
	std::vector<EnemyRace*> enemies;

	void genPotionLoc();
	void genGoldLoc();
	void genNextFloorLoc();
	void genPlayerLoc();
	void genMonsterLoc();
	

	public:
	void genChamber();
	bool InChamber(Coordinates coord);
	void deleteItem(Item *which);
	bool ValidMove(Coordinates coord);
	bool moveEnemies();

};
