#include "../map/subject.h"
#include "../map/observer.h"

class Item : public Subject{
	public:
	Item(Observer *td, Coordinates coords);
};
