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
        
        // Recursivo, qué perro miedo
        void invertir(){}
            
        
}; 