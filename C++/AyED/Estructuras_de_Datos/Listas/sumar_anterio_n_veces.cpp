#include <iostream>
using namespace std;

template<typename T>
class CDLList {
private:
    struct Node {
        T      data;
        Node*  next;
        Node*  prev;
        Node(const T& d = T())
            : data(d), next(this), prev(this) {}
    };

    Node* head;   // centinela único
    int   sz;

public:
    // Constructor vacío
    CDLList()
        : head(new Node()), sz(0) { }

    // Constructor de copia
    CDLList(const CDLList& other)
        : CDLList() {
        for (Node* cur = other.head->next; cur != other.head; cur = cur->next) {
            push_back(cur->data);
        }
    }

    // Destructor
    ~CDLList() {
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
        head->next = head->prev = head;
        sz = 0;
    }

    // Inserta al inicio
    void push_front(const T& value) {
        Node* node = new Node(value);
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next  = node;
        ++sz;
    }

    // Inserta al final
    void push_back(const T& value) {
        Node* node = new Node(value);
        node->prev = head->prev;
        node->next = head;
        head->prev->next = node;
        head->prev = node;
        ++sz;
    }

    // Extrae y devuelve el primer elemento
    T pop_front() {
        if (empty()) throw runtime_error("pop_front en lista vacía");
        Node* node = head->next;
        T val  = node->data;
        head->next = node->next;
        node->next->prev = head;
        delete node;
        --sz;
        return val;
    }

    // Extrae y devuelve el último elemento
    T pop_back() {
        if (empty()) throw runtime_error("pop_back en lista vacía");
        Node* node = head->prev;
        T val = node->data;
        head->prev  = node->prev;
        node->prev->next = head;
        delete node;
        --sz;
        return val;
    }

    // Inserta antes de 'pos' (si pos==head, equivale a push_back)
    void insert(const T& value, Node* pos) {
        if (!pos || pos == head) {
            push_back(value);
            return;
        }
        Node* node = new Node(value);
        node->next = pos;
        node->prev = pos->prev;
        pos->prev->next = node;
        pos->prev  = node;
        ++sz;
    }

    // Elimina un nodo dado (por puntero)
    void remove(Node* pos) {
        if (!pos || pos == head) return;
        pos->prev->next = pos->next;
        pos->next->prev = pos->prev;
        delete pos;
        --sz;
    }

    // Elimina la primera aparición de 'value'
    void remove(const T& value) {
        Node* cur = head->next;
        while (cur != head) {
            if (cur->data == value) {
                remove(cur);
                return;
            }
            cur = cur->next;
        }
    }

    // Devuelve el primer nodo que contiene 'value', o nullptr
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
        return head->prev->data;
    }

    // Imprime la lista en sentido forward
    void print() const {
        if (empty()) {
            cout << "(vacía)\n";
            return;
        }
        Node* cur = head->next;
        cout << cur->data;
        cur = cur->next;
        while (cur != head) {
            cout << " <-> " << cur->data;
            cur = cur->next;
        }
        cout << '\n';
    }

    CDLList<int> sumar_anterio_n_veces(CDLList<int> list, int n){
        Node* current = head->next;
        Node* prev = head->prev;
        for (int i = 0; i < n; i++) {
            current = head->next;
            prev = head->prev;
            while(current != head) {
                current->data += prev->data;
                current = current->next;
                prev = prev->next;
            }
        }
    }
};

CDLList<int> sumar_anterio_n_veces_out(CDLList<int> list, int n){
    int size = list.size();

    if(n == 0) return list;

    for(int i = 0; i < n; i++){
        int prev = list.back();
        for(int j = 0; j < size; j++){
            int current = list.pop_front();
            list.push_back(current + prev);
            prev = current;}
        }


    }

