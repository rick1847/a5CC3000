#include"subject.h"
void Subject::addObserver(Observer *who) {
  observers.emplace_back(who);
}

void Subject::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

