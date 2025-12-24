#include <iostream>
#include <cmath>
using namespace std;

double hptsCalculus(int legA, int legB){
    return sqrt(pow(legA,2) + pow(legB,2));
}

int main (){

    int legA, legB;
    cout << "Enter leg's values [A, B]: " << endl;
    cin >> legA >> legB;

    double hipotenuse = hptsCalculus(legA, legB);
    cout << "The long of hipotenuse is: " << hipotenuse << endl;

    return 0;
}
