#include "../subject.h"
#include "../observer.h"
#include "../Cell/cell.h"
#include "chamber.h"
#include "../coordinates.h"
#include<vector>

class Item;
class EnemyRace;


class Floor: public Observer{
	const int maxEnemies;
	const int maxPotions;
	std::vector<Cell*> passages;
	std::vector<Item*> items;
	std::vector<EnemyRace*> enemies;
	std::vector<Chamber*> chambers;

	void genPotionLoc();
	void genGoldLoc();
	void genNextFloorLoc();
	void genPlayerLoc();
	void genMonsterLoc(); 

	public:
	void genFloor();
	void moveEnemies();
	void deleteEnemy(EnemyRace *which);
	void deleteItem(Item *which);
	void NotifyCell(Coordinates coord);
	void NotifyGold(Coordinates coord);
	bool ValidMove(Coordinates coord);
	Coordinates getRandCoords();

};
