#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Función para crear un archivo
void crearArchivo(string nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    archivo.close();
}

// Función para escribir en un archivo
void escribirEnArchivo(string nombreArchivo, string texto) {
    ofstream archivo(nombreArchivo, ios_base::app);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    archivo << texto << endl;
    archivo.close();
}

// Función para leer un archivo
void leerArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

// Función principal
int main() {
    string nombreArchivo;
    cout << "Ingrese el nombre o ubicación del archivo: ";
    cin >> nombreArchivo;
    crearArchivo(nombreArchivo);

    string texto;
    cout << "Ingrese el texto a escribir en el archivo: ";
    cin.ignore();
    getline(cin, texto);
    escribirEnArchivo(nombreArchivo, texto);

    cout << "Contenido del archivo:" << endl;
    leerArchivo(nombreArchivo);

    return 0;
}