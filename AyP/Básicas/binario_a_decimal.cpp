#include <iostream>
#include <cmath>
using namespace std;

void printDecimal(int decimal){
    cout << decimal << endl;
}

void binarioDecimal(int binario){
    int decimal = 0;

    for(int i = 0; i < 4; i++){
        decimal += (binario % 10) * pow(2,i);
        binario /= 10;
    }
    
    printDecimal(decimal);
}

int main(){

    int binario;

    cin >> binario;

    if (binario < 1000 || binario > 1111) return 1;

    binarioDecimal(binario);

    system("pause");
    return 0;
}