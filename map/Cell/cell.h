#ifndef CELL_H
#define CELL_H
#include "../subject.h"
#include "../observer.h"
#include "../coordinates.h"

class Item;
class Character;
class Treasure;

enum class CellType{HorizontalWall, VerticalWall, Tile, Doorway, Passage, Empty};

class Cell : public Subject, public Observer {
	
	const Coordinates position;
	Item *itemHere;
	Character *characterHere; 
	CellType type;
	char dispChar;
	Treasure *gold;

	public:
	bool isOccupiedEnemy();
	bool isOccupiedPlayer();
	Coordinates getPos();
	void deleteChar(Character *character); 
	void deleteItem(Item *item);
	void notify(Subject &fromWho);
	char getDispChar();

};
#endif


