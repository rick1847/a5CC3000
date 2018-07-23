#include "item.h"

Item::Item(Observer *td, Coordinates coords):Subject(coords){
	dispChar = 'i';
	addObserver(td);
}
