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
    int  Size() const { return size; }

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


    // Elimina un nodo dado (por puntero)
    void remove(Node* target) {
        if (!head || !target) return;

        if (head == target) {
            head = head->next;
            delete target;
            return;
        }

        Node* prev = head;
        while (prev->next && prev->next != target) {
            prev = prev->next;
        }

        if (prev->next == target) {
            prev->next = target->next;
            delete target;
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

int main() {
    List<int> lista;

    // 1) Inserciones básicas
    lista.push_back(20);
    lista.push_front(10);
    lista.push_back(30);

    cout << "Después de push_front y push_back:\n";
    lista.print();   // head -> 10 -> 20 -> 30 -> tail

    // 2) Insertar 15 **antes** de 20
    auto nodo20 = lista.getPosition(20);
    if (nodo20) {
        lista.insert(15, nodo20);
    }

    cout << "\nDespués de insertar 15 antes de 20:\n";
    lista.print();   // head -> 10 -> 15 -> 20 -> 30 -> tail

    // 3) Eliminar el nodo con dato 15 (por puntero)
    auto nodo15 = lista.getPosition(15);
    if (nodo15) {
        lista.remove(nodo15);
    }

    cout << "\nDespués de eliminar 15 (por nodo):\n";
    lista.print();   // head -> 10 -> 20 -> 30 -> tail

    // 4) Eliminar por valor
    lista.remove(20);

    cout << "\nDespués de eliminar 20 (por valor):\n";
    lista.print();   // head -> 10 -> 30 -> tail

    // 5) Mostrar front() y back()
    if (!lista.empty()) {
        cout << "\nFront: " << lista.front()
        << "   Back: " << lista.back() << "\n";
    }

    // 6) Vaciar la lista
    lista.clear();
    cout << "\nDespués de clear():\n";
    lista.print();   // head -> tail

    return 0;
}