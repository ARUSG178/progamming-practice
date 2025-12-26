#include <iostream>
#include <string> // Necesario para usar string
using namespace std;

int D2B(int n){
    if (n == 1) return 1;

    return D2B(n/2) + (n % 2) * 10;

}

string D2H(int n) {
    if (n < 16) {
        if (n < 10) return to_string(n);           // Si es 0-9, lo convierte a string
        else return string(1, 'A' + (n - 10));     // Si es 10-15, devuelve 'A'-'F'
    }
    int rem = n % 16;                              // Calcula el resto (último dígito hex)
    string digit = (rem < 10) ? to_string(rem) : string(1, 'A' + (rem - 10));
    return D2H(n / 16) + digit;                    // Llama recursivo y concatena el dígito
}

int main(){
    int n, op;
    cout << "Digite N: ";
    cin >> n;
    cout << "1 | Binario" << endl;
    cout << "2 | Hexadecimal" << endl;
    cin >> op;

    switch (op){
        case 1:
            cout << "El resultado es: " << D2B(n) << endl;
            break;
        case 2:
            cout << "El resultado es: " << D2H(n) << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
    }

    return 0;
}