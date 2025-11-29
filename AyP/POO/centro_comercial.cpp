/*Un centro comercial desea administrar toda la información de sus locales.
Cada local tiene: nombre, RIF, horario, dueño, encargado, tamanio (m2) y
una lista de empleados. Los locales que pertenecen al centro comercial se
clasifican en:
•Tiendas de ropas, pudiendo ser estas tiendas para mujeres, hombres
o mixtas.
•Locales de comida, estos pueden ser restaurantes o de comida rápida.
•Librerías.
•Una Farmacia. 
Determinar:
•La cantidad de librerías del centro comercial.
•La cantidad de empleados, por sexo, de la farmacia.
•La cantidad de metros cuadrados que ocupan los locales del centro
comercial.
5*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib> // Para usar srand y rand
using namespace std;

class Empleado {
private:
    char sexo; // M - Masculino | F - Femenino.
public:
    Empleado() {
        this->sexo = (rand() % 2 == 0) ? 'M' : 'F';
    }
    char getSexo() {
        return sexo;
    }
};

class Local {
protected:
    string nombre;
    string rif;
    string horario;
    string dueño;
    string encargado;
    int tamanio;
    Empleado* empleados;
    int numEmpleados;

public:
    Local(string nombre_, string rif_, string horario_, string dueño_, string encargado_, int tamanio_, int numEmpleados_) {
        nombre = nombre_;
        rif = rif_;
        horario = horario_;
        dueño = dueño_;
        encargado = encargado_;
        tamanio = tamanio_;
        numEmpleados = numEmpleados_;
        empleados = new Empleado[numEmpleados];
        for (int i = 0; i < numEmpleados; i++) {
            empleados[i] = Empleado();
        }
    }

    virtual ~Local() {
        delete[] empleados; // Liberar memoria dinámica
    }

    virtual int calcularTamanio() {
        return tamanio;
    }

    string getNombre() {
        return nombre;
    }

    int getNumEmpleados() {
        return numEmpleados;
    }

    Empleado* getEmpleados() {
        return empleados;
    }

    virtual void mostrarInformacion() {
        cout << "Local: " << nombre << endl;
        cout << "Tamaño: " << tamanio << " m2" << endl;
    }
};

class TiendaDeRopas : public Local {
public:
    TiendaDeRopas(string nombre_, string rif_, string horario_, string dueño_, string encargado_, int tamanio_, int numEmpleados_)
        : Local(nombre_, rif_, horario_, dueño_, encargado_, tamanio_, numEmpleados_) {}
};

class LocalDeComida : public Local {
public:
    LocalDeComida(string nombre_, string rif_, string horario_, string dueño_, string encargado_, int tamanio_, int numEmpleados_)
        : Local(nombre_, rif_, horario_, dueño_, encargado_, tamanio_, numEmpleados_) {}
};

class Libreria : public Local {
public:
    Libreria(string nombre_, string rif_, string horario_, string dueño_, string encargado_, int tamanio_, int numEmpleados_)
        : Local(nombre_, rif_, horario_, dueño_, encargado_, tamanio_, numEmpleados_) {}

    void mostrarInformacion() override {
        Local::mostrarInformacion();
        cout << "Tipo: Librería" << endl;
    }
};

class Farmacia : public Local {
public:
    Farmacia(string nombre_, string rif_, string horario_, string dueño_, string encargado_, int tamanio_, int numEmpleados_)
        : Local(nombre_, rif_, horario_, dueño_, encargado_, tamanio_, numEmpleados_) {}

    void veriSexo() {
        int mujeres = 0, hombres = 0;
        for (int i = 0; i < numEmpleados; i++) {
            if (empleados[i].getSexo() == 'M') {
                hombres++;
            } else {
                mujeres++;
            }
        }
        cout << "Empleados hombres en " << nombre << ": " << hombres << endl;
        cout << "Empleados mujeres en " << nombre << ": " << mujeres << endl;
    }

    void mostrarInformacion() override {
        Local::mostrarInformacion();
        cout << "Tipo: Farmacia" << endl;
    }
};

class CentroComercial {
private:
    Local* locales[100]; // Arreglo de locales (máximo 100)
    int numLocales;

public:
    CentroComercial() : numLocales(0) {}

    void agregarLocal(Local* local) {
        if (numLocales < 100) {
            locales[numLocales++] = local;
        } else {
            cout << "No se pueden agregar más locales. Límite alcanzado." << endl;
        }
    }

    int cantidadLibrerias() {
        int count = 0;
        for (int i = 0; i < numLocales; i++) {
            if (dynamic_cast<Libreria*>(locales[i])) {
                count++;
            }
        }
        return count;
    }

    void empleadosPorSexoEnFarmacia() {
        for (int i = 0; i < numLocales; i++) {
            Farmacia* farmacia = dynamic_cast<Farmacia*>(locales[i]);
            if (farmacia) {
                farmacia->veriSexo();
            }
        }
    }

    int metrosCuadradosTotales() {
        int total = 0;
        for (int i = 0; i < numLocales; i++) {
            total += locales[i]->calcularTamanio();
        }
        return total;
    }

    void mostrarInformacionLocales() {
        for (int i = 0; i < numLocales; i++) {
            locales[i]->mostrarInformacion();
            cout << "-----------------------------" << endl;
        }
    }

    ~CentroComercial() {
        for (int i = 0; i < numLocales; i++) {
            delete locales[i];
        }
    }
};

int main() {
    srand((unsigned int)time(NULL)); // Inicializar la semilla del generador de números aleatorios

    // Crear un centro comercial
    CentroComercial centroComercial;

    // Agregar locales al centro comercial
    centroComercial.agregarLocal(new TiendaDeRopas("Tienda de Ropa", "RIF1", "9:00-18:00", "Dueño1", "Encargado1", 50, 5));
    centroComercial.agregarLocal(new LocalDeComida("Restaurante", "RIF2", "10:00-22:00", "Dueño2", "Encargado2", 100, 8));
    centroComercial.agregarLocal(new Libreria("Librería Central", "RIF3", "8:00-20:00", "Dueño3", "Encargado3", 80, 3));
    centroComercial.agregarLocal(new Farmacia("Farmacia Salud", "RIF4", "8:00-22:00", "Dueño4", "Encargado4", 60, 6));

    // Mostrar información de los locales
    centroComercial.mostrarInformacionLocales();

    // Determinar la cantidad de librerías
    cout << "Cantidad de librerías: " << centroComercial.cantidadLibrerias() << endl;

    // Determinar la cantidad de empleados por sexo en la farmacia
    centroComercial.empleadosPorSexoEnFarmacia();

    // Calcular la cantidad total de metros cuadrados
    cout << "Total de metros cuadrados: " << centroComercial.metrosCuadradosTotales() << endl;

    system ("pause");
    return 0;
}