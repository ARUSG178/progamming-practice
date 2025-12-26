#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

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
    Queue(const Queue<T>& other) : front(nullptr), rear(nullptr), count(0) {
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
            throw out_of_range("Cola vacía");
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
            throw out_of_range("Cola vacía");
        }
        return front->data;
    }

    // Imprimir cola (sin destruirla)
    void print() const {
        Queue<T> copy(*this);
        cout << "front -> ";
        while (!copy.empty()) {
            cout << copy.head() << " -> ";
            copy.dequeue();
        }
        cout << "null" << endl;
    }
};

void majorMinor(Queue<int> intQueue){
    Queue<int> copy(intQueue);
    int mayor = copy.head();
    int menor = copy.head();

    while(!copy.empty()){
        if(mayor < copy.head()) mayor = copy.head();
        if(menor > copy.head()) menor = copy.head();
        copy.dequeue();
    }

    cout << "El mayor es: " << mayor << endl;
    cout << "El menor es: " << menor << endl;
}



int main() {
    Queue<int> numeros;

    // Insertar elementos
    numeros.enqueue(17);
    numeros.enqueue(42);
    numeros.enqueue(-8);
    numeros.enqueue(23);
    numeros.enqueue(42);  // valor duplicado

    cout << "\n📦 Contenido actual:\n";
    numeros.print();  // Imprime sin destruir

    cout << "\n📈 Mayor y menor:\n";
    majorMinor(numeros);

    cout << "\n🚪 Quitamos un elemento:\n";
    numeros.dequeue();
    numeros.print();

    cout << "\n📈 Nuevos mayor y menor:\n";
    majorMinor(numeros);

    return 0;
}
    