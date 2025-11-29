#include <iostream>
using namespace std;

int invertirNumero(int numero){
    int invertido = 0;
    while (numero != 0){
        invertido = invertido * 10 + numero % 10;
        numero = numero / 10;
        }
    return invertido;
}

void confirmarCapicua(int invertido, int numero){
    (invertido == numero) ? cout << "Es capicua" : cout << "No es capicua" << endl;
}

int main(){      

    int numero, capicua = false;

    cin >> numero;

    int invertido = invertirNumero(numero);
    confirmarCapicua(invertido, numero);

    system("pause");
    return 0;
}