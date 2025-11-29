#include <iostream>
#include <cmath>
using namespace std;

float calculoAreaT(float base, float altura){
    return base * altura/2;
}

float calculoAreaC(float radio){
    return 3.14159 * pow(radio, 2);
}

void printAreas(float areaT, float areaC){
    cout << ((areaT > areaC) ?  "El area del triangulo es mayor" : "El area del circulo es mayor") << endl;
}

int main(){

    float bT, aT, rC;
    float areaT, areaC;
    cin >> bT >> aT >> rC;

    areaT = calculoAreaT(bT, aT);
    areaC = calculoAreaC(rC);

    printAreas(areaT, areaC);

    system("pause");
    return 0;
}