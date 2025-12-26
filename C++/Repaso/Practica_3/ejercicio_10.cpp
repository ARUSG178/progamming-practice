#include <iostream>
using namespace std;

bool isPrime(int number){
    if (number == 1) return false;
    for (int i = 2; i*i <= number; i++) if(number % i == 0) return false;
    return true;
}

int main() {
    int number;
    cout << "Enter the number: ";
    cin >> number;

    if (number > 100) {
        cout << "Invalid format" << endl;
        return 1;
    }

    if(isPrime(number)) cout << "The number " << number << " is prime" << endl;
    else  cout << "The number " << number << " isn't prime" << endl;

    return 0;
}