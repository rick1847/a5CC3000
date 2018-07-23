#include "textDisplay.h"
#include "../coordinate.h"
#include <iostream>
using namespace std;

TextDisplay::TextDisplay(vector<string> newDisplay):display{newDisplay}{
	
}

void TextDisplay::print(){
	for(auto i : display){
		cout<<i<<endl;
	}
}

void TextDisplay::notify(Cell &fromWho){
	Coordinate where = fromWho.getPos();
	
	
	display.at(where.X)[where.Y] = fromWho.getDispChar();
	//cout<<fromWho.getDispChar()<<endl;
	
/*	if(where.X == 3 && where.Y == 3){
		cout<<"asdfasdf"<<display.at(where.X)[where.Y]<<endl;
	}
	
	print();
	cout<<endl;*/
	
}

void TextDisplay::load(vector<string> newDisplay){
	display = newDisplay;
}
