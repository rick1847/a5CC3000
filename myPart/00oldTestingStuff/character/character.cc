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

Coordinates moveWhere(Coordinates curCoord, int instr){
	
	if(instr == 0){
		curCoord.x += 1;
		curCoord.y += 1;
	}
	else if(instr == 1){
		curCoord.x += 1;
		curCoord.y += 0;
	}
	else if(instr == 2){
		curCoord.x += 1;
		curCoord.y += -1;
		
	}
	else if(instr == 3){
		curCoord.x += 0;
		curCoord.y += 1;
		
	}
	else if(instr == 4){
		curCoord.x += 0;
		curCoord.y += -1;
		
	}
	else if(instr == 5){
		curCoord.x += -1;
		curCoord.y += 1;
	}
	else if(instr == 6){
		curCoord.x += -1;
		curCoord.y += 0;
	}
	else if(instr == 7){
		curCoord.x += -1;
		curCoord.y += -1;
	}
	
	return curCoord;
}

bool oneTileAway2(Coordinates obj1, Coordinates obj2){
	int diffX = obj1.x - obj2.x;
	int diffY = obj1.y - obj2.y;
	
	diffX = abs(diffX);
	diffY = abs(diffY);
	
	return diffX <= 1 && diffY <= 1 && !(diffX == 0 && diffY == 0);
}

#include <iostream>
void EnemyRace::react(PlayerRace *player){
	if(oneTileAway2(getPos(), player->getPos())){
		std::cout<<"I reacted"<<getPos().x<<" "<<getPos().y<<std::endl;
	}
}
Coordinates EnemyRace::move(){
	int instr = rand() % 8;
	
	Coordinates nextPos = moveWhere(position, instr);
	
	return nextPos;
}
