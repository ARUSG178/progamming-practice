#include <iostream>
#include <cmath>
using namespace std;

int saberContador(int numero, int contador){
    while(numero > 0){
        numero /= 10;
        contador++;
    }
    return contador;
}

int kDigitos(int numero, int digitos){
    int contador = saberContador(numero, contador);
    int numeroNuevo = numero / (pow(10, contador - digitos));
    return numeroNuevo;
}


int main(){

    int N, K;
    cin >> N >> K;

    int numeroK = kDigitos(N, K);
    cout << numeroK << endl;

    system("pause");
    return 0;
}