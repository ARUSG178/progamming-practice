#include <iostream>
using namespace std;

void printFibonacci(int n){
    int d1 = 0, d2 = 1;
    while (d1 <= n) {
        cout << d1 << ", ";
        int aux = d2;
        d2 += d1;
        d1 = aux;
    }
}

int main() {

    int n;
    cin >> n;
    
    printFibonacci(n);

    return 0;
}