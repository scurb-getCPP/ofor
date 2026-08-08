#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "ofor.h"

using namespace std;
int main(int argc, const char* argv[]){

        if(argc < 3){
                cout<<"use : [command] [file name]" <<endl;
                return 1;
        }

        ofor Ofor;

        string commands = "open copy edit";
        istringstream iss(commands);

        string openCommand;
        string copyCommand;
        string editCommand;

        iss>> openCommand>> copyCommand >>editCommand;

        if(argv[1] == openCommand){
                for(auto fi = argv + 2; fi != argv + argc; ++fi){
                ifstream file(*fi);

                if(!file) {
                        cerr<<"file cant open : " <<*fi <<endl;
                }
                else{
                        Ofor.openFile(file);
                        file.close();
                }
                }
        }
        else if(argv[1] == copyCommand){
                string text;
                vector<string> texts;

                ifstream file1(argv[2]);
                ofstream file2(argv[3], ios::app);

                if(!file1){
                        cerr<<"cannot open : " <<argv[2] <<endl;
                }
                if(!file2){
                        cerr<<"cannot open/create : " <<argv[3] <<endl;
                }

                while(getline(file1, text)){
                        texts.push_back(text);
                }

                for(const string& line : texts){
                        Ofor.writeIn(file2, line);
                }
                file1.close();
                file2.close();
                }
        else if(argv[1] == editCommand){
                string text;
                ofstream file(argv[2], ios::app);

                if(!file){
                        cerr<<"file not exist : " <<argv[2] <<endl;
                }
                else{
                        cout<<"enter your text/code : " <<endl;
                        while(getline(cin, text)){
                                if(text == "exit")
                                        break;
                                Ofor.writeIn(file, text);
                        }
                }        file.close();
        }

        return 0;
}
