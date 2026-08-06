#include "ofor.h"
#include <iostream>
#include <vector>

using namespace std;

void ofor::readFile(ifstream& input){
	string line;
	vector<string> lines;
	while (getline(input, line)){
		lines.push_back(line);
	}
	for (size_t l = 0; l < lines.size(); ++l){
		cout<<l + 1 <<" : " <<lines[l] <<endl;
	}
}
void ofor::writeIn(ostream& write, const string& text){
	write<<text <<endl;
}
