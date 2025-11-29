#include <iostream>
using namespace std;

int main(){

    int numero, numero_c;

    cin >> numero;

    while(numero != -1){

        numero_c = numero_c * 10 + numero;
        cin >> numero;
    }

    cout << numero_c << endl;


    system ("pause");
    return 0;
}