///////////////////////////////////////////
//      Hecho con IA (no sé ángulos)
///////////////////////////////////////////
#include <iostream>
#include <cmath> // para fabs
using namespace std;

double angle(int hours, int minutes){
    // Ángulo de la aguja de horas
    double hourAngle = 30 * (hours % 12) + 0.5 * minutes;
    // Ángulo de la aguja de minutos
    double minuteAngle = 6 * minutes;
    // Diferencia absoluta
    double diff = fabs(hourAngle - minuteAngle);
    // Ángulo mínimo
    return min(diff, 360 - diff);
}

int main (){ 
    int hours, minutes;
    cout << "Enter the hours and minutes [hours minutes]: ";
    cin >> hours >> minutes;

    cout << "The angle is: " << angle(hours, minutes) << " degrees" << endl;

    return 0;
}