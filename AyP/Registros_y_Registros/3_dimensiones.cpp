#include <iostream>
#include <math.h>
using namespace std;

struct puntoTridi{
    int x, y, z;
} p1, p2;

void registrarps(){
    cout << "Registre el primer p" << endl;
    cin >> p1.x >> p1.y >> p1.z;

    cout << "Registre el segundo p" << endl;
    cin >> p2.x >> p2.y >> p2.z;
}

double distanciaEntrePts(){
    return sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2) + pow(p1.z - p2.z,2));
}

int main(){
    registrarps();    
    double d = distanciaEntrePts();
    cout << "La distancia entre los puntos es: " << d << endl;

    return 0;
}