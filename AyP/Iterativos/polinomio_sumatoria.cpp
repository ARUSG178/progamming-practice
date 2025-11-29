#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int n = 0;
    float x = 0, a, polinomio = 0;
    
    cout << "Ingrese el grado del polinomio (n): ";
    cin >> n;
    cout << "Ingrese el valor de x: ";
    cin >> x;

    for (int i = 0; i <= n - 1; i++){
        cin >> a;
        polinomio += a*pow(x,i);
    }

    cout << polinomio;

    system("pause");
    return 0;
}