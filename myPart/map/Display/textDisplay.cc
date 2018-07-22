#include "textDisplay.h"
#include "../coordinates.h"
#include <iostream>
using namespace std;

TextDisplay::TextDisplay(vector<string> newDisplay):display{newDisplay}{
	
}

void TextDisplay::print(){
	for(auto i : display){
		cout<<i<<endl;
	}
}

void TextDisplay::notify(Subject &fromWho){
	Coordinates where = fromWho.getPos();
	
	
	display.at(where.x)[where.y] = fromWho.getDispChar();
	//cout<<fromWho.getDispChar()<<endl;
	
/*	if(where.x == 3 && where.y == 3){
		cout<<"asdfasdf"<<display.at(where.x)[where.y]<<endl;
	}
	
	print();
	cout<<endl;*/
	
}

void TextDisplay::load(vector<string> newDisplay){
	display = newDisplay;
}
