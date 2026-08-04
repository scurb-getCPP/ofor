#ifndef OFOR
#define OFOR

#include <fstream>
#include <string>

class ofor{
public:
	void fileDetail(std::ifstream& input);
	void writeInFile(std::ostream& write, const std::string& text);

};
#endif
