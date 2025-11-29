#include <iostream>
using namespace std;

float valorX(float m1, float b1, float m2, float b2){
    return (b2 - b1) / (m1 - m2);
}

int main(){

    float x = 0, y = 0, m1, m2, b1, b2;
    cin >> x >> m1 >> b1 >> m2 >> b2;

    x = valorX(m1, b1, m2, b2);
    y = m1 + x + b1;

    cout << "La intercepción de las dos rectas que no son paralelas esta en el par ordenado: ("<< x << "," << y <<")." << endl;

    system ("pause");
    return 0;
}