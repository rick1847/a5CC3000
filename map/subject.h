#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "coordinates.h"
class Observer;

class Subject {
	std::vector<Observer*> observers;
	
	protected:
	const Coordinates position;
	char dispChar;
	
	public:
	void addObserver(Observer *who);  
	void notifyObservers();
	Coordinates getPos();
	explicit Subject(Coordinates coords);
	
	char getDispChar();
};

#endif
