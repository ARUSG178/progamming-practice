/*Escriba un algoritmo que tome como entrada una secuencia de números 0 y 1 terminada en −1 que representan un número binario
 y calcule el número decimal representado. Por ejemplo, si la secuencia es 1 0 0 1 0 1 -1, su algoritmo debe imprimir 37.*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int binario, binario_c = 0;
    int decimal = 0;
    int c_digitos = 0;

    cin >> binario;

    while(binario != -1){

        binario_c = binario_c * 10 + binario;
        c_digitos ++;
        cin >> binario;
    }

    for(int i = 0; i < c_digitos; i++){
        int b_a_d = binario_c % 10;
        decimal += b_a_d * pow(2,i);
        binario_c = binario_c / 10;
    }

    cout << decimal << endl;

    system ("pause");
    return 0;
}