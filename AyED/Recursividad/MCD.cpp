#include <iostream>
using namespace std;

int MCD(int a, int b){
    
    if (b == 0) return a; // Caso base

    if (a > b) return MCD(a - b, b); // Si A es mayor que B, resta A - B
    else if (b > a) return MCD(a, b - a); // Si B es mayor que A, resta B - A
    else if (a == b) return a; // Si son iguales, devuelve A o B
    else return 0; // Si no se cumple ninguna de las condiciones anteriores, devuelve 0

}

int main(){
    int a, b;
    cout << "Digite A y B: ";
    cin >> a >> b;

    cout << "El resultado es: " << MCD(a, b) << endl;
    return 0;
}