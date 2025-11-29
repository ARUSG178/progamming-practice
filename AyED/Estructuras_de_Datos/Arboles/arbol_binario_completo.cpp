#include <iostream>
using namespace std;

// ------------------------------
// Nodo de un árbol binario
// ------------------------------
struct Nodo {
    int info;
    Nodo* izq;
    Nodo* der;

    Nodo(int v) : info(v), izq(nullptr), der(nullptr) {}
};

// ------------------------------
// Árbol binario con Altura, EsPerfecto y EsCompleto
// (sin usar <algorithm> ni otras librerías)
// ------------------------------
class Arbin {
private:
    Nodo* root;

    // Máximo de dos enteros sin <algorithm>
    int maximo(int a, int b) {
        return (a > b) ? a : b;
    }

    // 1) Altura de n (-1 si es nullptr)
    int alturaRec(Nodo* n) {
        if (!n) return -1;
        int hL = alturaRec(n->izq);
        int hR = alturaRec(n->der);
        return 1 + maximo(hL, hR);
    }

    // 2) Verifica si el subárbol en n es perfecto
    bool esPerfectoRec(Nodo* n) {
        if (!n) return true;
        int hL = alturaRec(n->izq);
        int hR = alturaRec(n->der);
        if (hL != hR) return false;
        return esPerfectoRec(n->izq) && esPerfectoRec(n->der);
    }

    // 3) Verifica si el subárbol en n es completo
    bool esCompletoRec(Nodo* n) {
        if (!n) return true;

        int hL = alturaRec(n->izq);
        int hR = alturaRec(n->der);

        if (hL == hR) {
            // Izq perfecto, Der completo
            return esPerfectoRec(n->izq) && esCompletoRec(n->der);
        }
        else if (hL == hR + 1) {
            // Izq completo, Der perfecto
            return esCompletoRec(n->izq) && esPerfectoRec(n->der);
        }
        else {
            return false;
        }
    }

public:
    Arbin() : root(nullptr) {}

    // Permite construir el árbol manualmente
    void setRoot(Nodo* r) { root = r; }

    // Altura pública
    int Altura() {
        return alturaRec(root);
    }

    // ¿Es perfecto?
    bool EsPerfecto() {
        return esPerfectoRec(root);
    }

    // ¿Es completo?
    bool EsCompleto() {
        return esCompletoRec(root);
    }
};

// ------------------------------
// Ejemplo de uso
// ------------------------------
int main() {
    // Construcción manual del árbol:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    Nodo* n1 = new Nodo(1);
    Nodo* n2 = new Nodo(2);
    Nodo* n3 = new Nodo(3);
    Nodo* n4 = new Nodo(4);
    Nodo* n5 = new Nodo(5);

    n1->izq = n2;
    n1->der = n3;
    n2->izq = n4;
    n2->der = n5;

    Arbin A;
    A.setRoot(n1);

    cout << "Altura: "       << A.Altura()       << "\n"; // 2
    cout << "EsPerfecto? "   << A.EsPerfecto()   << "\n"; // 0
    cout << "EsCompleto? "   << A.EsCompleto()   << "\n"; // 1

    // Liberar memoria
    delete n5;
    delete n4;
    delete n3;
    delete n2;
    delete n1;
    return 0;
}