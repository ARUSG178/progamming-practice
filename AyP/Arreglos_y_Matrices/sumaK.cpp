#include <iostream>
#include <ctime>
using namespace std;

bool ExisteSumaK(int* conjunto, int tamanio, int K){
    for(int i = 0; i < tamanio; i++){
        for(int j = i + 1; j < tamanio; j++){
            if(conjunto[i] + conjunto[j] == K) return true;
        }
    }
    return false;
}

int main(){
    srand((unsigned int)time(NULL));
    int tamanio, K;
    cin >> tamanio;

    int* arreglo = new int [tamanio];
    for(int i = 0; i < tamanio; i++){
        arreglo[i] = rand() % 10 + 1;
        cout << arreglo[i] << " ";
    }

    cin >> K;

    bool SumaK = ExisteSumaK(arreglo, tamanio, K);
    cout << ((SumaK == true) ? "Si hay digitos que sumen K" : "No hay digitos que sumen K") << endl;
    
    delete[] arreglo;
    
    return 0;
}