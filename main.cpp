#include <iostream>
#include <fstream>
#include <string>
#include "ofor.h"

using namespace std;
int main(int argc, const char* argv[]){
    ofor Ofor;
    if (argc < 3) {
        cerr<<"use : [Command] [File Name]" <<endl;
        return 1;
    }

    string command = argv[1];

    for (auto fi = argv + 2; fi != argv + argc; ++fi){
            if (command == "open"){
                ifstream file(*fi);

                if (!file){
                        cerr<<"file cant open : " <<*fi <<endl;
                }
                else {
                        Ofor.readFile(file);
                        file.close();
                }
            }

            else if (command == "add") {
                ofstream out(*fi, ios::app | ios::out);


                if (!out){
                        cerr<<"file not created : " <<*fi <<endl;
                }
                else{
                        cout<<"file name : " <<*fi <<endl;
                        cout<<"enter your code or text : " <<endl;
                        string choice;
                        while(true){
                                getline(cin, choice);

                                if (choice == "exit")
                                        break;

                                Ofor.writeIn(out, choice);
                        }
                        out.close();
                }
                else if (command == "copy"){
                    string lines;
                    vector<string> text;
                    ifstream in;
                    ofstream out;

                    in.open(argv[2]);
                    out.open(argv[3]);

                    while(getline(in, lines)){
                        text.push_back(lines);
                    }
                    for (const string& line : text){
                        writeIn(out, line);
                    }

                    }
                    cout<<"file copied succesfully" <<endl;

            }
    }
        return 0;
}
