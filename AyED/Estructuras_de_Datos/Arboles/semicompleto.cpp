#include <iostream>
using namespace std;

// ArbolGeneral: árbol “n-ario” con esquema hijo-izquierdo/hermano-derecho
class ArbolGeneral {
private:
    // Nodo interno
    struct Nodo {
        int valor;            
        Nodo* child;          
        Nodo* nextSibling;    
        Nodo(int v) : valor(v), child(nullptr), nextSibling(nullptr) {}
    };

    Nodo* raiz;            

    //===== Primitivas internas =====

    // busca un nodo con valor v en todo el subárbol
    Nodo* findNodo(Nodo* nodo, int v) const {
        if (!nodo) return nullptr;
        if (nodo->valor == v) return nodo;
        if (Nodo* r = findNodo(nodo->child, v)) 
            return r;
        return findNodo(nodo->nextSibling, v);
    }

    // libera recursivamente todo el subárbol
    void deleteSubtree(Nodo* nodo) {
        if (!nodo) return;
        for (Nodo* c = nodo->child; c; c = c->nextSibling)
            deleteSubtree(c);
        delete nodo;
    }

    //===== Método adicional interno =====

    // recorre en DFS hijo-hermano y valida que todos los nodos internos
    // tengan el mismo grado. expectedDeg arranca en -1 (no definido aún).
    bool isSemiRec (Nodo* nodo, int& expectedDeg) const {
        if (!nodo) return true;

        int degree = 0;
        Nodo* parChild = nodo->child;
        while(parChild) {
            degree++;
            parChild = parChild->nextSibling;
        }

        if (degree > 0) {
            if (expectedDeg < 0) expectedDeg = degree;
            else if (degree != expectedDeg) return false;
        }

        if (!isSemiRec(nodo->child, expectedDeg)) return false;

        return isSemiRec(nodo->nextSibling, expectedDeg);
    }
    

public:
    ArbolGeneral() : raiz(nullptr) {}
    ~ArbolGeneral() { deleteSubtree(raiz); }

    //===== Primitivas públicas =====

    // crea la raíz (descarta árbol previo)
    void crearRaiz(int v) {
        deleteSubtree(raiz);
        raiz = new Nodo(v);
    }

    // inserta 'valor' como primer hijo de nodo con dato == padre
    void insertar(int padre, int valor) {
        if (!raiz) return;
        Nodo* p = findNodo(raiz, padre);
        if (!p) return;
        Nodo* n = new Nodo(valor);
        n->nextSibling = p->child;
        p->child = n;
    }

    // verifica existencia de un valor
    bool existe(int v) const {
        return findNodo(raiz, v) != nullptr;
    }

    //===== Método adicional público =====

    // indica si el árbol es semi-completo:
    // todos los nodos internos deben tener el mismo número de hijos
    bool esSemiCompleto() const {
        int expectedDeg = -1;               // grado no definido aún
        return isSemiRec(raiz, expectedDeg);
    }
};

// Ejemplo de uso
int main() {
    ArbolGeneral ag;
    //        10
    //      /  |  \
    //     5   7   8
    //    / \  /\   \
    //   1  2 3 4   6
    ag.crearRaiz(10);
    ag.insertar(10, 5);
    ag.insertar(10, 7);
    ag.insertar(10, 8);
    ag.insertar(5, 1);
    ag.insertar(5, 2);
    ag.insertar(7, 3);
    ag.insertar(7, 4);
    ag.insertar(8, 6);

    // En este árbol cada nodo interno (10, 5, 7, 8) tiene grado = 3, 2, 2, 1 → no es semi-completo
    cout << (ag.esSemiCompleto() ? "Sí\n" : "No\n");  // imprime "No"

    // Ajustamos para que todos los internos tengan 2 hijos
    ArbolGeneral ag2;
    ag2.crearRaiz(10);
    ag2.insertar(10, 5);
    ag2.insertar(10, 7);
    ag2.insertar(5, 1);
    ag2.insertar(5, 2);
    ag2.insertar(7, 3);
    ag2.insertar(7, 4);

    cout << (ag2.esSemiCompleto() ? "Sí\n" : "No\n"); // imprime "Sí"

    return 0;
}