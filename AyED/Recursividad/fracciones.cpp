#include <iostream>
using namespace std;

float sumaFracciones(int n){
    if (n == 1) return 1.0;

    return 1.0/n + sumaFracciones(n - 1);

}

int main(){
    int n;
    cout << "Digite el numero de fracciones: ";
    cin >> n;

    float resultado = sumaFracciones(n);
    cout << "El resultado es: " << resultado << endl;

    return 0;
}