#include <iostream>
using namespace std;

int amountDigits(int n){
    int d = 0;

    while (n > 0) {
        n /= 10;
        d++;
    }

    return d;
}

int main () {
    int number;
    cin >> number;

    cout << amountDigits(number) << endl;

    return 0;
}