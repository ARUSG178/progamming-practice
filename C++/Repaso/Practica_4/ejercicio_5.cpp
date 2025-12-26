#include <iostream>
using namespace std;

void binary(int &decimal){

   int idx = 0, digit;
    while(true){

        cout << "Insert digit (-1 to end): ";
        cin >> digit;

        if (digit == -1) break;
        if (digit == 0 || digit == 1)  decimal = decimal * 2 + digit;
        else  cout << "Number invalid, only 0 and 1 or -1 allowed";
    }
}

int main () {
    int decimal = 0;
    binary(decimal);

    cout << "The value in decimal is: " << decimal << endl;

    return 0;
}