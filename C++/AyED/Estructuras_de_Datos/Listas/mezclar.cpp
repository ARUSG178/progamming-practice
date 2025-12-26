#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
class List {
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

        bool SwitchOrder(const T &a, const T &b) {
            return a < b;
        }

    void insertOrder(const T &value) {
    Node *current = head->next;
    Node *prev = head;
    
    while(current != tail && SwitchOrder(current->data, value)) {
        prev = current;
        current = current->next;
    }
    
    Node* newNode = new Node(value, current);
    prev->next = newNode;
    }

        void printList(){
            Node* current = head;
            while(current != tail){
                if(current == head) cout << "head -> ";
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "tail" << endl;
        }

        //Método de mezclar
        void mezcla2(List* list1, List* list2) {
            // Limpiar la lista actual (conservando centinelas)
            head->next = tail;
            
            Node* currentL1 = list1->head->next;
            Node* currentL2 = list2->head->next;
            Node* lastAdded = head;  // Comenzamos desde el centinela head, listaEwE
            
            while (currentL1 != list1->tail && currentL2 != list2->tail) {
                if (currentL1->data <= currentL2->data) {
                    // Crear nuevo nodo que apunte a tail
                    Node* newNode = new Node(currentL1->data, tail);
                    // Enlazar el último nodo al nuevo nodo
                    lastAdded->next = newNode;
                    lastAdded = newNode;  // Actualizar último añadido
                    currentL1 = currentL1->next;
                } else {
                    Node* newNode = new Node(currentL2->data, tail);
                    lastAdded->next = newNode;
                    lastAdded = newNode;
                    currentL2 = currentL2->next;
                }
            }
            
            // Añadir elementos restantes de list1
            while (currentL1 != list1->tail) {
                Node* newNode = new Node(currentL1->data, tail);
                lastAdded->next = newNode;
                lastAdded = newNode;
                currentL1 = currentL1->next;
            }
            
            // Añadir elementos restantes de list2
            while (currentL2 != list2->tail) {
                Node* newNode = new Node(currentL2->data, tail);
                lastAdded->next = newNode;
                lastAdded = newNode;
                currentL2 = currentL2->next;
            }
        }
};

int main(){
    srand(time(NULL));

    List<int> listUwU;
    List<int> listOwO;
    int dato;

    for(int i = 0; i < 10; i++){
        dato = rand() % 100;
        listUwU.insertOrder(dato);
    }
    for(int i = 0; i < 10; i++){
        dato = rand() % 100;
        listOwO.insertOrder(dato);
    }

    cout << "Lista UwU | ";
    listUwU.printList();
    cout << "Lista OwO | ";
    listOwO.printList();

    List<int> listEwE;
    listEwE.mezcla2(&listUwU, &listOwO);
    cout << "Lista EwE | ";
    listEwE.printList();
    return 0;
}