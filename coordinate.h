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
	bool operator==(Coordinate other);
	bool isEast(Coordinate &pos1, Coordinate &pos2);
	bool isNorth(Coordinate &pos1, Coordinate &pos2);
	bool equalNorth(Coordinate &pos1, Coordinate &pos2);
	bool equalEast(Coordinate &pos1, Coordinate &pos2);
	bool inDir(std::string dir, Coordinate &pos1, Coordinate &pos2);
};


#endif
