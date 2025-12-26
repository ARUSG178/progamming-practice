#include <iostream>
using namespace std;

template<typename T>
class Dipolo {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* front;  // Punto común de salida (inicio de la lista)
    Node* rear;   // Solo usado para cola (para insertar atrás)
    int size;

public:
    Dipolo() : front(nullptr), rear(nullptr), size(0) {}

    ~Dipolo() {
        while (!empty()) pop(); // simplemente elimina nodos
    }

    bool empty() const {
        return front == nullptr;
    }

    int getSize() const {
        return size;
    }

    // ————————— PILA —————————
    void push(const T& value) {
        Node* newNode = new Node(value, front); // se inserta por delante
        front = newNode;
        if (size == 0) rear = newNode;
        ++size;
    }

    // ————————— COLA —————————
    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        ++size;
    }

    // ————————— ELIMINACIÓN  —————————
    void pop() {
        if (empty()) return;
        Node* temp = front;
        front = front->next;
        delete temp;
        --size;
        if (size == 0) rear = nullptr;
    }

    void dequeue() {
        if (empty()) return;

        if (front == rear) {
            // Solo hay un elemento
            delete rear;
            front = rear = nullptr;
        } else {
            // Recorremos hasta el penúltimo
            Node* prev = front;
            while (prev->next != rear) {
                prev = prev->next;
            }
            delete rear;
            rear = prev;
            rear->next = nullptr;
        }
    --size;
    }

    // ————————— CONSULTA NO DESTRUCTIVA —————————
    T& peek() {
        if (empty()) throw runtime_error("Dipolo vacío");
        return front->data;
    }

    T& last() {
    if (empty()) throw std::runtime_error("Dipole vacío");

    Node* current = front;
    while (current != rear) {
        current = current->next;
    }

    return current->data;
}

    // ————————— VISUALIZACIÓN —————————
    void print() const {
        Node* curr = front;
        cout << "Dipolo → ";
        while (curr) {
            cout << curr->data << " → ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Dipolo<int> d;

    d.enqueue(10);   // cola
    d.enqueue(20);
    d.push(5);    // pila (se mete por delante)

    d.print();         // Esperado: 5 → 10 → 20 → NULL

    cout << "peek(): " << d.peek() << endl; // 5

    d.pop();           // elimina 5 (frente)
    d.print();         // 10 → 20 → NULL

    return 0;
}