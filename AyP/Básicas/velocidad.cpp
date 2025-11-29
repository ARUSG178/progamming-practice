#include <iostream>
using namespace std;

void calcularVelocidad(double D, double T){
    double V = D/T;
    cout << "La velocidad es: " << V << " m/s" << endl;
}

int main(){

    double D, T;
    cin >> D >> T;

    system("pause");
    return 0;
}