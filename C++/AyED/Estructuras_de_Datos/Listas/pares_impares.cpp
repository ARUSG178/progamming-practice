#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T      data;
        Node*  next;
        Node(const T& d = T(), Node* n = nullptr)
            : data(d), next(n) {}
    };

    Node* head;   // centinela inicial
    Node* tail;   // centinela final
    int   size;

    // Inserta **después** de un nodo dado
    void insertAfter(Node* pos, const T& value) {
        Node* newNode = new Node(value, pos->next);
        pos->next = newNode;
        ++size;
    }

public:
    List() : head(new Node()), tail(new Node()), size(0) {
        head->next = tail;
    }

    ~List() {
        clear();
        delete head;
        delete tail;
    }

    bool empty() const { return size == 0; }
    int  getSize() const { return size; }

    // Vacía la lista
    void clear() {
        Node* curr = head->next;
        while (curr != tail) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
        head->next = tail;
        size = 0;
    }

    // Elimina un nodo dado (por puntero)
    void remove(Node* node) {
        if (!node || node == head || node == tail) return;
        Node* prev = head;
        while (prev->next != tail && prev->next != node) {
            prev = prev->next;
        }
        if (prev->next == node) {
            prev->next = node->next;
            delete node;
            --size;
        }
    }

    // Elimina la primera aparición de 'value'
    void remove(const T& value) {
        Node* prev = head;
        Node* curr = head->next;
        while (curr != tail) {
            if (curr->data == value) {
                prev->next = curr->next;
                delete curr;
                --size;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Elimina todas las apariciones de 'value'
    void removeAll(const T& value) {
        Node* prev = head;
        Node* curr = head->next;
        while (curr != tail) {
            if (curr->data == value) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                --size;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    // Extrae y devuelve el primer elemento
    T pop_front() {
        if (empty())
            throw runtime_error("pop_front en lista vacía");
        Node* node = head->next;      // primer nodo real
        T      val  = node->data;
        head->next  = node->next;     // salta el nodo
        delete node;
        --size;
        return val;
    }

    // Extrae y devuelve el último elemento
    T pop_back() {
        if (empty())
            throw runtime_error("pop_back en lista vacía");

        // prev apuntará al nodo anterior al último real
        Node* prev = head;
        while (prev->next->next != tail) {
            prev = prev->next;
        }

        Node* last = prev->next;      // último real
        T      val  = last->data;
        prev->next  = tail;           // lo elimina de la cadena
        delete last;
        --size;
        return val;
    }


    // Inserciones en extremos
    void push_front(const T& value) { insertAfter(head, value); }

    void push_back(const T& value) {
        Node* curr = head;
        while (curr->next != tail) curr = curr->next;
        insertAfter(curr, value);
    }

    // Inserta **antes** de 'v'
    void insert(const T& value, Node* v) {
        if (!v || v == head->next) {
            push_front(value);
            return;
        }
        Node* prev = head;
        while (prev->next != tail && prev->next != v) {
            prev = prev->next;
        }
        if (prev->next == v) {
            insertAfter(prev, value);
        }
    }

    bool order(const T& a, const T& b) {
        return a < b;
    }

    void insertOrder(const T& value){
        Node*current = head->next;
        Node*prev = head;
        while(current != tail && order(current->data, value)){
            prev = current;
            current = current -> next;
        }
        insertAfter(prev, value);
    }

    // Devuelve el nodo con dato == value (o nullptr)
    Node* getPosition(const T& value) const {
        Node* curr = head->next;
        while (curr != tail) {
            if (curr->data == value) return curr;
            curr = curr->next;
        }
        return nullptr;
    }

    // Acceso a datos de extremos
    T& front() {
        return head->next->data;
    }
    T& back() {
        Node* curr = head;
        while (curr->next != tail) curr = curr->next;
        return curr->data;
    }

    // Imprime la lista
    void print() const {
        cout << "head -> ";
        for (Node* curr = head->next; curr != tail; curr = curr->next) {
            cout << curr->data << " -> ";
        }
        cout << "tail\n";
    }
};

void pares_impares(List<int>& lista) {
    int total = lista.getSize();
    List<int> pares, impares;

    for(int i = 0; i < total; i++){
        int value = lista.pop_front();
        if(value % 2 == 0) pares.push_back(value);
        else impares.push_back(value);
    }
    cout << "Pares: ";
    pares.print();
    cout << "Impares: ";
    impares.print();

    while(!pares.empty())lista.push_back(pares.pop_front());
    while(!impares.empty()) lista.push_back(impares.pop_front());

    cout << "Lista final: ";
    lista.print();
}

int main() {
    List<int> lista;

    // poblar la lista con valores de ejemplo
    lista.insertOrder(5);
    lista.insertOrder(2);
    lista.insertOrder(8);
    lista.insertOrder(3);
    lista.insertOrder(7);
    lista.insertOrder(4);
    lista.insertOrder(6);
    lista.insertOrder(1);
    
    return 0;
}
