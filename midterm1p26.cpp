#include <iostream>
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {
    char char1;
    char char2;
    char char3;
    char result;
    
    cout << "Please enter a lowercase character: ";
    cin >> char1;
    cout << "Please enter a lowercase character: ";
    cin >> char2;
    cout << "Please enter a lowercase character: ";
    cin >> char3;
    
    if (char1 < char2) {
        if (char1 < char3){
            result = char1;
        }else{
            result = char3;
        }
    }else{
        if (char2 < char3){
            result = char2;
        }else{
            result = char3;
        }
    }
    cout << result;

    return 0;
}