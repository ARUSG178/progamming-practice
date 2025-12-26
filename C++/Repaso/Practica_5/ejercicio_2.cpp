#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int N){
    int numCeros = 0;
    while(N > 0){
        N /= 10;
        numCeros++;
    }
return numCeros;
}

void extraerDigitos(int N, int K) {

    int quitar = countDigits(N) - K;
    int divisor = pow(10, quitar) ;
    int dExtraidos = N / divisor;

    cout << dExtraidos << endl;
}

int main (){

    int N, K;
    cout << "Enter N and K: ";
    cin >> N >> K;

    extraerDigitos(N, K);

    return 0;
}