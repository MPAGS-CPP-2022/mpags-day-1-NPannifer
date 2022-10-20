#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){
    const vector<string> cmdLineArgs { argv, argv+argc };

    //start loop at 2nd index  (1st is file name)
    for(int i = 1; i< (int)cmdLineArgs.size(); i++){      
        cout << cmdLineArgs[i] << endl;
    }
    
    return 0;
}