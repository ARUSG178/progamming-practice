#include <iostream>
#include <vector>
using namespace std;

void moving(vector<int> &A, int K) {
    for(int i = 0; i < K; i++) {
        int aux = A.front();
        for(int j = 0; j < A.size() - 1; j++) {
            A[i] = A[i + 1];
        }
        A.back() = aux;
    }
}

int main() {
    vector<int> array;
    int x, quantity, K;

    cout << "Enter the quantity: ";
    cin >> quantity;

    for(int i = 0; i < quantity; i++) {
        cin >> x;
        array.push_back(x);
    }

    cout << "Insert the times that the array will be moving to the left: ";
    cin >> K;

    moving(array, K);

    for(int j : array) cout << j << " ";
    cout << endl;

    return 0;
}