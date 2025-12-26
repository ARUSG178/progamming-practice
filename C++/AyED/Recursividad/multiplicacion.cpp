#include <iostream>
using namespace std;

double multiplicacion(double A, double B){

    if (B == 1) return A;
    
    return A + multiplicacion(A, B - 1);
}

int main(){

    cout << multiplicacion (8, 4) << endl;

    return 0;
}



