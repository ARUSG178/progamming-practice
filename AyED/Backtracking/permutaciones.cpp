#include <iostream>
using namespace std;



void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void printPermutacion(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void permutaciones(int* arr, int n, int idx) {
    if (idx == n) {
        printPermutacion(arr, n);
        return;
    }else {
        for(int i = idx; i < n; i++) {
            swap(arr[idx], arr [i]);
            permutaciones(arr, n, idx + 1);
            swap(arr[idx], arr[i]); // Backtrack
        }
    }
}

void permSumaPar(int* arr, int n, int idx) {
    if (idx == n) {
        int suma = 0;
        for (int i = 0; i < n; i++) {
            suma += arr[i];
        }
        cout << "Suma: " << suma << endl;
        if(suma % 2 == 0) {
            printPermutacion(arr, n);
        }
        return;
    }else {
        for(int i = idx; i < n; i++) {
            swap(arr[idx], arr [i]);
            permSumaPar(arr, n, idx + 1);
            swap(arr[idx], arr[i]); // Backtrack
        }
    }
}

int main(){

    int n, op;
    cout << "Ingrese el número de elementos: ";
    cin >> n;
    int* uwu = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> uwu[i];
    }

    cout << "Elija una opción: " << endl;
    cout << "1. Generar todas las permutaciones" << endl;
    cout << "2. Generar permutaciones con suma par" << endl;
    cin >> op;
    cout << endl;
    if(op == 1){
        cout << "Todas las permutaciones son: " << endl;
        permutaciones(uwu, n, 0);
    }else if(op == 2){
        cout << "Las permutaciones con suma par son: " << endl;
        permSumaPar(uwu, n, 0);
    }else{
        cout << "Opción no válida." << endl;
        delete[] uwu; // Liberar memoria
        return 0;
    }

    delete[] uwu; // Liberar memoria

    return 0;
}