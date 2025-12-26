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
            pushQueue(current->data);
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
        if (empty()) throw std::runtime_error("Dipole vacío");

        Node* current = front;
        while (current != rear) {
            current = current->next;
        }
        return current->data;
    }
    void print() const {
        Node* curr = front;
        cout << "Dipole → ";
        while (curr) {
            cout << curr->data << " → ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

void decimalBinario(int numero){
    Dipole<int> stackD;
    Dipole<int> temp;
    Dipole<int> queueB;

    
    stackD.push(numero);
    int valor = stackD.peek();

    while(valor > 0){
        int bit = valor % 2;
        temp.push(bit);
        valor /= 2;
    }

    while(!temp.empty()){
        queueB.enqueue(temp.peek());
        temp.pop();
    }

    while(!queueB.empty()){
        cout << queueB.peek() << " ";
        queueB.dequeue();
    }
    cout << endl;
}

int main() {
    int numero;

    std::cout << "Ingrese un número decimal: ";
    std::cin >> numero;

    std::cout << "Binario (orden original de bits): ";
    decimalBinario(numero);

    return 0;
}

