#include "Ex8_header.h"

/*
I have attempted to write clean(ish) code, but not really succeeded.

To do:
- Handle Case where no file name specified (e.g. when running ./Ex8 -o)
*/

int main(int argc, char* argv[])
{
    const vector<string> cmdLineArgs {argv, argv+argc};

    vector<int> whereH          = getIndexList(cmdLineArgs, "-h");
    vector<int> whereHelp       = getIndexList(cmdLineArgs, "--help");
    vector<int> whereVersion    = getIndexList(cmdLineArgs, "--version");
    vector<int> whereInputFile  = getIndexList(cmdLineArgs, "-i");
    vector<int> whereOutputFile = getIndexList(cmdLineArgs, "-o");

    if (whereH.size() + whereHelp.size())
    {
        cout << "**INSERT HELPFUL TEXT HERE**" << "\n" << endl;
    }

    if (whereVersion.size())
    {
        cout << "**INSERT VERSION NUMBER HERE**" << "\n" << endl;
    }
    
    string inputFileName{""};
    string outputFileName{""}; 

    int inputFileNameCheck{0};
    int outputFileNameCheck{0};

    bool inputExists{doesIndexExist(whereInputFile)};
    bool outputExists{doesIndexExist(whereOutputFile)};
    bool singleInput{isIndexSingle(whereInputFile)};
    bool singleOutput{isIndexSingle(whereOutputFile)};

    
    if (inputExists && singleInput)
    {   
        int inputArgIndex{convertListToInt(whereInputFile)};
        inputFileName = getFileName(cmdLineArgs,inputArgIndex);
        inputFileNameCheck = checkFileName(inputFileName);
    }
 
    if (outputExists && singleOutput)
    {   
        int outputArgIndex{convertListToInt(whereOutputFile)};
        outputFileName = getFileName(cmdLineArgs,outputArgIndex);
        outputFileNameCheck = checkFileName(outputFileName);
    }

    printWarnings(!singleInput,!singleOutput,inputFileNameCheck,outputFileNameCheck);

    if(!singleInput||!singleOutput||inputFileNameCheck||outputFileNameCheck)
    {
        return -1;
    }

    if (inputExists)
    {
        cout << "Input file: " << inputFileName << endl;
    }

    if (outputExists)
    {
        cout << "Output file: " << outputFileName << endl;
    }

    cout << "\n" << "Listing command line args:" << endl;
    for(int i = 1; i< (int)cmdLineArgs.size(); i++)
    {      
        cout << cmdLineArgs.at(i) << endl;
    }
    
    return 0;
}



vector<int> getIndexList(vector<string> args, string value)
{
    vector<int> index;
    for (int i = 0; i < (int)args.size(); i++)
    {
        if (args.at(i) == value)
        {
            index.push_back(i);
        }
    }
    return index;
}

bool doesIndexExist(vector<int> argsIndex)
{
    int numberOfFiles{(int)argsIndex.size()};
    if(numberOfFiles)
    {
        return true;
    }
    return false;

}

bool isIndexSingle(vector<int> argsIndex)
{
    int numberOfEntries{(int)argsIndex.size()};
    if (numberOfEntries>1)
    {
        return false;
    }
    return true;
}

int convertListToInt(vector<int> indexList)
{
    return indexList.at(0);
}

string getFileName(vector<string> args, int flagIndex)
{
    string fileName{args.at(flagIndex+1)};
    return fileName;
}

int checkFileName(string fileName){
    if(fileName[0] == '-')
    {
        return -1;
    }
    return 0;
}

void printWarnings(int check1, int check2, int check3, int check4)
{
    if(check1)
    {
        cout << "Error: cannot have multiple input files." << endl;
    }
    if(check2)
    {
        cout << "Error: cannot have multiple output files." << endl;
    }
    if(check3)
    {
        cout << "Error: input file name cannot be option/flag" << endl;
    }
    if(check4)
    {
        cout << "Error: output file name cannot be option/flag" << endl;
    }
    return;
}
