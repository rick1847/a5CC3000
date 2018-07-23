#ifndef CELL_H
#define CELL_H

#include "../../subject.h"
#include "../../observer.h"
#include "../../coordinate.h"

#include <vector>
#include <string>

class Item;
class Character;
class Treasure;
class TextDisplay;
enum class CellType{HorizontalWall, VerticalWall, Tile, Doorway, Passage, Empty};
class Cell{
	Coordinate *position;
	char dispChar;
	CellType type;
	Item *itemHere = nullptr;
	Character *characterHere = nullptr;
	//to notify td of a change
	TextDisplay *td;
	std::vector<Cell *> neighbours;
	//bool occupied = false;
	//bool occupiedGold = false;
	//std::vector<Observer *> observers;
public:
	Cell(TextDisplay *display, char type, Coordinate &coord);
	Coordinate &getPos();
	char getDisplayChar();
	void setDisplayChar(char a);
	Item *getItem();
	Character *getCharacter();
	void setItem(Item *);
	void setCharacter(Character *);
	void killCharacter();
	void removeItem();
	bool isOccupied();
	void addNeighbour(Cell *neighbour);
	std::vector<Cell *> &getNeighbours();
	void notify(Subject &fromWho);
	void alertDisplayOfChange();
	void send();
	void send(std::string dir);
	void receive(Cell *neighbour);
	bool receive(Character *myChar);
	void bloom();
};
#endif


