#include <iostream>
#include <ctime>
using namespace std;

int numeroQueMasSeRepite(int* conjunto, int tamanio){
    int contador[101];
    for(int i = 0; i < 101; i++){
    contador[i] = 0;
    }
    
    for(int i = 0; i < tamanio; i++){
        contador[conjunto[i]]++;
    }

    int valorMaximo = 0;
    int indiceMaximo = 0;

    for(int i = 0; i < 101; i++){
        if(valorMaximo < contador[i]){
            valorMaximo = contador[i];
            indiceMaximo = i;
        }
    }
    return indiceMaximo;
}

int main(){
    srand((unsigned int)time(NULL));
    int tamanio;
    cin >> tamanio;
    
    int* arreglo = new int[tamanio];
    for (int i = 0; i < tamanio; i++) {
        arreglo[i] = rand() % 100 + 1;
    }

    for (int i = 0; i < tamanio; i++) {
        cout << arreglo[i] << " ";
        if((i + 1) % 10 == 0) cout << endl;
    }

    int masFrecuente = numeroQueMasSeRepite(arreglo, tamanio);
    cout << endl << "El número que mas se repite es: " << masFrecuente << endl;

    delete [] arreglo;
    
    system("pause");
    return 0;
}