#include"subject.h"
#include"observer.h"
void Subject::addObserver(Observer *who) {
  observers.emplace_back(who);
}

void Subject::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

Subject::Subject(Coordinate coords):position{coords}{}

Coordinate Subject::getPos(){
	return position;
}

char Subject::getDispChar(){
	return dispChar;
}

void Subject::setPos(Coordinate coords){
	position = coords;
}
