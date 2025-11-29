#include <iostream>
#include <string>
#include <limits>
using namespace std;

string nombreMes(int numeroMes){

    switch(numeroMes){
        case 1: return "Enero";
        case 2: return "Febrero";
        case 3: return "Marzo";
        case 4: return "Abril";
        case 5: return "Mayo";
        case 6: return "Junio";
        case 7: return "Julio";
        case 8: return "Agosto";
        case 9: return "Septiembre";
        case 10: return "Octubre";
        case 11: return "Noviembre";
        case 12: return "Diciembre";
        default: return "Mes no encontrado";
    }
} 

int main(){

    int nMes;
    while (true) { 
        cout << "Ingrese un número de mes (1-12): ";
        cin >> nMes;

        // Verifica si la entrada es válida
        if (cin.fail() || nMes < 1 || nMes > 12) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Entrada inválida. Por favor, intente de nuevo." << endl;
        } else {
            break; // Sal del bucle si la entrada es válida
        }
    }

    string mesNombre = nombreMes(nMes);

    cout << mesNombre << "." << endl;
    
    system("pause");
    return 0;
}