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
    int count;     // Contador de elementos

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr), count(0) {}
    // Constructor de copys
    Queue(const Queue<T>& other) : front(nullptr), rear(nullptr), count(0) {
        Node* current = other.front;
        while (current != nullptr) {
        enqueue(current->data);  // reutiliza tu propio método para iertar
        current = current->next;
        }
    }

    // Destructor
    ~Queue() {
        clear();
    }

    //Operador copyr una cola a otra
    Queue<T>& operator=(const Queue<T>& other) {
        if (this != &other) {
            clear();

            Node * current = other.head();
            while (current != nullptr) {
                enqueue(current->data);
                current = current->next;
                return *this;
            }
        }
    }

    // Vacía la cola
    void clear() {
        while (!empty()) {
            dequeue();
        }
    }

    // Verifica si está vacía
    bool empty() const {
        return count == 0;
    }

    // Agrega elemento al final
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

    // Elimina el elemento del frente
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
    int Size() const {
        return count;
    }

    // Acceso al elemento frente
    T head() const {
        if (empty()) {
            throw out_of_range("Cola vacía");
        }
        return front->data;
    }

    void Print() {
        Queue<T> copy(*this);  // copia profunda usando constructor de copia
        cout << "front -> ";
        while (!copy.empty()) {
            cout << copy.head() << " -> ";
            copy.Dequeue();
        }
        cout << "null" << endl;
    }

    void invertPrint() {
        stack<T> stack;
        Queue<T> copy(*this);

        while(!copy.empty()) {
            stack.push(copy.head());
            copy.dequeue();
        }

        cout << "rear -> ";
        while(!stack.empty()) {
            cout << stack.top() << " -> ";
            stack.pop();
        }
        cout << "null";

    }

    double average() {
        Queue<T> copy(*this);
        double avrg = 0;
        while(!copy.empty()) {
            avrg += copy.head();
            copy.dequeue();
        }
        return avrg /= size();
        }
};

int main() {
    Queue<int> q;

    // Insertar elementos
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);

    std::cout << "\n📤 Contenido de la cola:\n";
    q.Print();  // front -> 5 -> 10 -> 15 -> 20 -> null

    std::cout << "\n🔁 Cola en orden inverso:\n";
    q.invertPrint();  // rear -> 20 -> 15 -> 10 -> 5 -> front

    std::cout << "\n📊 Promedio de la cola: ";
    std::cout << q.average() << "\n";  // (5+10+15+20)/4 = 12.5

    std::cout << "\n⛔ Desencolando dos elementos...\n";
    q.dequeue();
    q.dequeue();

    std::cout << "\n📤 Cola actualizada:\n";
    q.Print();  // front -> 15 -> 20 -> null

    std::cout << "\n📊 Nuevo promedio: ";
    std::cout << q.average() << "\n";  // (15+20)/2 = 17.5

    return 0;
}