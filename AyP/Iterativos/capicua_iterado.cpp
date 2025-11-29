/*Haga un algoritmo que determine si un número es capicúa (palíndrome). 
Un número es capicúa si se lee igual al derecho y a revés.*/

#include <iostream>
using namespace std;

int main(){

    int numero, numero_i = 0;

    cin >> numero;
    int aux = numero;

    for (; numero > 0; numero /= 10){
        int digito = numero % 10;
        numero_i = numero_i * 10 + digito;
    }

    if (numero_i == aux) cout << "El número es capicúa" << endl;
    else cout << "El número no es capicúa" << endl;

    system("pause");
    return 0;
}