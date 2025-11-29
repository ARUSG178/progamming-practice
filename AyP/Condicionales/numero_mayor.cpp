#include <iostream>
using namespace std;

void numeroMayor(int A, int B){
    if (A > B) cout << "El número mayor es " << A << endl;
    else cout << "El número mayor es " << B << endl;
}

int main(){

    int numeroA, numeroB;
    cin >> numeroA >> numeroB;

    numeroMayor (numeroA, numeroB);

    system ("pause");
    return 0;
}