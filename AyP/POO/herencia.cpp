#include <iostream>
#include <string>
using namespace std;

class Alumno{
    private:
        string nombre;
        string carnet;
    public:
    
    Alumno(){
        this->nombre = " ";
        this->carnet = " ";
    }

    void Insertar(string n, string c){
        this->nombre = n;
        this->carnet = c;
    }

    string Print(){
        return this->nombre + " " + this->carnet;
    }
};

class Lista: public Alumno{
    public:
        void listar(){
            cout << this->Print() << endl;
        }
};

int main(){
    Alumno yo = Alumno();
    yo.Insertar("Juan", "1234");
    Lista seccionA;
    seccionA.Insertar("Juan", "1234");
    seccionA.listar();
    return 0;
}