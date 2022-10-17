#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getIndex(vector<string> args, string value){
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

int main(int argc, char* argv[])
{
    const vector<string> cmdLineArgs { argv, argv+argc };

    string inputFileName{""};
    string outputFileName{""};
    int inputFileIndex{0};
    int outputFileIndex{0};
   
    vector<int> whereH          = getIndex(cmdLineArgs, "-h");
    vector<int> whereHelp       = getIndex(cmdLineArgs, "--help");
    vector<int> whereVersion    = getIndex(cmdLineArgs, "--version");
    vector<int> whereInputFile  = getIndex(cmdLineArgs, "-i");
    vector<int> whereOutputFile = getIndex(cmdLineArgs, "-o");

    int numberOfInputFiles{(int)whereInputFile.size()};
    int numberOfOutputFiles{(int)whereOutputFile.size()};


    if (whereH.size() + whereHelp.size())
    {
        cout << "**INSERT HELPFUL TEXT HERE**" << "\n" << endl;
    }

    if (whereVersion.size())
    {
        cout << "**INSERT VERSION NUMBER HERE**" << "\n" << endl;
    }
    

    if (numberOfInputFiles)
    {
        if (numberOfInputFiles>1)
        {
            cout << "Error: cannot have multiple input files." << endl;
            return -1;
        }
        else{
            inputFileIndex = (int)whereInputFile[0];
            inputFileName = cmdLineArgs[inputFileIndex+1];

            if(inputFileName[0] == '-'){
                cout << "Error: input file name cannot be option/flag" << endl;
                return -1;
            }

            cout << "Input file: " << inputFileName << endl;
        }
    }

    if (numberOfOutputFiles)
    {
        if (numberOfOutputFiles>1)
        {
            cout << "Error: cannot have multiple output files." << endl;
            return -1;
        }
        else{
            outputFileIndex = (int)whereOutputFile[0];
            outputFileName = cmdLineArgs[outputFileIndex+1];

            if(outputFileName[0] == '-'){
                cout << "Error: output file name cannot be option/flag" << endl;
                return -1;
            }

            cout << "Output file: " << outputFileName << endl;
        }
    }


    cout << "\n" << "Listing command line args:" << endl;
    for(int i = 1; i< (int)cmdLineArgs.size(); i++)
    {      
        cout << cmdLineArgs[i] << endl;
    }
    
    return 0;
}
