
#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> getIndexList(vector<string> args, string value);

bool doesIndexExist(vector<int> argsIndex);

bool isIndexSingle(vector<int> argsIndex);

int convertListToInt(vector<int> indexList);

string getFileName(vector<string> args, int flagIndex);

int checkFileName(string fileName);

void printWarnings(int check1, int check2, int check3, int check4);