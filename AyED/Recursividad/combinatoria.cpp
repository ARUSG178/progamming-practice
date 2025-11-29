#include <iostream>
using namespace std;

int combinatoria(int n, int m){
    if(n == 0 || m == n) return 1;

    return combinatoria(n - 1, m - 1) + combinatoria(n - 1, m);
}

int main(){
    int n, k;
    cout << "Digite N y K ";
    cin >> n >> k;
    cout << "El resultado es: " << combinatoria(n, k) << endl;

    return 0;
}