#include <iostream>
using namespace std;

template <typename T>
class Tree {
    private:
        struct Node {
            T data;
            Node* padre;
            Node* hijo;
            Node* hermano;
            Node (const T &data, Node* p = nullptr) : hijo(nullptr), hermano(nullptr) {}
        };

        Node* raiz;

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

        void podarHojas(Node* ref){
            if(!ref) return;

            podarHojas(ref->hijo);
            
            podarHojas(ref->hermano);

            if(!ref->hijo) {
                Node* eliminar = ref;
                ref = hermano->ref;
                delete eliminar;
            }
        }

    public:
        
        void Podar(){
            podarHojas(raiz);
        }

        void insert(Node* padre, const T& data) {
            // 1. Si padre es null, creamos la raíz y salimos
            if (!padre) {
                raiz = new Node(data, nullptr);
                return;
            }

            // 2. Creamos el nuevo nodo con puntero a padre
            Node* nuevoHijo = new Node(data, padre);

            // 3. Si no hay hijos, lo enlazamos como primer hijo
            if (!padre->hijo) {
                padre->hijo = nuevoHijo;
                return;
            }

            // 4. Si hay hijos, avanzamos hasta el último hermano
            Node* ultimo = padre->hijo;
            while (ultimo->hermano) {
                ultimo = ultimo->hermano;
            }

            // 5. Enganchamos el nuevo nodo como hermano del último
            ultimo->hermano = nuevoHijo;
        }
    



};