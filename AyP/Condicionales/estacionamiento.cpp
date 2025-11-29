#include <iostream>
using namespace std;

void calcularMonto(int entrada, int salida) {
    // Verificar si las horas de entrada y salida son válidas
    if (entrada < 0 || entrada > 23 || salida < 0 || salida > 23) {
        cout << "Hora de entrada o salida no válida." << endl; 
        return; // Salir de la función si las horas son inválidas
    }
    
    // Calcular las horas totales
    int horasTotales = abs(entrada - salida);
    int montoPagar = 100 + ((horasTotales - 1) * 80);
    
    // Imprimir el monto a pagar
    cout << "El monto a pagar es: " << montoPagar << endl;
}

int main() {
    int horaEntrada, horaSalida;
    cout << "Ingrese la hora de entrada y salida (ejemplo: 9 10): ";
    cin >> horaEntrada >> horaSalida; // Leer las horas de entrada y salida

    // Llamar a la función para calcular el monto
    calcularMonto(horaEntrada, horaSalida); 

    return 0;
}