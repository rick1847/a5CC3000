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
class PlayerRace;
class TextDisplay;

enum class CellType{HorizontalWall, VerticalWall, Tile, Doorway, Passage, Empty};

class Cell{
	
	Coordinate position;
	Item *itemHere = nullptr;
	
	Character *characterHere = nullptr;
	
	Treasure *treasureHere = nullptr;
	
	//to notify td of a change
	TextDisplay *td;
	
	CellType type;
	
	std::vector<Cell *> neighbours;
	char dispChar;
	/*
	bool occupied = false;
	
	bool occupiedGold = false;*/
	
	
	//std::vector<Observer *> observers;

	public:
	
	void setItemHere(Item *);
	void setCharacterHere(Character *);
	Item *getItemHere();
	Character *getCharacterHere();
	
	Cell(TextDisplay *display, char type, Coordinate coord);
	
	char getDispChar();
	bool isOccupiedEnemy();
	bool isOccupiedPlayer();
	
	Coordinate getPos();
	Coordinate *getPosPtr();
	
	void addNeighbour(Cell *neighbour);
	
<<<<<<< HEAD
=======
	void killChar(); 
	void removeItem();
	
	void notify(Subject &fromWho);
	void notify(Treasure &fromWho);
	
>>>>>>> 96165da3ca5b6ae01dea71dc38cbdb1c06efb12f
	void setChar(char a);

	void alertDisplayOfChange();

	
	
	void send();
	void receive(Cell *neighbour);
	//void notifyEnemies();

	void send(std::string dir);
	bool receive(Character *myChar);
	//void attackPlayer(Character *player);

	void bloom();
	
	
};
#endif


