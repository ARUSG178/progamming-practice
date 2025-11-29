#include <iostream>
using namespace std;

void Capicua(int* arreglo, int tamanio){
    int segmento[3];
    for(int i = 0; i < tamanio - 2; i++){
        if(arreglo[i] == arreglo[i + 2]){
            cout << "Existe capicua: ";
            for(int j = 0; j < 3; j++){
                segmento[j] = arreglo[i + j];
                cout << segmento[j];
            }
            cout << endl;
        } 
          
    }
}

int main(){

    int tamanio;
    cin >> tamanio;

    int* conjunto = new int [tamanio];
    for (int i = 0; i < tamanio; i++) {
        cin >> conjunto[i];
    }

   Capicua(conjunto, tamanio);

    delete [] conjunto;

    system("pause");
    return 0;
}