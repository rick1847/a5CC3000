#ifndef ___TEXTDISPLAY___H___
#define ___TEXTDISPLAY___H___

#include <vector>
#include <string> 
#include "../map/Cell/cell.h"
class TextDisplay{

	std::vector<std::string> display;

	public:
	TextDisplay(std::vector<std::string> newDisplay);
	void print();
	void notify(Cell &fromWho);
	void load(std::vector<std::string> newDisplay);
}; 

#endif
