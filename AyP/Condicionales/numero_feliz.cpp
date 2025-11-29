#include <iostream>
using namespace std;

void numeroFeliz(int numero){
    int ds[4];
    for(int i = 0; i < 4; i++){
        ds[i] = numero % 10;
        numero = numero / 10;    
    }

    int primerPar = ds[3] * 10 + ds[2]; 
    int segundoPar = ds[1] * 10 + ds[0];

    if ((primerPar > segundoPar) && ds[3] < ds[2] && ds[2] < ds[1] && ds[1] < ds[0]) cout << "Numero es feliz y creciente" << endl;
    else if(primerPar > segundoPar) cout << "Numero es feliz" << endl;
    else if(ds[3] < ds[2] && ds[2] < ds[1] && ds[1] < ds[0]) cout << "Numero es creciente" << endl;
    else cout << "Numero no es feliz ni creciente" << endl;
}

int main(){
    int numeroSospechoso;
    cin >> numeroSospechoso;

    if (numeroSospechoso < 0 || numeroSospechoso > 9999) return 1;

    numeroFeliz(numeroSospechoso);

    system("pause");
    return 0;
}