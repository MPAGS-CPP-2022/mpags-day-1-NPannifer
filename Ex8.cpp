#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> getIndex(vector<string> args, string value)
{
    vector<int> index;
    for (int i = 0; i < (int)args.size(); i++)
    {
        if (args[i] == value)
        {
            index.push_back(i);
        }
    }
    return index;
}


int main(int argc, char* argv[]){
    const vector<string> cmdLineArgs { argv, argv+argc };

    string inputFileName{""};
    string outputFileName{""};
   
    vector<int> whereH          = getIndex(cmdLineArgs, "-h");
    vector<int> whereHelp       = getIndex(cmdLineArgs, "--help");
    vector<int> whereVersion    = getIndex(cmdLineArgs, "--version");
    vector<int> whereInputFile  = getIndex(cmdLineArgs, "-i");
    vector<int> whereOutputFile = getIndex(cmdLineArgs, "-o");


    if (whereH.size() + whereHelp.size()){
        cout << "**INSERT HELPFUL TEXT HERE**" << endl;
    }

    if (whereVersion.size()){
        cout << "**INSERT VERSION NUMBER HERE**" << endl;
    }
    
    if (whereInputFile.size()){
        if (whereInputFile.size()>1){
            cout << "Error: cannot have multiple input files." << endl;
            return -1;
        }
        else{

            int inputFileIndex = (int)whereInputFile[0];
            inputFileName = cmdLineArgs[inputFileIndex+1];
            if(inputFileName[0] == '-'){
                cout << "Error: input file name cannot be option/flag" << endl;
                return -1;
            }
        }
    }

    if (whereOutputFile.size()){
        if (whereOutputFile.size()>1){
            cout << "Error: cannot have multiple output files." << endl;
            return -1;
        }
        else{

            int outputFileIndex = (int)whereOutputFile[0];
            outputFileName = cmdLineArgs[outputFileIndex+1];
            if(outputFileName[0] == '-'){
                cout << "Error: output file name cannot be option/flag" << endl;
                return -1;
            }
        }
    }

    cout << "Input file: " << inputFileName << endl;
    cout << "Output file: " << outputFileName << endl;

    cout << "\n" << "Listing command line args:" << endl;
    for(int i = 1; i< (int)cmdLineArgs.size(); i++){      
        cout << cmdLineArgs[i] << endl;
    }
    
    return 0;
}