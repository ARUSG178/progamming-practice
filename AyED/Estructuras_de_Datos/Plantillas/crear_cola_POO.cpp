#include <iostream>
#include <stack>
#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* front;   // Primer elemento
    Node* rear;    // Último elemento
    int count;     // Cantidad de elementos

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    // Constructor de copia (copia profunda)
    Queue(const Queue<T> &other) : front(nullptr), rear(nullptr), count(0) {
        Node* current = other.front;
        while (current != nullptr) {
            enqueue(current->data);
            current = current->next;
        }
    }

    // Operador de asignación
    Queue<T>& operator=(const Queue<T>& other) {
        if (this != &other) {
            clear();
            Node* current = other.front;
            while (current != nullptr) {
                enqueue(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // Destructor
    ~Queue() {
        clear();
    }

    // Vaciar la cola
    void clear() {
        while (!empty()) {
            dequeue();
        }
    }

    // Está vacía
    bool empty() const {
        return count == 0;
    }

    // Insertar elemento al final
    void enqueue(const T& x) {
        Node* newNode = new Node(x);
        if (empty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    // Eliminar el primer elemento
    void dequeue() {
        if (empty()) {
            throw std::out_of_range("Cola vacía");
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Tamaño de la cola
    int size() const {
        return count;
    }

    // Elemento del frente
    T head() const {
        if (empty()) {
            throw std::out_of_range("Cola vacía");
        }
        return front->data;
    }

    // Imprimir cola (sin destruirla)
    void print() const {
        Queue<T> copy(*this);
        std::cout << "front -> ";
        while (!copy.empty()) {
            std::cout << copy.head() << " -> ";
            copy.dequeue();
        }
        std::cout << "null" << std::endl;
    }

    // Imprimir al revés (sin destruir)
    void invertPrint() const {
        std::stack<T> pila;
        Queue<T> copy(*this);
        while (!copy.empty()) {
            pila.push(copy.head());
            copy.dequeue();
        }
        std::cout << "rear -> ";
        while (!pila.empty()) {
            std::cout << pila.top() << " -> ";
            pila.pop();
        }
        std::cout << "front" << std::endl;
    }

    // Promedio de los elementos
    double average() const {
        if (empty()) return 0.0;
        Queue<T> copy(*this);
        double suma = 0;
        while (!copy.empty()) {
            suma += copy.head();
            copy.dequeue();
        }
        return suma / size();
    }
};

int main() {
    Queue<int>* colaNumeros = new Queue<int>();

    std::cout << "\n=== COLA DE NÚMEROS ===" << std::endl;
    colaNumeros->enqueue(100);
    colaNumeros->enqueue(200);
    colaNumeros->enqueue(300);

    std::cout << "Frente: " << colaNumeros->head() << std::endl;
    std::cout << "Tamaño: " << colaNumeros->size() << std::endl;

    std::cout << "\n📤 Contenido:\n";
    colaNumeros->print();

    std::cout << "\n🔁 Invertida:\n";
    colaNumeros->invertPrint();

    std::cout << "\n📊 Promedio: " << colaNumeros->average() << std::endl;

    colaNumeros->dequeue();
    std::cout << "\nDespués de un dequeue:\n";
    colaNumeros->print();

    delete colaNumeros;  // Limpieza

    return 0;
}