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

        void suma(Stack* stack1, Stack* stack2, Stack* stack3){
            bool flagCarry = false;
            while(!stack1->isEmpty() || !stack2->isEmpty() || flagCarry){ 
                int a = 0;
                if (!stack1->isEmpty()) {
                    a = stack1->top();
                    stack1->pop();
                }

                int b = 0;
                if (!stack2->isEmpty()) {
                    b = stack2->top();
                    stack2->pop();
                }

                int s = a + b;

                if(flagCarry){ 
                    s += 1;
                    flagCarry = false;
                }

                if(s > 9) {
                    stack3->push(s - 10);
                    flagCarry = true;
                }
                else {
                    stack3->push(s);
                }
            }
        }
}; 

int main(){
    Stack<int> stack1;
    Stack<int> stack2;
    Stack<int> stack3;

    cout << "Ingrese numeros para Pila 1 (5, 4, 1):" << endl;
    stack1.push(5);
    stack1.push(4);
    stack1.push(1);
    
    cout << "Ingrese numeros para Pila 2 (5, 3, 2):" << endl;
    stack2.push(2);
    stack2.push(3);
    stack2.push(5);

    cout << "Pila 1: ";
    stack1.print();
    cout << "Pila 2: ";
    stack2.print();

    stack3.suma(&stack1, &stack2, &stack3);

    cout << "Pila 1 despues de suma: ";
    stack1.print();
    cout << "Pila 2 despues de suma: ";
    stack2.print();

    cout << "Pila 3 (Resultado): ";
    stack3.print();

    return 0;
}