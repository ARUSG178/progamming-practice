#include <iostream>
using namespace std;

class Tree {
    private:
    struct Node{
        int data;
        Node* izquierdo;
        Node* derecho;

        Node(const int &d) : izquierdo(nullptr), derecho(nullptr) {}
    };

    // Nos abstraemos del insert, qué ladilla

    Node* raiz;

    int Productoria(Node* subRaiz){
        if(!subRaiz) return 1;

        int multi = 1;
        Node* factor = subRaiz;
        while(subRaiz){
            multi *= factor->data;
            multi *= Productoria(factor->izquierdo);
            factor = factor->derecho;
        }

        return multi;
    }

    public:
    Tree() : raiz(0) {}

    int Valor(Node* raiz) {
        if(!raiz) return;

        Node* izquierdo = raiz->izquierdo;
        Node* derecho = raiz->derecho;

        return Productoria(izquierdo) - Productoria(derecho);
    }

    void printValor(){
        cout << Valor(raiz) << endl;
    }
};