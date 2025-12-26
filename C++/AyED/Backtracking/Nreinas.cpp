#include <iostream>
#include <cmath>
using namespace std;

int contador = 0;

bool comprobar(int* tablero, int k, int n){
    int i;
    for(i = 0; i < k; i++){
        if( (tablero[i] == tablero[k]) || (abs(tablero[i] - tablero[k]) == abs(i - k)) ){
            return false; // Hay conflicto entre reinas
        }
    }
    return true;
}

void posicionarReinas(int* tablero, int k, int n){
    // Todas las reinas fueron colocadas en sus columnas.
    if(k == n){
            contador++;
            cout << "Solucion #" << contador << ": ";
            for (int i = 0; i < n; i++) {
                cout << tablero[i] << " ";
            }
            cout << endl << endl;
    }
    // Aun quedan reinas por colocar.
        for(tablero[k] = 0; tablero[k] < n; tablero[k]++){
            if(comprobar(tablero, k, n)){
                // Colocar la reina en la fila correspondiente.
                posicionarReinas(tablero, k + 1, n);
            }
        }
}

int main() {
    int k = 0;
    int nReinas;
    cout << "Ingrese el número de reinas: ";
    cin >> nReinas;
    int* tablero = new int[nReinas]; // Tablero[columna de la reina] = fila de la reina
    for (int i = 0; i < nReinas; i++) {
        tablero[i] = 0;
    }

    posicionarReinas(tablero, k,  nReinas);

    delete[] tablero; // Liberar memoria
    return 0;
}