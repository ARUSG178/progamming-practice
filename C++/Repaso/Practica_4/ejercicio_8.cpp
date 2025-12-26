#include <iostream>
using namespace std;

int expresion(int n) {
    int total = 0;
    for(int i = 1; i <= n; i++){
        int produc = 1;
        for(int j = 1; j <= i; j++){
            produc *= j * j;
        }
        total += produc;
    }
    return total;
}

int main(){
    int n;
    cin >> n;

    cout << expresion(n) << endl;

    return 0;
}