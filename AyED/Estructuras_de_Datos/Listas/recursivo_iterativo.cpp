#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* nxt = nullptr) : data(d), next(nxt) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    List() : size(0) {
        tail = new Node(T());
        head = new Node(T(), tail);
    }

    ~List() {
        Clear();
        delete head;
        delete tail;
    }

    void Clear() {
        Node* current = head;
        while (current != tail && current != nullptr) {
            Node* aux = current;
            current = current->next;
            delete aux;
        }
        head->next = tail;
        size = 0;
    }

    void remove(Node* nodeD) {
        Node* current = head;
        while (current->next != nodeD && current->next != nullptr) {
            current = current->next;
        }
        if (current->next == nodeD) {
            current->next = nodeD->next;
            delete nodeD;
            size--;
        }
    }

    Node* first() {
        return (head->next != tail) ? head->next : nullptr;
    }

    Node* last() const {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        return current != head ? current : nullptr;
    }

    Node* next(Node* node) {
        return (node && node->next != tail) ? node->next : nullptr;
    }

    T& getData(Node* node) {
        return node->data;
    }

    Node* getPosition(const T& value) const {
        Node* curr = head->next;
        while (curr != tail) {
            if (curr->data == value) return curr;
            curr = curr->next;
        }
        return nullptr;
    }

    void insertFront(const T& value) {
        Node* newNode = new Node(value, head->next);
        head->next = newNode;
        size++;
    }

    void insertBack(const T& value) {
        Node* aux = head;
        while (aux->next != tail) {
            aux = aux->next;
        }
        Node* newNode = new Node(value, tail);
        aux->next = newNode;
        size++;
    }

    int getSize() {
        return size;
    }

    void printList() {
        Node* current = head;
        while (current != tail) {
            if (current == head) cout << "head -> ";
            else cout << current->data << " -> ";
            current = current->next;
        }
        cout << "tail" << endl;
    }

    void invertIterative() {
        Node* prev = nullptr;
        Node* current = head->next;
        Node* next = nullptr;

        while (current != tail) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        Node* firstReal = head->next;
        firstReal->next = tail;
        head->next = prev;
    }

    void invertRecursive() {
        if (!head->next || head->next == tail) return;
        Node* firstReal = head->next;
        Node* newFirst = invertRecursiveHelper(firstReal);
        firstReal->next = tail;
        head->next = newFirst;
    }

private:
    Node* invertRecursiveHelper(Node* node) {
        if (node->next == tail)
            return node;

        Node* rest = invertRecursiveHelper(node->next);
        node->next->next = node;
        return rest;
    }
};

int main() {
    List<int> miLista;

    // Insertamos elementos
    miLista.insertBack(1);
    miLista.insertBack(2);
    miLista.insertBack(3);
    miLista.insertBack(4);
    miLista.insertBack(5);

    cout << "Lista original:\n";
    miLista.printList();  // head -> 1 -> 2 -> 3 -> 4 -> 5 -> tail

    // Inversión iterativa
    miLista.invertIterative();
    cout << "\nDespués de invertir (iterativa):\n";
    miLista.printList();  // head -> 5 -> 4 -> 3 -> 2 -> 1 -> tail

    // Inversión recursiva
    miLista.invertRecursive();
    cout << "\nDespués de invertir (recursiva):\n";
    miLista.printList();  // head -> 1 -> 2 -> 3 -> 4 -> 5 -> tail

    // Eliminar un valor
    auto nodo3 = miLista.getPosition(3);
    if (nodo3) {
        miLista.remove(nodo3);
        cout << "\nDespués de eliminar el nodo con valor 3:\n";
        miLista.printList();  // head -> 1 -> 2 -> 4 -> 5 -> tail
    }

    // Borrar todo
    miLista.Clear();
    cout << "\nDespués de limpiar la lista:\n";
    miLista.printList();  // head -> tail

    return 0;
}