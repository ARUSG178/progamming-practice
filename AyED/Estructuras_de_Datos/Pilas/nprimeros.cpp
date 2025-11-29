#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack{
    private:
        struct Node{
            T data;
            Node* next;
            Node(const T& d, Node* nxt = nullptr) : data(d), next(nxt) {}
        }; 

        Node* topNode;
        int count;
    public:
        Stack() : topNode(nullptr), count(0) {}
        ~Stack(){
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
                throw runtime_error("stack vacía");
            }
            Node* toDelete = topNode;
            topNode = topNode->next;
            delete toDelete;
            count--;
        }

        T top(){
            if(isEmpty()){
                throw runtime_error("stack vacia");
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
                if(current == topNode) cout << "topNode -> ";
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "null" << endl;
        }

        int suma(int n){
            if (n < 0 || n > getSize()) {
                throw out_of_range("Error: n esta fuera del rango de elementos de la pila.");
            }

            Stack<T>* temp = new Stack<T>();

            int elementsToPopFromTop = getSize() - n;
            for(int i = 0; i < elementsToPopFromTop; i++){
                temp->push(top());
                pop();
            }

            int totalSum = 0;
            while(!isEmpty()){
                totalSum += top();
                temp->push(top());
                pop();
            }

            while(!temp->isEmpty()){
                push(temp->top());
                temp->pop();
            }
            
            delete temp; 

            return totalSum;
        }    
        
        
}; 

int main() {
    // Declara e inicializa punteros a Stack
    Stack<int>* myStack = new Stack<int>();
    myStack->push(10); // Fondo
    myStack->push(20);
    myStack->push(30);
    myStack->push(40);
    myStack->push(50); // Tope (topNode -> 50 -> 40 -> 30 -> 20 -> 10 -> null)

    cout << "Pila original: ";
    myStack->print(); 

    // Sumar los 3 elementos del fondo (10, 20, 30)
    int n_elements_to_sum = 3;
    try {
        // Llama a suma en el objeto apuntado por myStack
        int sum_result = myStack->suma(n_elements_to_sum);
        cout << "Suma de los " << n_elements_to_sum << " elementos desde el fondo: " << sum_result << endl; // Esperado: 10+20+30=60
        cout << "Pila despues de la suma: ";
        myStack->print(); // Debería estar intacta
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "\n--- Segundo Ejemplo (n=0) ---" << endl;
    Stack<int>* anotherStack = new Stack<int>();
    anotherStack->push(100);
    anotherStack->push(200);
    cout << "Pila original: ";
    anotherStack->print();
    try {
        int sum_zero = anotherStack->suma(0);
        cout << "Suma de 0 elementos desde el fondo: " << sum_zero << endl; // Esperado: 0
        cout << "Pila despues de la suma: ";
        anotherStack->print(); // Debería estar intacta
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "\n--- Tercer Ejemplo (n=total de elementos) ---" << endl;
    Stack<int>* fullSumStack = new Stack<int>();
    fullSumStack->push(1);
    fullSumStack->push(2);
    fullSumStack->push(3);
    cout << "Pila original: ";
    fullSumStack->print();
    try {
        // Aquí n es igual al getSize() de la pila, lo que suma todos los elementos.
        // La función suma maneja esto correctamente: getSize() - n = 0, así que no se descarta nada.
        int sum_all = fullSumStack->suma(fullSumStack->getSize()); 
        cout << "Suma de todos los elementos: " << sum_all << endl; // Esperado: 1+2+3=6
        cout << "Pila despues de la suma: ";
        fullSumStack->print(); // Debería estar intacta
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "\n--- Cuarto Ejemplo (n invalido) ---" << endl;
    Stack<int>* invalidNStack = new Stack<int>();
    invalidNStack->push(5);
    cout << "Pila original: ";
    invalidNStack->print();
    try {
        invalidNStack->suma(5); // n=5, getSize()=1. Esto lanzará un error.
    } catch (const out_of_range& e) {
        cerr << "Capturado error esperado: " << e.what() << endl;
    }
    cout << "Pila despues del error (deberia estar intacta): ";
    invalidNStack->print(); // Estará intacta ya que la excepción se lanza antes de modificarla.

    // Liberar la memoria asignada con 'new'
    delete myStack;
    delete anotherStack;
    delete fullSumStack;
    delete invalidNStack;

    return 0;
}