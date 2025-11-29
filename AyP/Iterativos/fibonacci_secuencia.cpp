#include <iostream>
using namespace std;

int main(){
    int numero, x = 0, y = 1, z = 0;

    cin >> numero;

    cout << "La secuencia de Fibonnaci hasta "<< numero <<" es: ";
    while(x <= numero){
        cout << x;
        z = x + y;
        x = y;
        y = z;

        if (x <= numero) cout << ", ";
    }
    cout << ".";

    system ("pause");
    return 0;
}