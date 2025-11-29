#include <iostream>
#include <cmath>
using namespace std;


int main(){

    int n;
    int suma = 0;
    cin >> n;

    for (int i = 1; i <= n; i++){
        int producto = 1;
        for(int j = 1; j <= i; j++){
            producto *= pow(j,2);
        }
        suma += producto;
    }

    cout << "La sumatoria de las productorias hasta desde 1 hasta "<< n << " es: "<< suma << endl;

    system ("pause");
    return 0;
}