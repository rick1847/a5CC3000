#include <vector>

#include "../subject.h"
#include "../observer.h"

class TextDisplay: public Observer{

	std::vector<std::vector<char>> display;

	public:
	void print();
	void notifiy(Subject &fromWho);
}; 
