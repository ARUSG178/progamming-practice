#include <iostream>
using namespace std;

int revers(int num){
    int rev = 0;
    while (num > 0){
        int digit = num % 10;
        rev = rev * 10 + digit;
        num = num / 10;
    }
    return rev;
}

int main (){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Reversed number: " << revers(num) << endl;
    return 0;
}