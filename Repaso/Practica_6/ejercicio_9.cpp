#include <iostream>
#include <vector>
using namespace std;

void newVector(vector<int> A, vector<int> B, vector<int> &C) {
    int i = 0, j = 0, k = 0;

    while(i < A.size() && j < B.size()) {
        if(A[i] > B[j]) C[k++] = A[i++];
        else C[k++] = B[j++];
    }

    while (i != A.size()) C[k++] = A[i++];
    while (j != B.size()) C[k++] = B[j++];
}

int main() {
    // Ejemplo de entrada
    vector<int> A = {9, 7, 5};
    vector<int> B = {8, 6, 4};

    // C tendrá tamaño A.size() + B.size(), inicializado en 0
    vector<int> C(A.size() + B.size(), 0);

    // Llamada a la función
    newVector(A, B, C);

    // Mostrar resultado
    cout << "Vector C: ";
    for (int x : C) cout << x << " ";
    cout << endl;

    return 0;
}
