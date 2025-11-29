#include <iostream>
using namespace std;

int hSegundos(int horas){
    int segundos = horas * 60 * 60;
    return segundos;
}

int mSegundos(int minutos){
    int segundos = minutos * 60;
    return segundos;
}

void printSegundos(int segundosTotales){
    cout << "La cantidad de segundos transcurridas es de: "<< segundosTotales << endl;
}

int main(){

    int horas, minutos, segundos, segundosTotales = 0;
    char meridiano;

    cout << "Horas (formato 12), minutos, segundos y meridiano (A/P)";
    cin >> horas >> minutos >> segundos >> meridiano;

    int horasSegundos = hSegundos(horas);
    int minutosSegundos = mSegundos(minutos);

    if (meridiano == 'A' || meridiano == 'a') segundosTotales = horasSegundos + minutosSegundos + segundos;
    else if (meridiano == 'P' || meridiano == 'p') segundosTotales = horasSegundos + minutosSegundos + segundos + 43200;
    else cout << "Error: Meridiano invalido"; return 1;

    printSegundos(segundosTotales);

    system("pause");
    return 0;
}