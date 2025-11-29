#include <iostream>
#include <stdexcept> // Para std::runtime_error, usado en errores de pila vacía

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* nxt = nullptr) : data(d), next(nxt) {} // Constructor de un nodo
    };

    Node* topNode; // Puntero al elemento superior de la pila
    int count;     // Número de elementos en la pila

public:
    Stack() : topNode(nullptr), count(0) {} // Constructor: inicializa una pila vacía

    ~Stack() {
        clear(); // Destructor: libera la memoria de todos los nodos
    }

    void clear() {
        while (topNode != nullptr) { // Elimina todos los elementos de la pila
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
        count = 0;
    }

    void push(const T& value) {
        Node* newNode = new Node(value, topNode);       // Crea un nuevo nodo y lo enlaza al actual top
        topNode = newNode;                              // El nuevo nodo se convierte en el top
        count++;                                        // Incrementa el tamaño
    }

    void pop() {
        if (isEmpty()) { // Verifica si la pila está vacía antes de intentar sacar un elemento
            throw std::runtime_error("Error: Intentando pop de una pila vacia.");
        }
        Node* toDelete = topNode;           // Guarda el nodo actual para eliminarlo
        topNode = topNode->next;            // El siguiente nodo se convierte en el nuevo top
        delete toDelete;                    // Libera la memoria del nodo anterior
        count--;                            // Decrementa el tamaño
    }

    T top() {
        if (isEmpty()) { // Verifica si la pila está vacía antes de acceder al top
            throw runtime_error("Error: Intentando acceder al top de una pila vacia.");
        }
        return topNode->data; // Retorna el dato del elemento superior
    }

    // Retorna el número de elementos
    int getSize() const { 
        return count;
    }

    // Verifica si la pila está vacía
    bool isEmpty() const { 
        return count == 0;
    }

    // Imprime la pila
    void print(){
        Node* current = top;
        while(current != nullptr){
            if(current == top) cout << "top -> "
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
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