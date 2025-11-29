#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void insercionK(int* conjunto, int tamanio, int K){
    for(int i = 0; i < tamanio; i++){
        conjunto[(int)pow(2,i)] = K;
    }

    for(int i = 0; i < tamanio; i++){
        cout << conjunto [i] << " ";
    }
}

int main(){
    srand(time(NULL));
    int tamanio;
    cin >> tamanio;

    int* arreglo = new int [tamanio];

    for(int i = 0; i < tamanio; i++){
       arreglo[i] = rand() % 100 + 1;
    }

     for(int i = 0; i < tamanio; i++){
        cout << arreglo [i] << " ";
    }
    cout << endl;
    
    int K;
    cin >> K;

    insercionK(arreglo, tamanio, K);

    delete [] arreglo;

    return 0;
}