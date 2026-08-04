#include <iostream>
#include <fstream>
#include <string>
#include "ofor.h"

using namespace std;

int main(int argc, const char* argv[]){
	ofor inputFile;

	if (argc < 3){
		cerr<<"use : <command> <file name>" <<endl;
		return 1;
	}
	string command = argv[1];

	if (command == "fopen"){
		for (auto fd = argv + 2; fd != argv + argc; ++fd){
			ifstream file(*fd);

			if (file.is_open()){
				inputFile.fileDetail(file);
			}
			else {
				cerr<<"CANT OPEN : " <<string(*fd) <<endl;
			}	
		}
	}
	else if (command == "fadd"){
		for (auto fa = argv + 2; fa != argv + argc; ++fa){
			ofstream file(*fa, ios::app);

			string choice;
			string textOrCode;

			if (!file.is_open()){
				cerr<<"file not created : " <<*fa <<endl;
				continue;
			}

				cout<<"file ready" <<endl;
				cout<<"wanna add something in (y/n)\n(exit) : " <<flush;

				cin>>choice;
				cin.ignore();
			if (choice == "y" || choice == "yes"){
				cout<<"enter your text or code : " <<endl;

				while (true){
					getline(cin, textOrCode);

					if (textOrCode == "exit")
						break;

					inputFile.writeInFile(file, textOrCode);
				}
			}
			else if (choice == "n" || choice == "no" || choice == "exit"){
				cout<<"done" <<endl;
			}
			else{
				cout<<"enter true command!" <<endl;
			}
		}
	}

	return 0;
}
