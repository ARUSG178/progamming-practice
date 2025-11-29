#include <iostream>
using namespace std;

// BST + AVL: Ahora manejamos LL, RR, LR y RL  
class BST {
private:
    struct Nodo {
        int valor;
        Nodo* izquierdo;
        Nodo* derecho;
        Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
    };

    Nodo* raiz;

    //===== Primitivas originales =====

    Nodo* insert(Nodo* nodo, int valor) {
        if (!nodo) return new Nodo(valor);
        if (valor < nodo->valor)
            nodo->izquierdo = insert(nodo->izquierdo, valor);
        else if (valor > nodo->valor)
            nodo->derecho   = insert(nodo->derecho, valor);
        return nodo;
    }

    Nodo* eliminarNodo(Nodo* nodo, int valor) {
        if (!nodo) return nullptr;
        if (valor < nodo->valor)
            nodo->izquierdo = eliminarNodo(nodo->izquierdo, valor);
        else if (valor > nodo->valor)
            nodo->derecho   = eliminarNodo(nodo->derecho, valor);
        else {
            if (!nodo->izquierdo && !nodo->derecho) {
                delete nodo;
                return nullptr;
            }
            if (!nodo->izquierdo) {
                Nodo* tmp = nodo->derecho;
                delete nodo;
                return tmp;
            }
            if (!nodo->derecho) {
                Nodo* tmp = nodo->izquierdo;
                delete nodo;
                return tmp;
            }
            Nodo* suc = minNodo(nodo->derecho);
            nodo->valor = suc->valor;
            nodo->derecho = eliminarNodo(nodo->derecho, suc->valor);
        }
        return nodo;
    }

    bool findNodo(Nodo* nodo, int valor) const {
        if (!nodo) return false;
        if (nodo->valor == valor) return true;
        return valor < nodo->valor
            ? findNodo(nodo->izquierdo, valor)
            : findNodo(nodo->derecho,  valor);
    }

    Nodo* minNodo(Nodo* nodo) const {
        while (nodo && nodo->izquierdo) nodo = nodo->izquierdo;
        return nodo;
    }

    Nodo* maxNodo(Nodo* nodo) const {
        while (nodo && nodo->derecho) nodo = nodo->derecho;
        return nodo;
    }

    void inorden(Nodo* nodo) const {
        if (!nodo) return;
        inorden(nodo->izquierdo);
        cout << nodo->valor << " ";
        inorden(nodo->derecho);
    }

    void preorden(Nodo* nodo) const {
        if (!nodo) return;
        cout << nodo->valor << " ";
        preorden(nodo->izquierdo);
        preorden(nodo->derecho);
    }

    void postorden(Nodo* nodo) const {
        if (!nodo) return;
        postorden(nodo->izquierdo);
        postorden(nodo->derecho);
        cout << nodo->valor << " ";
    }

    int contarHojas(Nodo* nodo) const {
        if (!nodo) return 0;
        if (!nodo->izquierdo && !nodo->derecho) return 1;
        return contarHojas(nodo->izquierdo) + contarHojas(nodo->derecho);
    }

    int tamanoSub(Nodo* nodo) const {
        if (!nodo) return 0;
        return 1 + tamanoSub(nodo->izquierdo) + tamanoSub(nodo->derecho);
    }

    int alturaSub(Nodo* nodo) const {
        if (!nodo) return 0;
        return 1 + std:: max(alturaSub(nodo->izquierdo), alturaSub(nodo->derecho));
    }

    void destruir(Nodo* nodo) {
        if (!nodo) return;
        destruir(nodo->izquierdo);
        destruir(nodo->derecho);
        delete nodo;
    }

    //===== Utilidades AVL =====

    // Retorna factor de balance: altura(izq) – altura(der)
    int getBalance(Nodo* x) const {
        return x ? alturaSub(x->izquierdo) - alturaSub(x->derecho) : 0;
    }

    // Rotación simple a la derecha (caso LL)
    //         x                   y
    //        / \                 / \
    //       y   T3   -->        T1  x
    //      / \                     / \
    //     T1  z                   z  T3
    Nodo* rotarDerecha(Nodo* x) {
        Nodo* y = x->izquierdo;
        Nodo* z = y->derecho;
        y->derecho = x;
        x->izquierdo = z;
        return y;
    }

    // Rotación simple a la izquierda (caso RR)
    //     x                       y
    //    / \                     / \
    //   T1  y    -->           x   T3
    //      / \                 / \
    //     z  T3               T1  z
    Nodo* rotarIzquierda(Nodo* x) {
        Nodo* y = x->derecho;
        Nodo* z = y->izquierdo;
        y->izquierdo = x;
        x->derecho = z;
        return y;
    }

    // Insertor AVL recursivo (devuelve nueva raíz de subárbol)
    Nodo* insertAVL(Nodo* x, int valor) {
        // 1. Inserción BST normal
        if (!x) return new Nodo(valor);

        if (valor < x->valor) x->izquierdo = insertAVL(x->izquierdo, valor);
        else if (valor > x->valor) x->derecho = insertAVL(x->derecho, valor);

        else return x; // duplicados ignorados

        // 2. Calcula balance
        int balance = getBalance(x);

        // 3. Corrige los 4 casos

        // LL: inserción en rama izquierda de hijo izquierdo
        if (balance > 1 && valor < x->izquierdo->valor)
            return rotarDerecha(x);

        // RR: inserción en rama derecha de hijo derecho
        if (balance < -1 && valor > x->derecho->valor)
            return rotarIzquierda(x);

        // LR: inserción en rama derecha de hijo izquierdo
        if (balance > 1 && valor > x->izquierdo->valor) {
            x->izquierdo = rotarIzquierda(x->izquierdo);
            return rotarDerecha(x);
        }

        // RL: inserción en rama izquierda de hijo derecho
        if (balance < -1 && valor < x->derecho->valor) {
            x->derecho = rotarDerecha(x->derecho);
            return rotarIzquierda(x);
        }

        return x; // ya balanceado
    }

public:
    BST() : raiz(nullptr) {}
    ~BST() { destruir(raiz); }

    // Métodos originales
    void insertar(int valor)   { raiz = insert(raiz, valor); }
    void eliminar(int valor)    { raiz = eliminarNodo(raiz, valor); }
    bool existe(int v) const    { return findNodo(raiz, v); }
    int minimo() const          { Nodo* n = minNodo(raiz); return n ? n->valor : -1; }
    int maximo() const          { Nodo* n = maxNodo(raiz); return n ? n->valor : -1; }
    void recorridoIn() const    { inorden(raiz); cout << "\n"; }
    void recorridoPre() const   { preorden(raiz); cout << "\n"; }
    void recorridoPost() const  { postorden(raiz); cout << "\n"; }
    int contarHojas() const     { return contarHojas(raiz); }
    int tamano() const          { return tamanoSub(raiz); }
    int altura() const          { return alturaSub(raiz); }

    // Nuevo método: Inserta y mantiene AVL
    void insertarAVL(int valor) {
        raiz = insertAVL(raiz, valor);
    }
};

// Ejemplo de uso
int main() {
    BST tree;

    // Uso BST puro
    tree.insertar(50);
    tree.insertar(30);
    tree.insertar(70);

    // Uso AVL
    tree.insertarAVL(20);
    tree.insertarAVL(10);
    tree.insertarAVL(5);    // provocará rotaciones LL

    cout << "Inorden AVL: "; tree.recorridoIn();
    return 0;
}