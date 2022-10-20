#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool find(string value, vector<string> args) {
    for (string str : args){
        if (str == value) {
           return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]){

    const vector<string> cmdLineArgs { argv, argv+argc };
    
    bool isHelp{find("-h", cmdLineArgs)||find("--help", cmdLineArgs)};
    if(isHelp){
        cout << "**INSERT HELPFUL TEXT HERE**" << endl;
    }
    
    for(int i = 1; i< (int)cmdLineArgs.size(); i++){      
    cout << cmdLineArgs[i] << endl;
    }
    

    return 0;
}