#include <iostream>
#include <cmath>
using namespace std;

double A, B, C;

double discriminanteValor(double A, double B, double C){
    double discriminante = pow(B,2) - (4 * A * C);
    return discriminante;
}

void verificarSoluciones(double discriminante, double &X1, double &X2){

    if (discriminante > 0){
        X1 = B + sqrt(discriminante)/2 * A;
        X2 = B - sqrt(discriminante)/2 * A;
        cout << "La ecuación tiene dos soluciones reales: " << X1 << " y " << X2 << endl;
    }else if(discriminante == 0){
        X1 = -B/(2*A);
        cout << "La ecuación tiene una solución real: " << X1 << endl;
    }else{
        cout << "La ecuación no tiene soluciones reales" << endl;
    }
}

int main(){

    double X1 = 0, X2 = 0;

    cin >> A >> B >> C;

    double discriminante = discriminanteValor (A, B, C);
    verificarSoluciones(discriminante, X1, X2);

    system ("pause");
    return 0;
}