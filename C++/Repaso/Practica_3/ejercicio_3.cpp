#include <iostream>
using namespace std;

int greaterNumber(int numA, int numB){
    if(numA > numB) return numA;
    else return numB;
}

int main (){
    int numA, numB;
    cout << "Enter the numbers to find out which is greater. [firts number, second number]: ";
    cin >> numA >> numB;

    cout << "The greater number between the two is: " << greaterNumber(numA, numB) << endl;

    return 0;
}