#include <iostream>
using namespace std;

template <typename T>
class CircularList {
private:
    struct Node {
        T      data;
        Node*  next;
        Node(const T& d = T(), Node* n = nullptr)
            : data(d), next(n) {}
    };

    Node* head;  // centinela (no dato)
    Node* tail;  // último nodo real (o head si está vacía)
    int   sz;

    // Inserta **después** de pos (O(1))
    void insertAfter(Node* pos, const T& value) {
        Node* newNode = new Node(value, pos->next);
        pos->next     = newNode;
        if (pos == tail)       // si añadimos tras el último real
            tail = newNode;
        ++sz;
    }

public:
    CircularList() : head(new Node()), tail(head), sz(0) {
        head->next = head;
    }

    ~CircularList() {
        clear();
        delete head;
    }

    bool empty() const { return sz == 0; }
    int  size()  const { return sz; }

    // Vacía la lista
    void clear() {
        Node* cur = head->next;
        while (cur != head) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        head->next = head;
        tail       = head;
        sz         = 0;
    }

    // Inserciones
    void push_front(const T& value) {
        insertAfter(head, value);
    }

    void push_back(const T& value) {
        insertAfter(tail, value);
    }

    // Extracciones
    T pop_front() {
        if (empty()) throw runtime_error("pop_front en lista vacía");
        Node* node = head->next;
        T      val  = node->data;
        head->next  = node->next;
        if (node == tail)  // si era el único real
            tail = head;
        delete node;
        --sz;
        return val;
    }

    T pop_back() {
        if (empty()) throw runtime_error("pop_back en lista vacía");
        // buscar el anterior al tail
        Node* prev = head;
        while (prev->next != tail)
            prev = prev->next;
        Node* node = tail;
        T      val = node->data;
        prev->next = head;
        tail       = (node == head->next ? head : prev);
        delete node;
        --sz;
        return val;
    }

    // Inserta **antes** de v
    void insert(const T& value, Node* v) {
        if (!v || v == head->next) {
            push_front(value);
            return;
        }
        // buscar al predecesor
        Node* prev = head;
        while (prev->next != head && prev->next != v)
            prev = prev->next;
        if (prev->next == v)
            insertAfter(prev, value);
    }

    // Elimina un nodo por puntero
    void remove(Node* current, Node* prev) {
        if (!current || current == head) return;

        prev->next = current->next;
        if (current == tail)
            tail = (current == head->next ? head : prev);

        delete current;
        --sz;
    }

    // Elimina la primera aparición de value
    void remove(const T& value) {
        Node* prev = head;
        Node* cur  = head->next;
        while (cur != head) {
            if (cur->data == value) {
                prev->next = cur->next;
                if (cur == tail)
                    tail = (cur == head->next ? head : prev);
                delete cur;
                --sz;
                return;
            }
            prev = cur;
            cur  = cur->next;
        }
    }

    // Búsqueda de nodo por valor
    Node* getPosition(const T& value) const {
        Node* cur = head->next;
        while (cur != head) {
            if (cur->data == value) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    // Acceso a extremos
    T& front() {
        if (empty()) throw runtime_error("front en lista vacía");
        return head->next->data;
    }
    T& back() {
        if (empty()) throw runtime_error("back en lista vacía");
        return tail->data;
    }

    // Impressión circular
    void print() const {
        if (empty()) {
            cout << "head -> (vacía) -> head\n";
            return;
        }
        cout << "head";
        Node* cur = head->next;
        do {
            cout << " -> " << cur->data;
            cur = cur->next;
        } while (cur != head);
        cout << " -> head\n";
    }

    void eliminarPosicionExacta(const T& p, const T& d) {
        if (p < 1 || d < 0) throw std::runtime_error("Error en los parámetros");

        int sz = size();
        if (sz == 0) return;

        int pos = (p - 1 + d) % sz; // Convertimos a índice base 0

        Node* prev = head;
        Node* current = head->next;
        for (int i = 0; i < pos; ++i) {
            prev = current;
            current = current->next;
        }

        // Eliminamos usando la versión optimizada de remove
        remove(current, prev);
    }
        

    void EliminarnNVeces(const T& p, const T& d, const T& n) {
        if (p < 1 || d < 0 || n <= 0) throw std::runtime_error("Error en los parámetros");

        T pos = p;  // Posición lógica base 1

        for (int i = 0; i < n && size() > 0; ++i) {
            eliminarPosicionExacta(pos, d);
            // No hace falta actualizar pos — cada llamada ya parte desde pos + d con módulo actualizado
        }
    }
};

int main() {
    CircularList<int> lista;

    // Insertamos elementos: 1 → 2 → 3 → 4 → 5 → 6 → 7
    for (int i = 1; i <= 7; ++i)
        lista.push_back(i);

    cout << "Lista inicial:\n";
    lista.print();

    int posicionInicial = 2;  // Lógica, base 1
    int desplazamiento = 3;   // Cada cuánto eliminar
    int cantidad = 4;         // Número total de eliminaciones

    cout << "\nEliminando " << cantidad 
    << " nodos comenzando en P = " << posicionInicial 
    << ", con desplazamiento d = " << desplazamiento << "...\n";

    lista.EliminarnNVeces(posicionInicial, desplazamiento, cantidad);

    cout << "\nLista final:\n";
    lista.print();

    return 0;
}