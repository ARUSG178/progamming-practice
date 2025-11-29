#include <iostream>
#include <string>
using namespace std;

class Saludo{
    string nombre;
    string dialogo;
    public:

    Saludo(string n){
        this->nombre = n;
        this->dialogo = "Hola, " + n + " eres bien pana";
    }

    Saludo(string n, string d){
        this->nombre = n;
        this->dialogo = d;
    }

    string getDialogo() const {
        return this->dialogo;
    }
};

int main(){
    Saludo saludo1("Juan");

    cout << saludo1.getDialogo() << endl;

    Saludo saludo2("Juan", "Hola! Espero tengas lindo dia");

    cout << saludo2.getDialogo() << endl;

    return 0;
}