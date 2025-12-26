#include <iostream>
#include <stdexcept> // Incluye la librería para el manejo de excepciones (runtime_error).

using namespace std;

template <typename T> // Define una plantilla para que la pila acepte cualquier tipo de dato (int, float, etc.).
class Stack {
private:
    struct Node {
        T data;     // El valor que almacena el nodo.
        Node* next; // Puntero que guarda la dirección del nodo que está "debajo" en la pila.
        
        // Constructor del nodo: asigna el valor y conecta con el siguiente nodo.
        Node(const T& d, Node* nxt = nullptr) : data(d), next(nxt) {} 
    };

    Node* topNode; // Puntero principal que siempre apunta al nodo superior (la cima).
    int count;     // Contador entero para llevar el control del tamaño sin recorrer la pila.

public:
    // Constructor de la pila: inicializa el puntero en nulo y el contador en cero.
    Stack() : topNode(nullptr), count(0) {} 

    // Destructor: se ejecuta automáticamente al final para limpiar toda la memoria dinámica.
    ~Stack() {
        clear(); 
    }

    void clear() {
        // Mientras el puntero de la cima no sea nulo, sigue borrando.
        while (topNode != nullptr) { 
            Node* temp = topNode;    // Guarda la dirección del nodo actual para no perderla.
            topNode = topNode->next; // Mueve la cima al nodo de abajo.
            delete temp;             // Libera la memoria física del nodo que acabamos de "saltar".
        }
        count = 0; // Reinicia el contador a cero tras vaciar todo.
    }

    void push(const T& value) {
        // Crea un nuevo nodo en memoria; su 'next' apuntará al actual topNode.
        Node* newNode = new Node(value, topNode); 
        topNode = newNode; // El nuevo nodo pasa a ser oficialmente la nueva cima.
        count++;           // Incrementa el tamaño de la pila.
    }

    void pop() {
        if (isEmpty()) { // Validación de seguridad: no puedes sacar nada de una pila vacía.
            throw std::runtime_error("Error: Intentando pop de una pila vacia.");
        }
        Node* toDelete = topNode; // Marcamos el nodo de arriba para morir.
        topNode = topNode->next;  // La cima ahora es el que estaba debajo.
        delete toDelete;          // Borramos físicamente el nodo de la memoria.
        count--;                  // Decrementamos el tamaño.
    }

    T top() {
        if (isEmpty()) { // Validación: si está vacía, no hay dato que retornar.
            throw runtime_error("Error: Intentando acceder al top de una pila vacia.");
        }
        return topNode->data; // Retorna el valor guardado en el nodo de la cima.
    }

    // Retorna el valor actual de 'count' (complejidad O(1), muy rápido).
    int getSize() const { 
        return count;
    }

    // Retorna verdadero si count es 0, falso si tiene elementos.
    bool isEmpty() const { 
        return count == 0;
    }

    void print() {
        Node* current = topNode; // Empezamos el recorrido desde la cima.
        while (current != nullptr) { // Mientras no lleguemos al fondo (null).
            if (current == topNode) cout << "top -> "; // Marca visual para la cima.
            cout << current->data << " -> ";           // Imprime el dato del nodo actual.
            current = current->next;                   // Salta al siguiente nodo hacia abajo.
        }
        cout << "null" << endl; // Indica el final de la pila.
    }
};

int main() {
    Stack<int> myStack;

    std::cout << "Pila vacia? " << (myStack.isEmpty() ? "Si" : "No") << std::endl;
    std::cout << "Tamano de la pila: " << myStack.getSize() << std::endl;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Despues de push, tamano: " << myStack.getSize() << std::endl;
    std::cout << "Elemento superior: " << myStack.top() << std::endl;

    try {
        std::cout << "Haciendo pop: " << myStack.top() << std::endl; // Muestra antes de pop
        myStack.pop();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "Nuevo elemento superior: " << myStack.top() << std::endl;

    myStack.push(40);
    std::cout << "Despues de push 40, elemento superior: " << myStack.top() << std::endl;

    try {
        std::cout << "Haciendo pop: " << myStack.top() << std::endl;
        myStack.pop();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        std::cout << "Haciendo pop: " << myStack.top() << std::endl;
        myStack.pop();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        std::cout << "Haciendo pop: " << myStack.top() << std::endl;
        myStack.pop();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    

    std::cout << "Pila vacia? " << (myStack.isEmpty() ? "Si" : "No") << std::endl;
    std::cout << "Tamano de la pila: " << myStack.getSize() << std::endl;

    try {
        myStack.pop();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        myStack.top();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}