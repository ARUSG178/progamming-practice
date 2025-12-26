#include <iostream>
#include <string>
using namespace std;

class Familia {
private:
    struct Node {
        string nombre;
        Node* padre;
        Node* hijo;
        Node* hermano;
        Node(const string& n, Node* p = nullptr): nombre(n), padre(p), hijo(nullptr), hermano(nullptr) {}
    };

    Node* raiz;

    // Inserta un hijo bajo 'nodo'
    void insert(Node* nodo, const string& nombre) {
        Node* nFamiliar = new Node(nombre, nodo);
        if (!nodo->hijo) {
            nodo->hijo = nFamiliar;
        } else {
            Node* ultimo = nodo->hijo;
            while (ultimo->hermano) {
                ultimo = ultimo->hermano;
            }
            ultimo->hermano = nFamiliar;
        }
    }

    // Busca un nodo por nombre (DFS hijo-hermano)
    Node* findNodo(Node* actual, const string& nombre) {
        if (!actual) return nullptr;
        if (actual->nombre == nombre) return actual;
        if (Node* res = findNodo(actual->hijo, nombre)) return res;
        return findNodo(actual->hermano, nombre);
    }

    // Imprime los primos de 'nombre'
    void imprimirPrimos(const string& nombre) {
        Node* persona = findNodo(raiz, nombre);
        if (!persona || !persona->padre || !persona->padre->padre) {
            cout << "No hay primos para " << nombre << "\n";
            return;
        }

        Node* padre  = persona->padre;
        Node* abuelo = padre->padre;

        Node* tio = abuelo->hijo;
        while (tio) {
            if (tio != padre) {
                Node* primo = tio->hijo;
                while (primo) {
                    cout << primo->nombre << " ";
                    primo = primo->hermano;
                }
            }
            tio = tio->hermano;
        }
        cout << "\n";
    }

public:
    Familia() : raiz(nullptr) {}

    // Método público para insertar un familiar
    // Si la familia está vacía, crea la raíz con 'childName'
    void add(const string& parentName, const string& childName) {
        if (!raiz) {
            raiz = new Node(childName, nullptr);
        }
        else {
            Node* padre = findNodo(raiz, parentName);
            if (!padre) {
                cout << "No existe el familiar “" << parentName << "”\n";
                return;
            }
            insert(padre, childName);
        }
    }

    // Método público para mostrar primos
    void showPrimos(const string& name) {
        imprimirPrimos(name);
    }
};

int main() {
    Familia fam;

    // 1. Crear la raíz (abuelo)
    fam.add("", "Abuelo");        

    // 2. Hijos del abuelo
    fam.add("Abuelo", "Padre");
    fam.add("Abuelo", "Tio");

    // 3. Hijos del padre
    fam.add("Padre", "Yo");
    fam.add("Padre", "Hermano");

    // 4. Hijos del tío (mis primos)
    fam.add("Tio", "Primo1");
    fam.add("Tio", "Primo2");

    // 5. Consultas de primos
    cout << "Primos de Yo: ";
    fam.showPrimos("Yo");        // Debería listar: Primo1 Primo2

    cout << "Primos de Hermano: ";
    fam.showPrimos("Hermano");   // Debería listar: Primo1 Primo2

    cout << "Primos de Padre: ";
    fam.showPrimos("Padre");     // No hay primos para Padre

    return 0;
}