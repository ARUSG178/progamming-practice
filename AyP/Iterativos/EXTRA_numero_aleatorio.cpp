#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int main() {
    srand(time(0)); // Inicializar la semilla para números aleatorios
    int numeroAleatorio, numeroJugable, maxIntentos;
    vector<int> intentos;
    char jugarDeNuevo;

    cout << "=================================================================================================" << endl;
    cout << "                                    ADIVINA EL NUMERO   " << endl;
    cout << "=================================================================================================" << endl;

    do {
        // Elegir nivel de dificultad
        int dificultad;
        cout << "\nDIFICULTAD => [ 1: FACIL (1 - 100) | 2: MEDIO (1 - 1000) | 3: DIFICIL (1 - 10000) ]: ";
        cin >> dificultad;

        // Establecer el rango y el número de intentos según la dificultad
        switch (dificultad) {
            case 1:
                numeroAleatorio = rand() % 100 + 1; // 1-100
                maxIntentos = 10;
                break;
            case 2:
                numeroAleatorio = rand() % 1000 + 1; // 1-1000
                maxIntentos = 12;
                break;
            case 3:
                numeroAleatorio = rand() % 10000 + 1; // 1-10000
                maxIntentos = 15;
                break;
            default:
                cout << "Dificultad no válida. Se establecerá en Medio." << endl;
                numeroAleatorio = rand() % 1000 + 1; // 1-1000
                maxIntentos = 12;
                break;
        }

        intentos.clear(); 
        int intentosRestantes = maxIntentos;

        while (numeroJugable != numeroAleatorio && intentosRestantes > 0) {
            cout << "\nTienes " << intentosRestantes << " intentos restantes." << endl;
            cout << "-> ";
            cin >> numeroJugable;

            // Validar la entrada
            if (cin.fail() || numeroJugable < 1 || numeroJugable > (dificultad == 1 ? 100 : (dificultad == 2 ? 1000 : 10000))) {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(10000, '\n'); // Ignorar hasta 10,000 caracteres o hasta un salto de línea
                cout << "Error! Debes introducir un numero valido." << endl;
            } else {
                intentos.push_back(numeroJugable); // Almacenar el intento
                intentosRestantes--;
            // Si el numero es menor o mayor
                if (numeroJugable < numeroAleatorio) {
                    cout << "(ES MENOR)" << endl;
                } else if (numeroJugable > numeroAleatorio) {
                    cout << "(ES MAYOR)" << endl;
                }
            }
        }

        // Resultado del juego
        if (numeroJugable == numeroAleatorio) {
            cout << "\nFelicidades! Has adivinado el numero: " << numeroJugable << "." << endl;
        } else {
            cout << "\nIntentos agotados, el numero era: " << numeroAleatorio << "." << endl;
        }

        // Mostrar historial de intentos
        cout << "INTENTOS: ";
        for (int intento : intentos) {
            cout << intento << " ";
        }
        cout << endl;

        // Preguntar si el jugador quiere jugar de nuevo
        cout << "\nJugar de nuevo? (s/n): ";
        cin >> jugarDeNuevo;

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    cout << "========================================" << endl;
    cout << "           GRACIAS POR JUGAR        " << endl;
    cout << "========================================" << endl;

    return 0;
}