#include <iostream>
#include <ctime>
using namespace std;

int valorMax(int* conjunto, int tamanio){
    int maximo = conjunto[0];
    for(int i = 0; i < tamanio; i++){
        if (maximo < conjunto [i]) maximo = conjunto [i];
    }

    return maximo;
}

int main(){

    srand(time(NULL));

    int tamanio;
    cin >> tamanio;

    int* arreglo = new int [tamanio];

    for(int i = 0; i < tamanio; i++){
        arreglo[i] = rand() % 101;
    }

    for(int i = 0; i < tamanio; i++){
        cout << arreglo[i] << ", ";
    }

    int maximo = valorMax(arreglo, tamanio);
    cout << "\nValor máximo es de: "<< maximo << endl;

    delete[] arreglo;
    
    return 0;
}