/*Escriba un algoritmo que imprima por pantalla en borde de un cuadrado de 
lados de tamaño N . Por ejemplo, si N = 5, el algoritmo debería imprimir:

XXXXX
X   X
X   X
X   X
XXXXX

*/

#include <iostream>
using namespace std;

int main() {
    int N;

    cin >> N;
    
    for (int i = 0; i < N; i++){

        for (int j = 0; j < N; j++){

            if(i == 0 || j == 0 || i == N - 1 || j == N - 1) cout << "X ";
            else cout << "  ";
            }

        cout << "\n";   
    }

    cout << "\n";  
      
system("pause");
return 0;
}    