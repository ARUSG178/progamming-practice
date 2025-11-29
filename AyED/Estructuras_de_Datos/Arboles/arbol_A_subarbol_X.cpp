#include <iostream>
using namespace std;

// ------------------------------
// Definición de Nodo del árbol binario
// ------------------------------
class Nodo {
public:
    int info;
    Nodo* izq;   // hijo izquierdo
    Nodo* der;   // hijo derecho

    // Si quisieras hacer EsPadre en O(1), podrías incluir:
    // Nodo* padre;

    Nodo(int d) : info(d), izq(nullptr), der(nullptr) {}
};

// ------------------------------
// Clase principal del árbol binario
// ------------------------------
class Arbin {
private:
    Nodo* root;

public:
    Arbin() : root(nullptr) {}



    // ------------------------------
    // INCISO 13.a
    // bool EsHoja(Arbin A, Arbin X);
    // Verifica si el nodo X no tiene hijos
    // Implementación va aquí
    // ------------------------------

    bool esHoja(Arbin A, Arbin X) const {
        Nodo* veri = X.root;
        return (root->izq && root->der);
    }

    // ------------------------------
    // INCISO 13.b
    // bool EsPadre(Arbin A, Arbin x, Arbin y);
    // Verifica si 'x' es padre directo de 'y'
    // Implementación va aquí
    // ------------------------------

    bool EsPadre(Arbin A, Arbin x, Arbin y) const {
        return (x.root->izq == y.root || x.root->der == y.root);
    }
};

// ------------------------------
// Programa principal
// ------------------------------
int main() {
    // Aquí puedes probar la clase Arbin
    // Crear nodos, construir árbol y llamar a EsHoja / EsPadre

    return 0;
}