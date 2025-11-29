#include <iostream>
#include <ctime>
using namespace std;

void sumaDeArreglos(int* conjuntoA, int tamanioA, int* conjuntoB, int tamanioB){
    int i = 0, j = 0, k = 0;
    int tamanioC = tamanioA + tamanioB;
    int* conjuntoC = new int[tamanioC];

    while(i < tamanioA && j < tamanioB){
        if(conjuntoA[i] < conjuntoB[j]) conjuntoC[k++] = conjuntoA[i++];
        else conjuntoC[k++] = conjuntoB[j++];
    }

    while(i < tamanioA) conjuntoC[k++] = conjuntoA[i++];

    while(j < tamanioB) conjuntoC[k++] = conjuntoB[j++];

    // Ordenar el arreglo conjuntoC utilizando el algoritmo de ordenamiento por inserción
    for(int i = 1; i < tamanioC; i++){
        int clave = conjuntoC[i];
        int j = i - 1;
        while(j >= 0 && conjuntoC[j] > clave){
            conjuntoC[j + 1] = conjuntoC[j];
            j--;
        }
        conjuntoC[j + 1] = clave;
    }

    for(int m = 0; m < tamanioC; m++){
        cout << conjuntoC[m] << " ";
    }
    cout << endl;
    delete[] conjuntoC;
}

int main(){
    srand((unsigned int)time(NULL));
    int tamanioA, tamanioB;
    cout << "Ingrese el tamaño del primer arreglo: ";
    cin >> tamanioA;
    cout << "Ingrese el tamaño del segundo arreglo: ";
    cin >> tamanioB;

    int* conjuntoA = new int[tamanioA];
    for(int i = 0; i < tamanioA; i++){
        conjuntoA[i] = rand() % 10 + 1;
    }

    int* conjuntoB = new int[tamanioB];
    for(int i = 0; i < tamanioB; i++){
        conjuntoB[i] = rand() % 10 + 1;
    }

    for(int i = 0; i < tamanioA; i++){
        cout << conjuntoA[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < tamanioB; i++){
        cout << conjuntoB[i] << " ";
    }
    cout << endl;

    sumaDeArreglos(conjuntoA, tamanioA, conjuntoB, tamanioB);

    delete[] conjuntoA;
    delete[] conjuntoB;

    return 0;
}