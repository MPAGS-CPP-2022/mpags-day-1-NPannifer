#include <iostream>
#include <string>
using namespace std;

int main(){
    const double aConstDouble{0.5772};
    cout << aConstDouble << endl;

    const int aConstInt{420};
//    aConstInt++;      //will throw error if uncommented

    string aString{"This is a string."};
    cout << aString << endl;

    return 0;

}