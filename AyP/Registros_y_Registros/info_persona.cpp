#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Persona {
    int cedula;
    string nombre;
    int edad;
    char sexo;
};

int main() {
    // Abrir archivo personas.txt para lectura
    ifstream archivo("personas.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo personas.txt" << endl;
        return 1;
    }

    // Leer número de personas
    int N;
    archivo >> N;

    // Crear arreglo de personas
    Persona personas[N];

    // Leer información de personas
    for (int i = 0; i < N; i++) {
        if (archivo >> personas[i].cedula) {
            archivo.ignore(); // Ignorar salto de línea
            getline(archivo, personas[i].nombre);
            archivo >> personas[i].edad;
            archivo >> personas[i].sexo;
            archivo.ignore(); // Ignorar salto de línea
        } else {
            cout << "Error al leer el archivo" << endl;
            return 1;
        }
    }

    // Abrir archivo mayores_de_edad.txt para escritura
    ofstream archivo_salida("mayores_de_edad.txt");
    if (!archivo_salida.is_open()) {
        cout << "Error al abrir el archivo mayores_de_edad.txt" << endl;
        return 1;
    }

    // Escribir cédulas y edades de personas mayores de 18 años
    for (int i = 0; i < N; i++) {
        if (personas[i].edad > 18) {
            archivo_salida << personas[i].cedula << " " << personas[i].edad << endl;
        }
    }

    // Cerrar archivos
    archivo.close();
    archivo_salida.close();

    return 0;
}