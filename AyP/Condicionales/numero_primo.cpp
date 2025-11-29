#include <iostream>
#include <limits>
using namespace std;

bool numeroPrimo(int numero){
    if (numero <= 1) return false;
    for (int i = 2; i < numero; i++) {
        if (numero % i == 0) return false;
        }
        return true;
}

int main(){
    int numero;
    while(true){
        cin >> numero;
        if(cin.fail() || numero < 0 || numero > 100){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Por favor, ingrese un número entre 0 y 100: ";
        }
    }

    bool esPrimo = numeroPrimo(numero);
}