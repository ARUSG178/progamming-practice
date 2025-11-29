#include <iostream>
using namespace std;

int numero, contador;

int main(){

    cin >> numero;

    do{
        numero /= 10;
        contador ++;

        }while(numero != 0);

    cout << "El numero tiene "<< contador << " digitos." << endl;

    system("pause");
    return 0;
}