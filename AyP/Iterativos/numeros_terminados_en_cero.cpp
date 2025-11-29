/*Dada una secuencia de números terminada en cero, elaborar un algoritmo para calcular el porcentaje y 
la suma de los números impares, el porcentaje y la suma de los números pares, y la suma de todos los números, 
y cuántos números fueron ingresados.*/

#include <iostream>
using namespace std;

int main(){

    int numero, suma_total = 0, suma_pares = 0, suma_impares = 0, porcentaje_p = 0, porcentaje_imp = 0, contador = 0;

    cout << "Ingresa un numero (para terminar escribe 0): " << endl;
    cin >> numero;

    while(numero != 0){

        suma_total += numero;
        contador ++;

        (numero % 2 == 0) ? suma_pares += numero : suma_impares += numero;
        
        cout << "Ingresa otro numero (para terminar escribe 0): " << endl;
        cin >> numero;
    }

    if(suma_total > 0){
    porcentaje_p = (contador > 0)? (double)suma_pares*100/suma_total : 0;
    porcentaje_imp = (contador > 0)? (double)suma_impares*100/suma_total : 0;
    }

    cout << "La cantidad de numeros ingresados es: " << contador << endl;
    cout << "La suma de todos los numeros es: " << suma_total << endl;
    cout << "La suma de los numeros pares es: " << suma_pares << endl;
    cout << "La suma de los numeros impares es: " << suma_impares << endl;
    cout << "El porcentaje de los numeros pares es: " << porcentaje_p << endl;
    cout << "El porcentaje de los numeros impares es: " << porcentaje_imp << endl;

    system ("pause");
    return 0;
}