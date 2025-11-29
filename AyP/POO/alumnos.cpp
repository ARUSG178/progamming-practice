#include <iostream>
#include <string>
using namespace std;

class Estudiante{
    string nombre;
    string edad;
    string carnet;
    string materia;

    public:

    Estudiante(){
        this->nombre = "";
        this->edad = "";
        this->carnet = "";
        this->materia = "";
    }

    void Insertar(string n, string e, string c, string m){
        this->nombre = n;
        this->edad = e;
        this->carnet = c;
        this->materia = m;
    }

    string Imprimir(){
        return "Nombre: " + this->nombre + " - Edad: " + this->edad + " - Carnet: " + this->carnet + " - Materia cursante: " + this->materia + "\n";
    }
};

int main(){

    Estudiante Primer = Estudiante();
    Primer.Insertar("Juan", "20", "12345", "Matemáticas");
    cout << Primer.Imprimir();

    return 0;
}