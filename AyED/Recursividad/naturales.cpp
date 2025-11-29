#include <iostream>
using namespace std;

int nNaturales(int n){
    if(n == 0) return 0;

    return n + nNaturales(n - 1);
}

int main(){
    int n;
    cout << "Digite N: ";
    cin >> n;

    cout << "El resultado es: " << nNaturales(n) << endl;

    return 0;
}