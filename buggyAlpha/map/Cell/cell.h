#ifndef CELL_H
#define CELL_H

#include "../../coordinate.h"

#include <vector>
#include <string>

class Item;
class Character;
class Treasure;
class PlayerRace;
class TextDisplay;

enum class CellType{HorizontalWall, VerticalWall, Tile, Doorway, Passage, Empty};

class Cell{
	Coordinate *position;
	char dispChar;
	CellType type;
	Item *itemHere = nullptr;
	Character *characterHere = nullptr;
	Treasure *treasureHere;
	//to notify td of a change
	TextDisplay *td;
	std::vector<Cell *> neighbours;
public:
	Cell(TextDisplay *display, char type, Coordinate *coord);
	Coordinate *getPos();
//	Coordinate getPosPtr();
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
	void alertDisplayOfChange();
	void send();
	void send(std::string dir);
	void receive(Cell *neighbour);
	bool receive(Character *myChar);
	void sendPlayer(std::string dir);
	bool receivePlayer(Character *myChar);
	Item *getItemInDir(std::string dir);
	Character *getCharacterInDir(std::string dir);
	void bloom();
	void autoLootGold();
	
};
#endif


