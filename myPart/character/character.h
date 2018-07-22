#include "../map/coordinates.h"
#include "../map/subject.h"
#include "../map/observer.h"

class Character: public Subject{
//	Coordinates position;
	
//	public:
};

class PlayerRace: public Subject{
	
	
	public:
	PlayerRace(Observer *td, Coordinates coords);
	void move(Coordinates newCoords);
};

class EnemyRace: public Subject{
	
	
	public:
	void react(PlayerRace *player);
	EnemyRace(Observer *td, Coordinates coords);
	Coordinates move();
};
