#include <iostream>
#include <ctime>
using namespace std;

void paresImpares(int* conjunto, int tamanio, int &pares, int &impares){
    for (int i = 0; i < tamanio; i++) {
        if(conjunto [i] % 2 == 0) pares ++;
        else impares++;
    }
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
    cout << endl;

    int pares = 0, impares = 0;

    paresImpares(arreglo, tamanio, pares, impares);

    cout << "Pares: " << pares << endl;
    cout << "Impares: "<< impares << endl;

    delete [] arreglo;
}