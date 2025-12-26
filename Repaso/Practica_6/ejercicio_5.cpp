#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void insertK(vector<int> &A, int K) {
    for(int i = 0; i < A.size(); i++) {
        int pos = (1 << i) - 1; //desplazamiento
        A[pos] = K;
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

    cout << "Insert which number you want to insert: ";
    cin >> K;

    insertK(array, K);

    for(int j : array) cout << j << " ";
    cout << endl;

    return 0;
}