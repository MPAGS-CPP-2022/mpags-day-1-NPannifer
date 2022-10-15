#include <iostream> 
#include <string>
using namespace std;

int main(){
    char in_char{'x'};
    string out_str{""};

    while(cin >> in_char)
    {   
        if(isalpha(in_char)){
            out_str += toupper(in_char);
        }

        switch(in_char){
            case '0':
                out_str += "zero";
                break;
            case '1':
                out_str += "one";
                break;
            case '2':
                out_str += "two";
                break;
            case '3':
                out_str += "three";
                break;
            case '4':
                out_str += "four";
                break;
            case '5':
                out_str += "five";
                break;
            case '6':
                out_str += "six";
                break;
            case '7':
                out_str += "seven";
                break;
            case '8':
                out_str += "eight";
                break;
            case '9':
                out_str += "nine";
                break;
            default:
                out_str += "";
                break;
            }
            
        }
      
    cout << out_str << endl;
    return 0;
}