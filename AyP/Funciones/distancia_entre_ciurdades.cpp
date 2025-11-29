#include <iostream> 
#include <string>
using namespace std;

double millasKilometro(double distanciaMillas){
    return distanciaMillas * 1.6;
}

bool seguirEjecutandose(string ciudad1, string ciudad2, double distancia) {
    return (ciudad1 == ciudad2 && distancia == 0) ? false : true;
}

void siguientesCiudades(string &ciudad1, string &ciudad2, double &distancia){
    cin >> ciudad1 >> ciudad2 >> distancia;   
}

void printCiudades(string ciudad1, string ciudad2, double distancia){
    cout << ciudad1 << " " << ciudad2 << " :" << distancia << endl;
}

int main(){

    string ciudad1, ciudad2;
    double distanciaMilla, distanciaKm = 0;

    cin >> ciudad1 >> ciudad2 >> distanciaMilla;

    while(seguirEjecutandose(ciudad1, ciudad2, distanciaMilla)){
        distanciaKm = millasKilometro(distanciaMilla);
        printCiudades(ciudad1, ciudad2, distanciaKm);
        siguientesCiudades(ciudad1,ciudad2,distanciaMilla);
    }

    system("pause");
    return 0;
}