#include <iostream>
using namespace std;

int numeroReverso(int numero){
    int reverso[4];
    for (int i = 0; i < 4; i++){
        reverso [i] = numero % 10;
        numero = numero / 10;
    }

    int numeroFinal = 0;
    for (int j = 0; j < 4; j++){
        numeroFinal = numeroFinal * 10 + reverso[j];
    }

    return numeroFinal;
}

void printReverso(int reverso){
    cout << reverso << endl;
}

int main (){

    int numero, reverso = 0;

    cout << "Ingrese un numero: ";
    cin >> numero;

    reverso = numeroReverso(numero);

    printReverso(reverso);

    system ("pause");
    return 0;
}  