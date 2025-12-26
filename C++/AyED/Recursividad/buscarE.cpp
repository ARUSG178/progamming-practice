#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

bool condicion(int a, int b){
    return a <= b;
}

void ordenar(int* arr, int inf, int sup) {
    if (inf >= sup) return;

    int pivot = arr[sup]; 
    int i = inf, j = sup - 1;

    while (i < j) {
        if (condicion(arr[i], pivot)) {
            i++;
        } else {
            swap(arr[i], arr[j]);
            j--;
        }
    }
    
    if (!condicion(arr[i], pivot)) {
        swap(arr[i], arr[sup]);
    }

    ordenar(arr, inf, i - 1);
    ordenar(arr, i + 1, sup);
}

bool busquedaBinaria(int* arr, int inf, int sup, int valor){
    if (inf > sup) return;

    int mid = (sup + inf)/ 2;
    if (arr[mid] == valor) return true;
    else if (arr[mid] < valor) busquedaBinaria(arr, mid + 1, sup, valor);
    else busquedaBinaria(arr, inf, mid - 1, valor);
    
}

int main(){
    int n, e;
    cin >> n;
    int* uwu = new int [n];

    for(int i = 0; i < n; i++){
        cin >> uwu[i];
    }
    cout << "Valor a buscar: ";
    cin >> e;
    
    ordenar(uwu, 0, n - 1); // Ordena el arreglo antes de buscar

    if (busquedaBinaria(uwu, 0, n - 1, e))
        cout << "Encontrado" << endl;
    else
        cout << "No encontrado" << endl;

    delete[] uwu;

    return 0;
}
