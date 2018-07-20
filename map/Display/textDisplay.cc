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
	
}
