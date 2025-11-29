#include <iostream>
#include <ctime>
using namespace std;

void desplazamientosK (int* conjunto, int tamanio, int K){
    int aux = 0;
 
    while(K > 0){
        aux = conjunto[0];
        for(int i = 0; i < tamanio - 1; i++){
            conjunto[i] = conjunto[i + 1];
        }
        conjunto[tamanio - 1] = aux;
        K--;
    }

    for(int i = 0; i < tamanio; i++){
        cout << conjunto[i] << " ";
    }
}

int main(){
    srand((unsigned int)time(NULL));
    int tamanio;
    cin >> tamanio;

    int* arreglo = new int [tamanio];

    for(int i = 0; i < tamanio; i++){
        arreglo[i] = rand() % 100 + 1;
        }
    
    for(int i = 0; i < tamanio; i++){
        cout << arreglo[i] << " ";
    }

    int K;
    cin >> K;

    cout << endl;
    desplazamientosK(arreglo, tamanio, K);
    
    delete [] arreglo;

    return 0;
}