#include <iostream>
using namespace std;

void dentroDelIntervalo(int inferior, int superior, int valor){
    if(inferior < valor && valor < superior) cout << "Está en el intervalo" << endl;
    else cout << "No está en el intervalo" << endl;
}

int main(){

    int valor1, valor2, X;
    cin >> valor1 >> valor2 >> X;
    dentroDelIntervalo(valor1, valor2, X);

    system("pause");
    return 0;
}