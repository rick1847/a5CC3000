#include<fstream>
#include<iostream>
#include<string>

#include"map/dungeon.h"
int main(int argc, char **argv){
/*
	std::ifstream test(argv[1]);
	std::string test2("");
	while(std::getline(test, test2)){
		std::cout<<test2<<std::endl;
	}*/
	
	std::ifstream mapFile("testFloor.txt");
	
	Dungeon test(mapFile);
	test.play();

}


