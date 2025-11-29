#include <iostream>
#include <cmath>
using namespace std;

void printHipotenusa(double H){
    cout << "Hipotenusa: " << H << endl;
}

void calcularHipotesuna(double C1, double C2){

    double H = sqrt(pow(C1,2) + pow(C2,2));
    printHipotenusa(H);
}

int main(){

    double C1, C2;
    cin >> C1 >> C2;
    
    calcularHipotesuna(C1, C2);

    system("pause");
    return 0;
}