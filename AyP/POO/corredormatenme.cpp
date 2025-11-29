#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Corredor{
    private:
    int energia;
    public:
    Corredor(int energia){
        this->energia = energia;
    }
    void verificarEnergia() {
        if(energia <= 0){
            this->energia = 0;
            cout << "La energia del corredor se establece a la mínima '0'.";
        }else if(energia >= 100){
            this->energia = 100;
            cout << "La energia del corredor se establece a la máxima '100'.";
        }
    }
    void recargarEnergia(Corredor& a) {
        int recarga;
        cout << "¿Cuánta energia deseas recargar? ";
        cin >> recarga;
        a.energia += recarga;
    }
    void correr(Corredor& a) {
        energiaAgotada(a);
        if (a.energia > 10) {
            a.energia -= 10;
        }
    }
    void energiaAgotada(Corredor& a) {
        if (a.energia <= 10) {
            a.energia = 0;
            cout << "Se llegó al mínimo de energía." << endl;
            cout << "La energía del corredor es: " << a.energia << endl;
        }
    }
    void entrenar(Corredor& a) { 
        a.energia += 15;
        if(a.energia > 100) a.energia = 100;
    }
    int getEnergia(){
        return energia;
    }
};

int main() {
    Corredor corredor(50);

    cout << "Energía inicial del corredor: " << corredor.getEnergia() << endl;

    corredor.correr(corredor);
    cout << "Energía después de correr: " << corredor.getEnergia() << endl;

    corredor.entrenar(corredor);
    cout << "Energía después de entrenar: " << corredor.getEnergia() << endl;

    corredor.recargarEnergia(corredor);
    cout << "Energía después de recargar: " << corredor.getEnergia() << endl;

    corredor.verificarEnergia();

    return 0;
}