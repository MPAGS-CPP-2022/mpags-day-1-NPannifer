#include <iostream>
#include <string>
using namespace std;

int main(){
    int anInt{42};
    int anotherInt{13};
    double aDouble{2.503};

    cout << anInt*aDouble << endl;
    
    cout << aDouble/anInt << endl;

    cout << anInt/anotherInt << endl;

    string aString{"This is a string."};
    char aChar{aString[0]};
    cout << aChar << endl;

    return 0;
}