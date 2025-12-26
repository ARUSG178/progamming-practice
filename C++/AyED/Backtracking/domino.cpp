// Un juego de dominó se considera “trancado” si las dos piezas que permiten a los jugadores participar en el
// juego son iguales, y ninguno de ellos (en el caso de cuatro jugadores) posee ninguna piedra que tenga ese valor.
// Se desea conocer todas las formas en la cual un juego de dominó esta trancado.
#include <iostream>
using namespace std;

class Ficha{
    int a, b;
public:
    Ficha(int a, int b) : a(a), b(b) {}
    int getA() { return a; }
    int getB() { return b; }
};

class Jugador{
    Ficha ficha[7];
    int cantidad;
    public:
    Jugador() : cantidad(0) {}
    void agregarFicha(Ficha f) {
        if(cantidad < 7) {
            ficha[cantidad++] = f;
        }
    }

    bool tieneValor(int v) const {
    for (int i = 0; i < cantidad; i++)
        if (fichas[i].tieneValor(v)) return true;
    return false;
    }

};

class Domino{
    public:
    Jugador jugadores[4];
    int trancado[2];

    Domino() {
        trancado[0] = trancado[1] = 0;
    }
    
    bool estaTrancado() const {
        if (trancado[0] != trancado[1]) return false;
        int valor = trancado[0];
        for (int j = 0; j < 4; j++)
            if (jugadores[j].tieneValor(valor)) return false;
        return true;
    }

    void buscarTrancas() {
        for (int valor = 0; valor <= 6; valor++) {
            trancado[0] = trancado[1] = valor;
            if (estaTrancado()) {
                cout << "Tranca posible con valor: " << valor << endl;
            }
        }
    }

    }
};

int main(){


    domino();
    return 0;
}