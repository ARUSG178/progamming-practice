#include <iostream>
#include <string>
using namespace std;

class Profesor{
    public:
    string nombre;
    Profesor(string& nombre) : nombre(nombre){}
};
class Auxiliar{
    public:
    string nombre;
    Auxiliar(string& nombre) : nombre(nombre){}
};
class EquipoDocente {
    public:
        Profesor responsable;
        Auxiliar auxiliares[4];
        int cantidadAuxiliares;
    
        EquipoDocente(const Profesor& resp, const Auxiliar auxs[], int cantidad)
        : responsable(resp), cantidadAuxiliares(cantidad) {
            if (cantidad < 1 || cantidad > 4) {
                cerr << "Error: Debe tener entre 1 y 4 auxiliares\n";
                exit(1);
            }
            
            for (int i = 0; i < cantidad; ++i) {
                auxiliares[i] = auxs[i];
            }
        }
    };

class Evaluacion {
public:
    string fecha;
    bool aprobado;
    
    Evaluacion(const string& f, bool a) : fecha(f), aprobado(a) {}
    virtual ~Evaluacion() = default;
    virtual string getTipo() const = 0;
};
class Parcial: public Evaluacion{};
class TrabajoEscrito: public Evaluacion{};
class ParcialFinal: public Evaluacion{};
class Alumno{};