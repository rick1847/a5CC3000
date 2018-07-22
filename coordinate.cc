#include "coordinate.h"


Coordinate::Coordinate(int x, int y) : X(x), Y(y)
{}

int Coordinate::getX() {
	return X;
}

int Coordinate::getY() {
	return Y;
}