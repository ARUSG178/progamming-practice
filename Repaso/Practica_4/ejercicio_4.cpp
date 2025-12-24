#include <iostream>
using namespace std;

void processSequence(int &sumEven, int &sumOdd, int &sumTotal, int &ctEven, int &cOdd, int &cTotal, double &pEven, double &pOdd) {
    int number;
    cout << "Enter numbers (end with 0): " << endl;

    while(true){
        cin >> number;
        if(number == 0) break; 

        sumTotal += number;
        cTotal++;

        if(number % 2 == 0) {
            sumEven += number;
            ctEven++;
        } else {
            sumOdd += number;
            cOdd++;
        }
    }

    if(cTotal > 0){
        pEven = (static_cast<double>(ctEven) / cTotal) * 100;
        pOdd  = (static_cast<double>(cOdd) / cTotal) * 100;
    }
}

int main() {
    int sumEven = 0, sumOdd = 0, sumTotal = 0;
    int ctEven = 0, cOdd = 0, cTotal = 0;
    double pEven = 0.0, pOdd = 0.0;

    processSequence(sumEven, sumOdd, sumTotal, ctEven, cOdd, cTotal, pEven, pOdd);

    cout << "Sum of even numbers: " << sumEven  << " | count: " << ctEven  << " | " << pEven << "%\n";
    cout << "Sum of odd numbers: " << sumOdd  << " | count: " << cOdd << " | " << pOdd << "%\n";
    cout << "Sum of all numbers: " << sumTotal << " | total count: " << cTotal << endl;

    return 0;
}