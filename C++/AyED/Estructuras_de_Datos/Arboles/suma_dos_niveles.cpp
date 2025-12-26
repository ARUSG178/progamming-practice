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
        Nodo(int v) : valor(v), child(nullptr), nextSibling(nullptr){}
    };

    Nodo* raiz;            

    //===== Primitivas internas =====

    // busca un nodo con valor v en el subárbol
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

    // recorre y suma valores entre niveles [low..high]
    int sumBetweenRec(Nodo* nodo, int level, int low, int high) const {
        if (!nodo) return 0;
        int s = 0;
        if (level >= low && level <= high) s += nodo->valor;
        s += sumBetweenRec(nodo->child, level + 1, low, high);
        s += sumBetweenRec(nodo->nextSibling, level, low, high);
        return s;
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
        p->child       = n;
    }

    //===== Método adicional público =====

    // suma todos los valores entre niveles low y high (raíz = nivel 0)
    int sumarEntreNiveles(int low, int high) const {
        return sumBetweenRec(raiz, 0, low, high);
    }
};

// Ejemplo de uso
int main() {
    ArbolGeneral ag;
    ag.crearRaiz(1);
    ag.insertar(1, 2);
    ag.insertar(1, 3);
    ag.insertar(1, 4);
    ag.insertar(3, 5);

    int resultado = ag.sumarEntreNiveles(1, 2);
    cout << "Suma entre niveles 1 y 2: " << resultado << endl;
    return 0;
}