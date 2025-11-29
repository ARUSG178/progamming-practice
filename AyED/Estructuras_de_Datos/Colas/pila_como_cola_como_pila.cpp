#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Dipole {
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
    Dipole() : front(nullptr), rear(nullptr), size(0) {}
    Dipole(const Dipole<T> &other) : front(nullptr), rear(nullptr), size(0) {
        Node* current = other.front;
        while(current != nullptr) {
            enqueue(current->data);
            current = current->next;
        }
    }


    ~Dipole() {
        while (!empty()) pop(); // simplemente elimina nodos
    }

    bool empty() const {
        return front == nullptr;
    }

    int getSize() const {
        return size;
    }

    void push(const T& value) {
        Node* newNode = new Node(value, front); // se inserta por delante
        front = newNode;
        if (size == 0) rear = newNode;
        ++size;
    }

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

    T& peek() {
        if (empty()) throw runtime_error("Dipole vacío");
        return front->data;
    }

    T& last() {
        if (empty()) throw runtime_error("Dipole vacío");

        Node* current = front;
        while (current != rear) {
            current = current->next;
        }
        return current->data;
    }
    void print() const {
        Node* curr = front;
        std::cout << "Dipole → ";
        while (curr) {
            std::cout << curr->data << " → ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }

};

void likeS(Dipole<int> stack) {
    Dipole<int> stackC;

    // Insertamos como cola (orden stack)
    while (!stack.empty()) {
        stackC.enqueue(stack.peek());
        stack.pop();
    }

    int suma = 0;

    // Extraemos como pila: desde el final
    while (!stackC.empty()) {
        suma += stackC.last();     // último elemento
        stackC.dequeue();          // eliminación desde el final
    }

    std::cout << "Suma como Pila = " << suma << endl;
};

void likeQ(Dipole<int> queue){
    Dipole<int> queueC(queue);
    int suma = 0;
    while(!queueC.empty()){
        suma += queueC.peek();
        queueC.pop();
    }
    std::cout << "Suma como Cola = " << suma << endl;
    queueC.~Dipole();
}

int main() {
    Dipole<int> d;

    // Insertamos en el dipolo: 10 y 20 como cola, 5 como pila (al frente)
    d.enqueue(10);   // entra primero
    d.enqueue(20);   // entra segundo
    d.push(5);       // entra al frente

    d.print();  // Esperado: 5 → 10 → 20 → NULL

    std::cout << "peek(): " << d.peek() << std::endl;  // Debería mostrar 5

    // Probamos likeS y likeQ
    std::cout << "\nUsando likeS (pila simulada):\n";
    likeS(d);

    std::cout << "\nUsando likeQ (cola simulada):\n";
    likeQ(d);

    return 0;
}