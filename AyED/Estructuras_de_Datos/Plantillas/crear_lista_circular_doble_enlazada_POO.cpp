#include <iostream>
using namespace std;

template <typename T>
class CDLList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& d = T(), Node* p = nullptr, Node* n = nullptr)
            : data(d), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;
    int   size;

    void insertAfter(Node* pos, const T& value) {
        Node* newNode = new Node(value, pos, pos->next);
        pos->next->prev = newNode;
        pos->next = newNode;
        ++size;
    }

public:
    CDLList() : size(0) {
        head = new Node(); 
        tail = new Node(); 
        head->next = tail;
        tail->prev = head;
    }

    ~CDLList() {
        clear();
        delete head;
        delete tail;
    }

    bool empty() const { return size == 0; }
    int Size() const { return size; }

    void clear() {
        Node* curr = head->next;
        while (curr != tail) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void push_front(const T& value) { insertAfter(head, value); }

    void push_back(const T& value) { insertAfter(tail->prev, value); }

    T pop_front() {
        if (empty()) throw runtime_error("pop_front en CDLLista vacía");
        Node* node = head->next;
        T val = node->data;
        head->next = node->next;
        node->next->prev = head;
        delete node;
        --size;
        return val;
    }

    T pop_back() {
        if (empty()) throw runtime_error("pop_back en CDLLista vacía");
        Node* node = tail->prev;
        T val = node->data;
        tail->prev = node->prev;
        node->prev->next = tail;
        delete node;
        --size;
        return val;
    }

    void remove(Node* target) {
        if (!target || target == head || target == tail) return;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        delete target;
        --size;
    }

    void remove(const T& value) {
        Node* curr = head->next;
        while (curr != tail) {
            if (curr->data == value) {
                remove(curr);
                return;
            }
            curr = curr->next;
        }
    }

    void removeAll(const T& value) {
        Node* curr = head->next;
        while (curr != tail) {
            if (curr->data == value) {
                Node* toDelete = curr;
                curr = curr->next;
                remove(toDelete);
            } else {
                curr = curr->next;
            }
        }
    }

    void insert(const T& value, Node* v) {
        if (!v || v == head->next) {
            push_front(value);
            return;
        }
        insertAfter(v->prev, value);
    }

    Node* getPosition(const T& value) const {
        Node* curr = head->next;
        while (curr != tail) {
            if (curr->data == value) return curr;
            curr = curr->next;
        }
        return nullptr;
    }

    T& front() { return head->next->data; }
    T& back()  { return tail->prev->data; }

    void print() const {
        cout << "head -> ";
        for (Node* curr = head->next; curr != tail; curr = curr->next) {
            cout << curr->data << " <-> ";
        }
        cout << "tail\n";
    }
};

// Ejemplo de uso
int main() {
    CDLList<int> L;

    // push_back
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    cout << "Después de push_back: ";
    L.print();  // 10 <-> 20 <-> 30

    // push_front
    L.push_front(5);
    cout << "Después de push_front(5): ";
    L.print();  // 5 <-> 10 <-> 20 <-> 30

    // pop_front / pop_back
    cout << "pop_front(): " << L.pop_front() << "\n"; // 5
    cout << "pop_back(): "  << L.pop_back()  << "\n"; // 30
    cout << "Ahora: ";
    L.print();  // 10 <-> 20

    // insert antes de 20
    auto p20 = L.getPosition(20);
    L.insert(15, p20);
    cout << "Después de insert(15 antes de 20): ";
    L.print();  // 10 <-> 15 <-> 20

    // remove por valor
    L.remove(15);
    cout << "Después de remove(15): ";
    L.print();  // 10 <-> 20

    // front y back
    cout << "Front: " << L.front()
    << "   Back: "  << L.back() << "\n";

    // clear
    L.clear();
    cout << "Después de clear(): ";
    L.print();  // (vacía)

    return 0;
}