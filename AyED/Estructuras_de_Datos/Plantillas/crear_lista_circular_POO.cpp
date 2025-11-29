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
    void remove(Node* v) {
        if (!v || v == head) return;
        Node* prev = head;
        while (prev->next != head && prev->next != v)
            prev = prev->next;
        if (prev->next == v) {
            prev->next = v->next;
            if (v == tail)
                tail = (v == head->next ? head : prev);
            delete v;
            --sz;
        }
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
};

// Ejemplo de uso
int main() {
    CircularList<int> cl;
    cl.push_back(10);
    cl.push_back(20);
    cl.push_back(30);
    cout << "Inicial: "; cl.print();

    cl.push_front(5);
    cout << "push_front(5): "; cl.print();

    cout << "pop_front(): " << cl.pop_front() << "\n";
    cout << "pop_back(): "  << cl.pop_back()  << "\n";
    cout << "Después pops: "; cl.print();

    auto n20 = cl.getPosition(20);
    cl.insert(15, n20);
    cout << "insert(15 antes de 20): "; cl.print();

    cl.remove(20);
    cout << "remove(20): "; cl.print();

    cout << "Front: " << cl.front()
    << ", Back: " << cl.back() << "\n";

    cl.clear();
    cout << "clear(): "; cl.print();

    return 0;
}