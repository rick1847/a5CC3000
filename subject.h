#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "coordinate.h"
class Observer;

class Subject {
	
	public:
	std::vector<Observer*> observers;
	Coordinate position;
	char dispChar;

	void addObserver(Observer *who);  
	void notifyObservers();
	Coordinate getPos();
	explicit Subject(Coordinate coords);
	
	void setPos(Coordinate coords);
	char getDispChar();
};

#endif
