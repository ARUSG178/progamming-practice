#include <iostream>
using namespace std;

int invertir(int n, int res = 0) {
    if (n == 0) return res; // Caso base: ya no hay más dígitos
    return invertir(n / 10, res * 10 + n % 10); // Paso recursivo
    return 0;
}

int main(){
    int n;
    cout << "Ingresar N: ";
    cin >> n;

    cout << "Num invertido: " << invertir(n) << endl;

    return 0;
}