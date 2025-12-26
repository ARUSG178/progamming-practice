#include <iostream>
using namespace std;

struct Dano {
    int tipo;
    int cantidad;
};

class ControlDeDano {
private:
    struct Nodo {
        Dano d;
        Nodo* next;
        Nodo(const Dano& dano, Nodo* sig = nullptr) : d(dano), next(sig) {}
    };

    Nodo* cabeza;        
    int vidaInicial;
    int totalRecibido;

public:
    ControlDeDano(int vidaInicial) : vidaInicial(vidaInicial), totalRecibido(0), cabeza(nullptr) {}

    int recibirDano(Dano dano) {
        Nodo* nuevo = new Nodo(dano, cabeza);
        cabeza = nuevo;
        totalRecibido += dano.cantidad;
        return vidaInicial - totalRecibido;
    }

    int curarUltimosNDanos(int n) {
        while (n > 0 && cabeza != nullptr) {
            Nodo* temp = cabeza;
            totalRecibido -= cabeza->d.cantidad;
            cabeza = cabeza->next;
            delete temp;
            n--;
        }
        return vidaInicial - totalRecibido;
    }

    int curarDanoPorTipo(int tipo) {
        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;

        while (actual != nullptr) {
            if (actual->d.tipo == tipo) {
                totalRecibido -= actual->d.cantidad;
                Nodo* eliminado = actual;

                if (anterior == nullptr) {  // estaba en cabeza
                    cabeza = actual->next;
                    actual = cabeza;
                } else {
                    anterior->next = actual->next;
                    actual = actual->next;
                }

                delete eliminado;
            } else {
                anterior = actual;
                actual = actual->next;
            }
        }

        return vidaInicial - totalRecibido;
    }

    ~ControlDeDano() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->next;
            delete temp;
        }
    }
};