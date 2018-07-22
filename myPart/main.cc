#include<fstream>
#include<iostream>
#include<string>

#include"map/dungeon.h"
int main(int argc, char **argv){

	bool randGen = true;
	std::string fileName = "emptyfloor.txt";
	if(argc > 1){
		randGen = false;
		fileName = argv[1];
	}
	
	std::ifstream mapFile(fileName);
	
	
	
	Dungeon test(mapFile, randGen);
	test.play();

}
