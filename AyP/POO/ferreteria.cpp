#include <iostream>
#include <string>
using namespace std;

class Herramienta {
protected:
    string nombre;
    string descripcion;
    int precio;
    string codigo;
    string nombreF;

public:
    Herramienta() {} // Constructor por defecto
    Herramienta(string n, string d, int p, string c, string nF) {
        nombre = n;
        descripcion = d;
        precio = p;
        codigo = c;
        nombreF = nF;
    }

    virtual void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Descripción: " << descripcion << endl;
        cout << "Precio: " << precio << endl;
        cout << "Código: " << codigo << endl;
        cout << "Nombre del fabricante: " << nombreF << endl;
    }
};

class Manuales : virtual public Herramienta {
private:
    string material;
    float longitud;
    float peso;

public:
    Manuales(string n, string d, int p, string c, string nF, string mat, float lon, float pe) : Herramienta(n, d, p, c, nF) {
        material = mat;
        longitud = lon;
        peso = pe;
    }

    void mostrarCaracteristicas() {
        cout << "Material: " << material << endl;
        cout << "Longitud: " << longitud << " cm" << endl;
        cout << "Peso: " << peso << " kg" << endl;
    }
};

class Electricas : virtual public Herramienta {
private:
    float voltaje;
    float potencia;
    string bateriaTipo;

public:
    Electricas(string n, string d, int p, string c, string nF, float vol, float pot, string batTip) : Herramienta(n, d, p, c, nF) {
        voltaje = vol;
        potencia = pot;
        bateriaTipo = batTip;
    }

    void mostrarCaracteristicas() {
        cout << "Voltaje: " << voltaje << " V" << endl;
        cout << "Potencia: " << potencia << " W" << endl;
        cout << "Tipo de batería: " << bateriaTipo << endl;
    }
};

class Motoras : virtual public Herramienta {
private:
    float cilindrada;
    string tipoCilindro;

public:
    Motoras(string n, string d, int p, string c, string nF, float cilin, string tipCilin) : Herramienta(n, d, p, c, nF) {
        cilindrada = cilin;
        tipoCilindro = tipCilin;
    }

    void mostrarCaracteristicas() {
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
        cout << "Tipo de cilindro: " << tipoCilindro << endl;
    }
};

class Especialidad : public Manuales, public Electricas, public Motoras {
private:
    string especialidad;

public:
    Especialidad(string n, string d, int p, string c, string nF, string mat, float lon, float pe, float vol, float pot, string batTip, float cilin, string tipCilin, string speci)
        : Herramienta(n, d, p, c, nF), Manuales(n, d, p, c, nF, mat, lon, pe), Electricas(n, d, p, c, nF, vol, pot, batTip), Motoras(n, d, p, c, nF, cilin, tipCilin) {
        especialidad = speci;
    }

    void mostrarInformacion() {
        Herramienta::mostrarInformacion();
        cout << "Especialidad: " << especialidad << endl;
    }

    void mostrarCaracteristicas() {
        cout << "Especialidad: " << especialidad << endl;
        Manuales::mostrarCaracteristicas();
        Electricas::mostrarCaracteristicas();
        Motoras::mostrarCaracteristicas();
    }
};

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");

    Especialidad herramienta("Herramienta especial", "Descripción de la herramienta", 100, "Código de la herramienta", "Nombre del fabricante",
                             "Material de la herramienta", 10.0, 5.0, 12.0, 50.0, "Tipo de batería", 250.0, "Tipo de cilindro", "Especialidad de la herramienta");

    herramienta.mostrarInformacion();
    herramienta.mostrarCaracteristicas();

    return 0;
}