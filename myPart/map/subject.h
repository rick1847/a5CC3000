#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "coordinates.h"
class Observer;

class Subject {
	
	public:
	std::vector<Observer*> observers;
	Coordinates position;
	char dispChar;

	void addObserver(Observer *who);  
	void notifyObservers();
	Coordinates getPos();
	explicit Subject(Coordinates coords);
	
	void setPos(Coordinates coords);
	char getDispChar();
};

#endif
