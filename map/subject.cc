#include"subject.h"
#include"observer.h"
void Subject::addObserver(Observer *who) {
  observers.emplace_back(who);
}

void Subject::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

Subject::Subject(Coordinates coords):position{coords}{}

Coordinates Subject::getPos(){
	return position;
}

char Subject::getDispChar(){
	return dispChar;
}
