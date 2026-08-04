#include "ofor.h"
#include <iostream>

using namespace std;

void ofor::fileDetail(ifstream& input){
	string line;
	while (getline(input, line)){
		cout<<line <<endl;
	}
}
void ofor::writeInFile(ostream& write, const string& text){
	write<<text <<endl;
}
