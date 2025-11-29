#include <iostream>
using namespace std;

class Monedero{
    private:
    int cantidad;
    public:
    Monedero(int _cantidad) {
        cantidad = _cantidad;
    }
    void agregarDinero(Monedero& a){
        int deposito;
        cout << "Ingrese la cantidad de dinero que quiere agregar: ";
        cin >> deposito;
        this->cantidad += deposito;
    }
    void retirarDinero(Monedero& a){
        int retiro;
        cout << "Ingrese la cantidad de dinero que quiere retirar: ";
        cin >> retiro;
        if (retiro <= this->cantidad) {
            this->cantidad -= retiro;
            cout << "Se ha retirado $" << retiro << " de su cuenta." << endl;
        } else {
            cout << "No tiene suficiente dinero en su cuenta para retirar esa cantidad." << endl;
        }
    }
    void getDinero(){
        cout << "Su cuenta tiene $" << this->cantidad << "." << endl;
    }
};

int main(){
    Monedero m1(1000);
    m1.getDinero();
    m1.agregarDinero(m1);
    m1.getDinero();

    return 0;
}