#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node (int v) : data(v), left(nullptr), right(nullptr) {}
};

void inOrderInterative(Node* root){
    stack<Node*> pila;
    Node* current = root;

    while(current || !pila.empty()) {

        while(current) {
            pila.push(current);
            current->left;
        }

        current = pila.top();
        pila.pop();
        cout << current->data << " ";

        current = current->right;
    }
}