#include <iostream>
using namespace std;

int mElemento(int* arreglo, int n){
    if(n == 1) return arreglo[0];

    int eMaximo = mElemento(arreglo, n - 1);

    if(arreglo[n - 1] > eMaximo) return arreglo[n - 1];
    else return eMaximo;
}

int sumaArr(int* arreglo, int n){
    if(n == 1) return arreglo[0];

    return arreglo[n - 1] + sumaArr(arreglo, n - 1);
}

int promedioArr(int* arreglo, int n){
    sumaArr(arreglo, n);
    return sumaArr(arreglo, n) / n;
}

bool ordenado(int* arreglo, int n){
    if(n == 1) return true;

    if(arreglo[n - 1] < arreglo[n - 2]) return false;

    return ordenado(arreglo, n - 1);
}

int main(){
    int uwu;
    cout << "Digite tamanio arreglo" << endl;
    cin >> uwu;

    int* arreglo = new int[uwu];
    cout << "Digite los elementos del arreglo" << endl;
    for (int i = 0; i < uwu; i++){
        cin >> arreglo[i]; 
    }


}