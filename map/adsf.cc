#include <iostream>
#include "dungeon.h"

using namespace std;

bool topWallBottomWall(const string & a){
	int i = 1;
	int end = a.size();
	
	if(a[0] != '|') return false;
	if(a[end - 1] != '|') return false;
	
	while(i < end - 1){
		if(a[i] != '-'){
			return false;
		}
		++i;
	}
	
	return true;
}
Dungeon::Dungeon(ifstream &mapFile){
	string floorLine;
	int i = 0;
	
	
	
	//load a map File in
	while(getline(mapFile, floorLine)){
		//cout<<floorLine<<endl;
		
		//cout<<topWallBottomWall(floorLine)<<endl;
		
		if(topWallBottomWall(floorLine)){
			FloorMaps.emplace_back(vector<string>());
			FloorMaps.at(i).emplace_back(floorLine);
			//cout<<FloorMaps.at(i).at(0)<<endl;
			//cout<<floorLine<<endl;
			//
			getline(mapFile, floorLine);
			
			int j = 1;
			while(!topWallBottomWall(floorLine)){
				FloorMaps.at(i).emplace_back(floorLine);
				//cout<<FloorMaps.at(i).at(j)<<endl;
				//cout<<floorLine<<endl;
				getline(mapFile, floorLine);
				
				++j;
				
				//cout<<"I work 1"<<endl;
			}
		
			FloorMaps.at(i).emplace_back(floorLine);
			//cout<<FloorMaps.at(i).at(j)<<endl;
			++i;
		}
	}
//	td = new TextDisplay;
}

void Dungeon::play(){
	int i = 0;
	
	while(i < 5){
		for(auto t : FloorMaps.at(i)) cout<<t<<endl;
		
		++i;
	}
	//cout<<"I work";
}
