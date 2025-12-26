#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* nxt = nullptr) : data(d), next(nxt) {}
    }; 

    Node* topNode;
    int count;

public:
    Stack() : topNode(nullptr), count(0) {}
    ~Stack() {
        while(!isEmpty()){
            pop();
        }
        topNode = nullptr;
        count = 0;
    }
    
    void push(const T &value){
        topNode = new Node(value, topNode);
        count++;
    }
    void pop(){
        if(isEmpty()){
            throw std::runtime_error("stack vacía");
        }
        Node* toDelete = topNode;
        topNode = topNode->next;
        delete toDelete;
        count--;
    }

    T top(){
        if(isEmpty()){
            throw std::runtime_error("stack vacia");
        }
        return topNode->data;
    }

    int getSize() const {
        return count;
    }

    bool isEmpty() const{
        return topNode == nullptr;
    }

    void print(){
        Node* current = topNode;
        while(current != nullptr){
            if(current == topNode) std::cout << "topNode -> ";
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "null" << std::endl;
    }

    double calcularPromedio() {
        if (isEmpty()) {
            return 0.0; // Retorna 0.0 para una pila vacía según esta simplificación.
        }

        double suma_total = 0.0;
        int contador_elementos = 0;

        while (!isEmpty()) {
            suma_total += top();
            pop();
            contador_elementos++;
        }
        
        return suma_total / contador_elementos;
    }
};

int main() {
    Stack<int> pila1;
    pila1.push(10);
    pila1.push(20);
    pila1.push(30);
    pila1.push(40);
    pila1.push(50); 

    std::cout << "Pila 1 original: ";
    pila1.print(); 

    double promedio1 = pila1.calcularPromedio();
    std::cout << "Promedio de los elementos de Pila 1: " << promedio1 << std::endl; 
    std::cout << "Pila 1 despues de calcular promedio: ";
    pila1.print(); 

    std::cout << "\n--- Segundo Ejemplo ---" << std::endl;
    Stack<int> pila2;
    pila2.push(77); 

    std::cout << "Pila 2 original: ";
    pila2.print();
    double promedio2 = pila2.calcularPromedio();
    std::cout << "Promedio de los elementos de Pila 2: " << promedio2 << std::endl; 
    std::cout << "Pila 2 despues de calcular promedio: ";
    pila2.print(); 

    std::cout << "\n--- Tercer Ejemplo ---" << std::endl;
    Stack<int> pila3; 

    std::cout << "Pila 3 original: ";
    pila3.print();
    double promedio3 = pila3.calcularPromedio();
    std::cout << "Promedio de los elementos de Pila 3: " << promedio3 << std::endl; 
    std::cout << "Pila 3 despues de calcular promedio: ";
    pila3.print(); 

    std::cout << "\n--- Cuarto Ejemplo ---" << std::endl;
    Stack<double> pila4;
    pila4.push(1.5);
    pila4.push(2.5);
    pila4.push(3.0);
    std::cout << "Pila 4 original: ";
    pila4.print();
    double promedio4 = pila4.calcularPromedio();
    std::cout << "Promedio de los elementos de Pila 4: " << promedio4 << std::endl; 
    std::cout << "Pila 4 despues de calcular promedio: ";
    pila4.print(); 

    return 0;
}