#ifndef COORDINATE_H
#define COORDINATE_H
//tracks the position of a cell/character/item
//top left cell of the game area is (0,0), right and down are positive directions

class Coordinate {
	int X;
	int Y;
public:
	Coordinate(int x = 0, int y = 0);
	int getX();
	int getY();
};


#endif
