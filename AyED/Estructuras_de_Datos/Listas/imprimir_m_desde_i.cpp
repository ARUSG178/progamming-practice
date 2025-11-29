#include <iostream>
using namespace std;

template <typename T>
class List{
    private:
        struct Node{
            T data;
            Node* next;
            // Constructor
            Node(const T &d, Node* n = nullptr) : data(d), next(n) {}
        };

        Node*  head;
        Node* tail;

    public: 
        List(){
            tail = new Node(T());
            head = new Node (T(), tail);
        }
        
        ~List(){
            clear();
            delete head;
            delete tail;
        }

        void clear(){
            Node* current = head->next;
            while(current != tail){
                Node* aux = current;
                current = current->next;
                delete aux;
            }
            head->next = tail;
        }

        void insertBack(const T &value) {
            Node* lastReal = head;
            while(lastReal->next != tail){
                lastReal = lastReal->next;
            }

            Node* newNode = new Node(value, tail);
            lastReal->next = newNode;
            newNode->next = tail;
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
        // Imprimir m valores desde la posición i
        void printCondicional(int m, int i){
            Node* current = head -> next;
            for(int j = 0; j < i; j++){
                current = current->next;
            }
            for(int j = 0; j < m; j++){
                if (j == 0) cout << "head -> " << current->data << " -> ";
                else if (j == m-1) cout << current->data << " -> tail" << endl;
                else cout << current->data << " -> ";
                current = current->next;
            }
            cout << endl;
        }
    
};

int main(){
    List<char> listCulo;
    while(true){
        char c;
        cout << "Insert a char (ñ to exit): ";
        cin >> c;
        if (c == 'z') break;
        listCulo.insertBack(c);
    }
    cout << "List | ";
    listCulo.printList();
    listCulo.printCondicional(8, 5);

    return 0;
}