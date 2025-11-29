#include <iostream>
using namespace std;

void imprimirDobleCuadrado(int N){

    while(N != 0){
        if(N % 2 == 0){
            for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){
                    if(i == 0 || j == 0 || i == N - 1 || j == N - 1) cout << "X ";
                    else cout << "  ";
                }

            cout << "\n";   
            }

        cout << "\n";  
        }
        N -=2;
    }
}


int main(){

    int N;
    cin >> N;

 imprimirDobleCuadrado(N);

    system ("pause");
    return 0;
}