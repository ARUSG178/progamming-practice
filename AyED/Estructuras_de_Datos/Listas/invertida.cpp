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
        pos->next = newNode;
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
    int  getSize() const { return sz; }

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
        T val = node->data;
        head->next = node->next;        // salta el nodo
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
    void remove(Node* node) {
        if (!node || node == head || node == tail) return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
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

    void reverse(){
        Node *left = head->next;
        Node *right = tail->prev;
        Node *aux = new Node();
        while(left != right && left->next != right){
            aux->data = left->data;
            left->data = right->data;
            right->data = aux->data;

            left = left->next;
            right = right->prev;
        }
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

int main(){
    DLList<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.push_back(6);
    L.push_back(7);

    cout << "Antes: "; L.print();   // head <-> 1 <-> 2 <-> 3 <-> 4 <-> tail

    L.reverse();

    cout << "Después: "; L.print(); // head <-> 4 <-> 3 <-> 2 <-> 1 <-> tail
}