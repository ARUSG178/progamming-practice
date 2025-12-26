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
        
        bool palindrome(Stack* originalStack){ 
            if(originalStack->isEmpty() || originalStack->getSize() == 1) return true;

            Stack* reversed = new Stack<T>();
            Stack* temp = new Stack<T>();

            while(!originalStack->isEmpty()){
                T value = originalStack->top();
                reversed->push(value);
                temp->push(value);
                originalStack->pop();
            }

            while(!temp->isEmpty()){
                originalStack->push(temp->top());
                temp->pop();
            }

            while(!reversed->isEmpty()){
                if(reversed->top() != originalStack->top()){
                    delete reversed;
                    delete temp;
                    return false;
                }
                originalStack->pop();
            }

            delete reversed;
            delete temp;

            return true;
        }
}; 

int main() {
    Stack<int>* s1 = new Stack<int>();
    s1->push(1);
    s1->push(2);
    s1->push(1);
    cout << "Pila s1: "; s1->print();
    cout << "Es palindromo? " << (s1->palindrome(s1) ? "Si" : "No") << endl;

    Stack<int>* s2 = new Stack<int>();
    s2->push(1);
    s2->push(2);
    s2->push(3);
    cout << "\nPila s2: "; s2->print();
    cout << "Es palindromo? " << (s2->palindrome(s2) ? "Si" : "No") << endl;

    Stack<int>* s3 = new Stack<int>();
    s3->push(1);
    s3->push(2);
    s3->push(2);
    s3->push(1);
    cout << "\nPila s3: "; s3->print();
    cout << "Es palindromo? " << (s3->palindrome(s3) ? "Si" : "No") << endl;

    Stack<int>* s4 = new Stack<int>();
    cout << "\nPila s4: "; s4->print();
    cout << "Es palindromo? " << (s4->palindrome(s4) ? "Si" : "No") << endl;

    Stack<int>* s5 = new Stack<int>();
    s5->push(7);
    cout << "\nPila s5: "; s5->print();
    cout << "Es palindromo? " << (s5->palindrome(s5) ? "Si" : "No") << endl;

    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;

    return 0;
}