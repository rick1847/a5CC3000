#include "coordinate.h"


Coordinate::Coordinate(int x, int y) : X(x), Y(y)
{}

int Coordinate::getX() {
	return X;
}

int Coordinate::getY() {
	return Y;
}

bool Coordinate::operator==(Coordinate other){
	return X == other.getX() && Y == other.getY();
}

bool Coordinate::isEast(Coordinate &pos1, Coordinate &pos2) {
	return pos2.Y > pos1.Y;
}

bool Coordinate::isNorth(Coordinate &pos1, Coordinate &pos2) {
	return pos2.X < pos1.X;
}

bool Coordinate::equalNorth(Coordinate &pos1, Coordinate &pos2) {
	return pos2.X == pos1.X;
}

bool Coordinate::equalEast(Coordinate &pos1, Coordinate &pos2) {
	return pos2.Y == pos1.Y;
}

bool Coordinate::inDir(std::string dir, Coordinate &pos1, Coordinate &pos2) {
	if (dir == "no") {
		return isNorth(pos1, pos2) && equalEast(pos1, pos2);
	}
	else if (dir == "so") {
		return (!isNorth(pos1, pos2)) && equalEast(pos1, pos2);
	}
	else if (dir == "ea") {
		return isEast(pos1, pos2) && equalNorth(pos1, pos2);
	}
	else if (dir == "we") {
		return (!isEast(pos1, pos2)) && equalNorth(pos1, pos2);
	}
	else if (dir == "ne") {
		return isNorth(pos1, pos2) && isEast(pos1, pos2);
	}
	else if (dir == "nw") {
		return isNorth(pos1, pos2) && (!isEast(pos1, pos2));
	}
	else if (dir == "se") {
		return (!isNorth(pos1, pos2)) && isEast(pos1, pos2);
	}
	else if (dir == "sw") {
		return (!isNorth(pos1, pos2)) && (!isEast(pos1, pos2));
	}
	else {
		return false;
	}
}