#include "chamber.h"
#include <algorithm>
#include <iostream>
#include "../Display/textDisplay.h"
using namespace std;


bool invalidTile(char test){return (test == ' ' || test == '|' || test == '-' || test == '#'); }



bool oneTileAway(Coordinates obj1, Coordinates obj2){
	int diffX = obj1.x - obj2.x;
	int diffY = obj1.y - obj2.y;
	
	diffX = abs(diffX);
	diffY = abs(diffY);
	
	return diffX <= 1 && diffY <= 1 && !(diffX == 0 && diffY == 0);
}

bool detAddCoord(vector<Coordinates> &chamberCoords, vector<string> &plan, int xOff, int yOff, auto &i){
	if(!invalidTile(plan.at(i.x + xOff)[i.y + yOff])){
		if(chamberCoords.end() == find_if(chamberCoords.begin(), chamberCoords.end(), [&](Coordinates inCoord){return inCoord.x == i.x + xOff && inCoord.y == i.y + yOff; })){
			chamberCoords.emplace_back(Coordinates{i.x + xOff, i.y + yOff});
			return true;
		}
	}
	
	return false;
}
Chamber::Chamber(TextDisplay *td, vector<string> plan, Coordinates coord){
	vector<Coordinates> chamberCoords;
	
	chamberCoords.emplace_back(coord);
	
	bool newTile = true;
	
	while(newTile){
		newTile = false;
		for (auto i : chamberCoords){
			newTile = detAddCoord(chamberCoords, plan, 1, 0, i) || newTile;
			newTile = detAddCoord(chamberCoords, plan, 0, 1, i) || newTile;
			newTile = detAddCoord(chamberCoords, plan, -1, 0, i) || newTile;
			newTile = detAddCoord(chamberCoords, plan, 0, -1, i) || newTile;
		}
	}
	/*
	for(int i = 2; i < 8; ++i){
		for(auto pos : chamberCoords){
			if(pos.x == i)
			cout<<"("<<pos.x<<" "<<pos.y<<")";
		}
		cout<<endl;
	}
	cout<<"I work 2 "<<chamberCoords.size()<<endl<<endl;*/
	
	// creates the cells
	for(auto i : chamberCoords)
		cells.emplace_back(new Cell(td, plan.at(i.x).at(i.y), i));
	
	//adds the observers
	for(auto curCell : cells){
		for(auto observerCell : cells){
			if(oneTileAway(curCell->getPos(), observerCell->getPos())){
				curCell->addObserver(observerCell);
			}
		}
		curCell->addObserver(td);
		
	}
	
	
	
	
}

void Chamber::printChamber(){
	for(int i = 0; i < 30; ++i){
		for(auto cell : cells){
			Coordinates pos = cell->getPos();
			if(pos.x == i)
				cout<<"("<<pos.x<<" "<<pos.y<<")";
		}
		cout<<endl;
	}
}

void Chamber::genPotionLoc(){
	
}

void Chamber::genGoldLoc(){
	
}

void Chamber::genNextFloorLoc(){
	
}

void Chamber::genPlayerLoc(){
	
}

void Chamber::genMonsterLoc(){
	
}

void Chamber::genChamber(){
	
}

bool Chamber::InChamber(Coordinates coord){
	
}

void Chamber::deleteItem(Item *which){
	
}

bool Chamber::ValidMove(Coordinates coord){
	bool test = cells.end() == find_if(cells.begin(), cells.end(), 
		[&coord](Cell *inCell)
			{return inCell->getPos().x == coord.x && inCell->getPos().y == coord.y; });
	/*Cell *foundCell = *find_if(cells.begin(), cells.end(), 
		[&coord](Cell *inCell)
			{return inCell->getPos().x == coord.x && inCell->getPos().y == coord.y; });
	Coordinates foundCoord;
	if(foundCell){
		foundCoord = foundCell->getPos();
	}
	cout<<foundCoord.x<<" "<<foundCoord.y<<" "<<test<<endl;
	*/
	//throw "asdfasdf";
	return test;
	
}

bool Chamber::moveEnemies(){
	return true;
}

void Chamber::bloom(){
	cells.at(0)->notifyObservers();
}
