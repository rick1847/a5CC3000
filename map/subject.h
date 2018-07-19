#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

class Observer;

class Subject {
  std::vector<Observer*> observers;
 public:
  void addObserver(Observer *who);  
  void notifyObservers();
};

#endif
