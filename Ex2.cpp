#include <iostream>
using namespace std;

int main(){

    int anInt{1};
    anInt++;
    cout << anInt << endl;

    double aDouble{4.669};
    cout << aDouble << endl;

    int intFromDouble{(int)aDouble};
    cout << intFromDouble << endl;

    return 0;

}