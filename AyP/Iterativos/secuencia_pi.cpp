/*Escriba un algoritmo utilizando un ciclo para que calcule el valor aproxi-
mado de π usando la serie: π = 4 − 4/3 + 4/5 − 4/7 + 4/9 ... +- 4/n; */


#include <iostream>
using namespace std;

int main(){

    int n;
    float pi = 3.14;
    bool positivo = true;

    cin >> n;

    for(int i = 1; i <= n; i += 2){

        (positivo == true) ? pi += 4.0/i : pi -= 4.0/i;
        positivo = !positivo;
    }

    cout << "El valor aproximado de π es: " << pi << endl;

    system ("pause");
    return 0;
}