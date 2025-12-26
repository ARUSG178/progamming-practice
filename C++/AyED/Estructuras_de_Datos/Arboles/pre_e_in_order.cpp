#include <iostream>
using namespace std;

template <typename T>
class ArbolGeneral{
    private:
        struct Nodo{
            T data;
            Nodo* child;
            Nodo* nextSibling;

            Nodo (const T &d) : data(d), child(nullptr), nextSibling(nullptr) {}
        };

        Nodo* root;

    // preorden: raíz → hijos
    void preRec(Nodo* nodo) const {
        if (!nodo) return;

        // 1. Visitar primero el nodo actual
        cout << nodo->valor << " ";

        // 2. Luego recorrer todos sus hijos
        Nodo* hijo = nodo->child;
        while (hijo) {
            preRec(hijo);
            hijo = hijo->nextSibling;
        }

    }

    // inorden: hijo izquierdo -> raíz -> hijo derecho
    void inRec(Nodo* nodo) const {
        if (!nodo) return;

        Nodo* hijo = nodo->child;
    
        if (hijo) { 
            // 1. Recorrer primer hijo
            inRec(hijo);

            // 2. Visitar la raíz
            cout << nodo->valor << " ";

            // 3. Recorrer los hermanos del primer hijo
            hijo = hijo->nextSibling;
            while (hijo) {
                inRec(hijo);
                hijo = hijo->nextSibling;
            }
        } else {
            // Si no tiene hijos, se imprime directamente
            cout << nodo->valor << " ";
        }

    }

    // postorden: hijos → raíz
    void postRec(Nodo* nodo) const {
        if (!nodo) return;

        // 1. Recorrer todos los hijos primero
        Nodo* hijo = nodo->child;
        while (hijo) {
            postRec(hijo);
            hijo = hijo->nextSibling;
        }

        // 2. Luego visitar el nodo actual
        cout << nodo->valor << " ";
    }

    public:

        // recorrido preorden
    void preOrden() const {
        cout << "Preorden: ";
        preRec(raiz);
        cout << "\n";
    }

    void inOrden() const {
        cout << "Inorden: ";
        inRec(raiz);
        cout << "\n";
    }

    // recorrido postorden
    void postOrden() const {
        cout << "Postorden: ";
        postRec(raiz);
        cout << "\n";
    }
};