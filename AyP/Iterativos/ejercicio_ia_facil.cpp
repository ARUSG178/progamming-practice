#include <iostream>
using namespace std;

int main(){
    
    int numero, sumatoria = 0, productoria = 1, pares = 0;

    cin >> numero;

    int i = 1;

    for(i; i <= numero; i++) sumatoria += i;

    cout << "La sumatoria desde 1 hasta "<< numero << " es: " << sumatoria << endl;

    int j = 1;
    while(j <= numero) productoria *= j, j++;

    cout << "La productoria desde 1 hasta "<< numero << " es: " << productoria << endl;

    int k = 1;
    do {if(k % 2 == 0) pares++;
        k++;
    }while (k <= numero);
    cout << "La cantidad de pares desde 1 hasta "<< numero << " es: " << pares << endl;

    system ("pause");
    return 0;
}