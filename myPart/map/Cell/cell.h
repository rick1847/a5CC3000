#ifndef CELL_H
#define CELL_H
#include "../subject.h"
#include "../observer.h"
#include "../coordinates.h"

#include <vector>

class Item;
class Character;
class Treasure;

enum class CellType{HorizontalWall, VerticalWall, Tile, Doorway, Passage, Empty};

class Cell : public Subject, public Observer {
	
	//const Coordinates position;
	/*
	Item *itemHere;
	Character *characterHere; 
	CellType type;
	Treasure *gold;
	*/
	bool occupied = false;
	bool occupiedGold = false;
	
	
	//std::vector<Observer *> observers;

	public:
	Cell(Observer *display, char type, Coordinates coord);
	
	bool isOccupiedEnemy();
	bool isOccupiedPlayer();
	
	void deleteChar(Character *character); 
	void deleteItem(Item *item);
	
	void notify(Subject &fromWho);
	void notify(Treasure &fromWho);
	
	void setChar(char a);

	void setOccupy(bool toWhat);
	bool getOccupy();
	
	void setOccupyGold(bool toWhat);
	bool getOccupyGold();
	
	
};
#endif


