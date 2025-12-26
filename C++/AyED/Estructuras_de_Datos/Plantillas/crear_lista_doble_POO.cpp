#include <iostream>
using namespace std;

template <typename T>
class DLList {
private:
    struct Node {
        T      data;
        Node*  prev;
        Node*  next;
        Node(const T& d = T(), Node* p = nullptr, Node* n = nullptr)
            : data(d), prev(p), next(n) {}
    };

    Node* head;   // centinela inicial
    Node* tail;   // centinela final
    int   sz;

    // Inserta **después** de pos (interno O(1))
    void insertAfter(Node* pos, const T& value) {
        Node* newNode = new Node(value, pos, pos->next);
        pos->next->prev = newNode;
        pos->next       = newNode;
        ++sz;
    }

public:
    DLList()
        : head(new Node()), tail(new Node()), sz(0) {
        head->next = tail;
        tail->prev = head;
    }

    // Constructor de copia
    DLList(const DLList& other)
        : DLList() {
        for (Node* cur = other.head->next; cur != other.tail; cur = cur->next) {
            push_back(cur->data);
        }
    }

    ~DLList() {
        clear();
        delete head;
        delete tail;
    }

    bool empty() const { return sz == 0; }
    int  size() const { return sz; }

    // Vacía la DLList
    void clear() {
        Node* cur = head->next;
        while (cur != tail) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        head->next = tail;
        tail->prev = head;
        sz = 0;
    }

    // Extrae y devuelve el primer elemento
    T pop_front() {
        if (empty()) {
            throw runtime_error("pop_front en lista vacía");
        }
        Node* node = head->next;       // primer nodo real
        T      val = node->data;
        head->next      = node->next;  // salta el nodo
        node->next->prev = head;
        delete node;
        --sz;
        return val;
    }

    // Extrae y devuelve el último elemento
    T pop_back() {
        if (empty()) {
            throw runtime_error("pop_back en lista vacía");
        }
        Node* node = tail->prev;       // último nodo real
        T      val = node->data;
        tail->prev      = node->prev;  // salta el nodo
        node->prev->next = tail;
        delete node;
        --sz;
        return val;
    }

    // Inserta al frente
    void push_front(const T& value) {
        insertAfter(head, value);
    }

    // Inserta al final
    void push_back(const T& value) {
        insertAfter(tail->prev, value);
    }

    // Elimina un nodo dado (por puntero)
    void remove(Node* target) {
        if (!target || target == head) return;  // Nunca eliminamos el centinela

        target->prev->next = target->next;
        target->next->prev = target->prev;

        delete target;
        --sz;
    }

    // Elimina la primera aparición de value
    void remove(const T& value) {
        Node* cur = head->next;
        while (cur != tail) {
            if (cur->data == value) {
                remove(cur);
                return;
            }
            cur = cur->next;
        }
    }

    // Inserta **antes** de v
    void insert(const T& value, Node* v) {
        if (v == nullptr || v == head->next) {
            push_front(value);
        } else if (v == tail) {
            push_back(value);
        } else {
            insertAfter(v->prev, value);
        }
    }

    // Devuelve el nodo con dato == value o nullptr
    Node* getPosition(const T& value) const {
        Node* cur = head->next;
        while (cur != tail) {
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
        return tail->prev->data;
    }

    // Imprime la DLList de izq a der
    void print() const {
        cout << "head";
        for (Node* cur = head->next; cur != tail; cur = cur->next) {
            cout << " <-> " << cur->data;
        }
        cout << " <-> tail\n";
    }
};
// Ejemplo de uso
int main() {
    DLList<int> L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    cout << "Después de push_back: ";
    L.print();

    auto n20 = L.getPosition(20);
    L.insert(15, n20);
    cout << "Después de insertar 15 antes de 20: ";
    L.print();

    L.remove(10);
    cout << "Después de remove(10): ";
    L.print();

    L.push_front(5);
    cout << "Después de push_front(5): ";
    L.print();

    cout << "Front: " << L.front()
    << "  Back: " << L.back() << "\n";

    L.clear();
    cout << "Después de clear(): ";
    L.print();

    return 0;
}