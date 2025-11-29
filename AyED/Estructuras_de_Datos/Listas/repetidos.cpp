#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

template <typename T>
class List{
    private:
        struct Node{
            T data;
            Node* next;
            Node(const T &d, Node* nxt = nullptr) data(d) next(nxt) {}
        }

        Node* head;
        Node* tail;
    public:

        List(){
            tail = new Node(T());
            head = new Node(T(), tail);
        }
            
        ~List() {
            Clear();                         
            delete head;                      
            delete tail;                      
        }
        
        void Clear() {
            Node* current = head->next;
            while(current != tail) {            
                Node* aux = current;
                current = current->next;
                delete aux;                    
            }
            head->next = tail;  
            size = 0;
        }

        void printList(){
            Node* current = head;                           
            while(current != tail){                 
                if(current == head) cout << "head -> ";     
                else cout << current->data << " -> ";       
                current = current->next;                    
            }
            cout << "tail" << endl;                         
        }

        void deleteRepeated(List* L1){
            Node*current = head->next;
            while(current->next != tail){
                Node*aux = current->next;
                while(aux != tail){
                    if(aux->data == current->data){
                        Node* dead = aux;
                        aux = aux->next
                        delete dead;
                    }
                    else aux = aux->next;
                }
                current = current->next;
            } 
        }
};
