#include <iostream>
#include <cmath>
using namespace std;

int horarioGrados(int horas, int minutos){ 
    return horas = (horas % 12)*30 + minutos * 0.5;
}

int minuteroGrados(int minutos){ 
    return minutos * 6;
}

int diferenciaHoraMinuto(int horas, int minutos){
    int diferencia = abs(horas - minutos);
    int angulo = min (diferencia, 360 - diferencia);
    return angulo;
}

int main(){

    int horario, minutero;
    int horaGrados = 0, minutoGrados = 0;

    cout << "Hora (formato 24) y minutos. En ese orden: ";
    cin >> horario >> minutero;

    horaGrados = horarioGrados(horario, minutero);
    minutoGrados = minuteroGrados(minutero);

    int angulo = diferenciaHoraMinuto(horaGrados, minutoGrados);

    cout << "El angulo entre horario y minutero es de: " << angulo << " grados." << endl;

    system("pause");
    return 0;
}