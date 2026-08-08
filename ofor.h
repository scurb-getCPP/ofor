#ifndef OFOR
#define OFOR

#include <fstream>
#include <string>

class ofor{
public:
	void openFile(std::ifstream& input);
	void writeIn(std::ostream& write, const std::string& text);

};
#endif
