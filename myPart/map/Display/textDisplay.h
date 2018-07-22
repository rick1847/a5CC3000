#ifndef ___TEXTDISPLAY___H___
#define ___TEXTDISPLAY___H___

#include <vector>
#include <string> 
#include "../subject.h"
#include "../observer.h"

class TextDisplay: public Observer{

	std::vector<std::string> display;

	public:
	TextDisplay(std::vector<std::string> newDisplay);
	void print();
	void notify(Subject &fromWho) override;
	void load(std::vector<std::string> newDisplay);
}; 

#endif
