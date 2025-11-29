#include <iostream>
using namespace std;

class ArbolGeneral {
public:
    // Nodo en representación hijo-izquierdo / hermano-derecho
    struct Nodo {
        char valor;
        Nodo* child;       // primer hijo
        Nodo* nextChild;   // hermano inmediato
        Nodo* parent;      // puntero al padre

        Nodo(char v, Nodo* p = nullptr) : valor(v), child(nullptr), nextChild(nullptr), parent(p) {}
    };

private:
    Nodo* raiz;

    // Busca (DFS) el primer nodo con valor v
    Nodo* findNodo(Nodo* nodo, char v) const {
        if (!nodo) return nullptr;
        if (nodo->valor == v) return nodo;
        Nodo* r = findNodo(nodo->child, v);
        if (r) return r;
        return findNodo(nodo->nextChild, v);
    }

    // Preorden interno: raíz → todos los hijos
    void preRec(Nodo* nodo) const {
        if (!nodo) return;
        cout << nodo->valor << ' ';
        Nodo* c = nodo->child;
        while (c) {
            preRec(c);
            c = c->nextChild;
        }
    }

    // Postorden interno: todos los hijos → raíz
    void postRec(Nodo* nodo) const {
        if (!nodo) return;
        Nodo* c = nodo->child;
        while (c) {
            postRec(c);
            c = c->nextChild;
        }
        cout << nodo->valor << ' ';
    }

    // Cuenta todos los nodos del subárbol
    int countRec(Nodo* nodo) const {
        if (!nodo) return 0;
        int cnt = 1;
        Nodo* c = nodo->child;
        while (c) {
            cnt += countRec(c);
            c = c->nextChild;
        }
        return cnt;
    }

    // Cuenta hojas (nodos sin hijos)
    int leafRec(Nodo* nodo) const {
        if (!nodo) return 0;
        if (!nodo->child) return 1;
        int cnt = 0;
        Nodo* c = nodo->child;
        while (c) {
            cnt += leafRec(c);
            c = c->nextChild;
        }
        return cnt;
    }

    // Altura (profundidad máxima)
    int heightRec(Nodo* nodo) const {
        if (!nodo) return 0;
        int h = 0;
        Nodo* c = nodo->child;
        while (c) {
            int ch = heightRec(c);
            if (ch > h) h = ch;
            c = c->nextChild;
        }
        return h + 1;
    }

    // Libera recursivamente todo el subárbol
    void deleteSubtree(Nodo* nodo) {
        if (!nodo) return;
        Nodo* c = nodo->child;
        while (c) {
            Nodo* next = c->nextChild;
            deleteSubtree(c);
            c = next;
        }
        delete nodo;
    }

public:
    ArbolGeneral() : raiz(nullptr) {}
    ~ArbolGeneral() { deleteSubtree(raiz); }

    // Crea o reinicia la raíz (su parent será nullptr)
    void crearRaiz(char v) {
        deleteSubtree(raiz);
        raiz = new Nodo(v, nullptr);
    }

    // Devuelve puntero a la raíz (puede ser nullptr)
    Nodo* getRoot() const {
        return raiz;
    }

    // Inserta 'valor' como hijo de 'padre'.
    // Si padre==nullptr y el árbol está vacío, crea la raíz.
    // Retorna el nodo creado o nullptr si falla.
    Nodo* insertar(Nodo* padre, char valor) {
        if (!padre) {
            if (!raiz) {
                raiz = new Nodo(valor, nullptr);
                return raiz;
            }
            return nullptr;  // padre nulo pero ya existe raíz
        }
        Nodo* nuevo = new Nodo(valor, padre);
        if (!padre->child)  padre->child = nuevo;
        else {
            Nodo* last = padre->child;
            while (last->nextChild) {
                last = last->nextChild;
            }
            last->nextChild = nuevo;
        }
        return nuevo;
    }

    // Retorna el padre de 'nodo' (o nullptr)
    Nodo* getParent(Nodo* nodo) const {
        return nodo ? nodo->parent : nullptr;
    }

    // Verifica existencia de un valor en el árbol
    bool existe(char v) const {
        return findNodo(raiz, v) != nullptr;
    }

    // Recorrido Preorden público
    void preOrden() const {
        cout << "Preorden: ";
        preRec(raiz);
        cout << "\n";
    }

    // Recorrido Postorden público
    void postOrden() const {
        cout << "Postorden: ";
        postRec(raiz);
        cout << "\n";
    }

    // Métricas: nodos, hojas, altura
    int contarNodos() const {
        return countRec(raiz);
    }

    int contarHojas() const {
        return leafRec(raiz);
    }

    int altura() const {
        return heightRec(raiz);
    }
};

// Ejemplo de uso
int main() {
    ArbolGeneral ag;
    ag.crearRaiz('A');
    ArbolGeneral::Nodo* r = ag.getRoot();
    ArbolGeneral::Nodo* b = ag.insertar(r, 'B');
    ArbolGeneral::Nodo* c = ag.insertar(r, 'C');
    ArbolGeneral::Nodo* d = ag.insertar(r, 'D');
    ArbolGeneral::Nodo* e = ag.insertar(c, 'E');
    ArbolGeneral::Nodo* f = ag.insertar(c, 'F');

    ag.preOrden();   // A B C E F D
    ag.postOrden();  // B E F C D A

    cout << "Nodos:  " << ag.contarNodos() << "\n";
    cout << "Hojas:  " << ag.contarHojas() << "\n";
    cout << "Altura: " << ag.altura() << "\n";

    return 0;
}