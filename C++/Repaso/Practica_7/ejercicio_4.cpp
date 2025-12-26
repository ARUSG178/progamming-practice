#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Persona {
    int cedula;
    string nombreC;
    int edad;
    char sexo;
};

void insertData(ifstream &file, Persona personas[], int n) {
    for (int i = 0; i < n; i++) {
        file >> personas[i].cedula;
        file.ignore(); // limpiar salto de línea antes de getline
        getline(file, personas[i].nombreC);
        file >> personas[i].cedula;
        file >> personas[i].edad;
    }
}

void newArchive(ofstream &file, Persona personas[], int n) {
    int mayores = 0;
    for(int i = 0; i < n; i++) if(personas[i].edad > 18) mayores++;
    
    file << mayores << "\n";

    for(int i = 0; i < n; i++) {
        if(personas[i].edad > 18) {
            file << personas[i].cedula << "\n";
            file << personas[i].sexo << "\n";
        }
    }
}

int main() {
    ifstream file("archive/personas.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo personas.txt" << endl;
        return 1;
    }

    int n = 0;
    file >> n; // número de personas en el archivo

    Persona personas[100]; // máximo 100
    insertData(file, personas, n);

    ofstream nFile("archive/personasMayores.txt");
    if (!nFile.is_open()) {
        cerr << "Error al crear el archivo personasMayores.txt" << endl;
        return 1;
    }

    newArchive(nFile, personas, n);

    cout << "Archivo personasMayores.txt generado correctamente." << endl;
    return 0;
}