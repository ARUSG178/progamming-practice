#include <iostream>
#include <ctime>
using namespace std;

void promedioConN(int* conjunto, int tamanio, int N, int &mayores, double &promedio){
    int contador = 0;
    int acumulado = 0;
    for(int i = 0; i < tamanio; i++){
        if(conjunto[i] > N){
            contador++;
            acumulado += conjunto[i];
            }   
    }

    mayores = contador;
    promedio = acumulado / contador;
}

int main(){
    srand(time(NULL));
    int tamanio, mayoresN = 0; 
    double promedioDeMayores = 0;
    cin >> tamanio;

    int* arreglo = new int [tamanio];
    for(int i = 0; i < tamanio; i++){
        arreglo[i] = rand() % 101;
    }

    for(int i = 0; i < tamanio; i++){
        cout << arreglo[i] << ", ";
    }
    cout << endl;

    int N;
    cin >> N;

    promedioConN(arreglo, tamanio, N, mayoresN, promedioDeMayores);

    cout << "Cantidad de numeros mayores: "<< mayoresN << endl;
    cout << "Promedio de los numeros mayores: "<< promedioDeMayores << endl;

    delete [] arreglo;

    return 0;
}