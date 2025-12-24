#include <iostream>
using namespace std;

void mDecimal(int &decimal) {
    int digit = 0;
    
    while(true){
        cout << "Insert a digit: ";
        cin >> digit;

        if(digit == -1) break;
        decimal = (decimal * 10) + digit;
    }

    cout << decimal << endl;
}

int main() {
    int decimal = 0;
    mDecimal(decimal);

    return 0;
}