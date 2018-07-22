#include "character.h"

PlayerRace::PlayerRace(Observer *td, Coordinates coords):Subject(coords){
	dispChar = '@';
	addObserver(td);
}

void PlayerRace::move(Coordinates newCoords){
	setPos(newCoords);
	notifyObservers();
	
//	dispChar = 'p';
}


EnemyRace::EnemyRace(Observer *td, Coordinates coords):Subject(coords){
	dispChar = 'e';
	addObserver(td);
}

void move(){
	
}
