#include <iostream>
#include <string>
using namespace std;

class Persona{
    protected: 
    string nombre;
    int cedula;
    int edad;
    public:
    Persona(string n, int c, int e){
        nombre = n;
        cedula = c;
        edad = e;
    }
    string getNombre(){
        return nombre;
    }
    int getEdad(){
        return edad;
    }
    void printPersona(){
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }

};

class Empleado : public Persona {
    private:

    string cargo;
    int salario;

    public:

    Empleado(string n, int c, int e, string ca, int s) : Persona(n,c,e){
        cargo = ca;
        salario = s;
    }

    bool bienPagado(){
        if(salario > 300){
            return true;
        }
    }

    void printEmpleado(){
        if(bienPagado()){
            printPersona();
            cout << "Cargo: " << cargo << endl;
            cout << "Salario: " << salario << endl;
            cout << "Está bien pagado" << endl;
        }
        else{
            printPersona();
            cout << "Cargo: " << cargo << endl;
            cout << "Salario: " << salario << endl;
            cout << "No está bien pagado" << endl;
        }
    }
};

class Estudiante : public Persona {
    protected:
    string institucion;
    string materias;
    bool inscrito;
    public:
    Estudiante(string n, int c, int e, string ins, string mat, bool inscr) : Persona (n,c,e){
        institucion = ins;
        materias = mat;
        inscrito = inscr;
    }
    
    bool jubilao(string mat){
        return mat.empty();
    }

    void printEstudiante(){
        printPersona();
        cout << "Institución: " << institucion << endl;
        cout << "Materias: " << materias << endl;
        cout << ((jubilao(this->materias)) ? "Jubilao" : "No jubilao") << endl;
    }
};

class Universitario : public Estudiante {
    private:
    string carrera;
    int semestre;
    int pupitre;
    public:
    Universitario(string n, int c, int e, string ins, string mat, bool inscr, string carr, int semes, int pupi) : Estudiante(n, c, e, ins, mat, inscr){
        carrera = carr;
        semestre = semes;
        pupitre = pupi;
    }

    bool hayPupitre(int pupi){
        if(pupi > 0){
            return true;
        }
        return false;  
    }

    void printUni(){
        printEstudiante();
        cout << "Carrera: " << carrera << endl;
        cout << "Semestre: " << semestre << endl;
        cout << "Pupitre: " << pupitre << endl;
        cout << ((hayPupitre(pupitre)) ? "Hay pupitre" : "No hay pupitre") << endl;
    }
    
};

int main(){
    Universitario u("Andy", 6584738, 20, "UCV", "Programación, singar, uwu", 1, "Computacion", 5, 8);
    u.printUni();
}