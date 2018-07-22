#ifndef COORDINATES_H
#define COORDINATES_H

#include<iostream>
#include<cstddef>

struct Coordinates{
	size_t x, y;

	bool operator==(const Coordinates &other){
		return x == other.x && y == other.y;
	}
};


#endif
