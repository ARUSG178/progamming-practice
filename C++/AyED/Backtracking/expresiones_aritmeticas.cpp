#include <iostream>
using namespace std;

int aplicar(int a, int b, char op) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    if(op == '/') return (b != 0) ? a / b : 0;
    return 0;
}

void backtrack(int* arr, char* ops, int n, int idx, int resultado, int R) {
    if(idx == n - 1) {
        if(resultado == R) {
            if (ops[0] == '+') {
                cout << "+";
            } else if (ops[0] == '-') {
                cout << "-";
            }
            cout << arr[0];
            for(int i = 1; i < n; i++) {
                cout << " " << ops[i] << arr[i];
            }
            cout << " = " << R << endl;
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        char op = "+-*/"[i];
        ops[idx + 1] = op;
        int nuevo = aplicar(resultado, arr[idx + 1], op);
        backtrack(arr, ops, n, idx + 1, nuevo, R);
    }
}

int main() {
    int N, R;
    cout << "Ingrese el número de elementos: ";
    cin >> N >> R;

    int* arr = new int[N];
    char* ops = new char[N];
    for(int i = 0; i < N; i++) arr[i] = i + 1;

    ops[0] = '+';
    backtrack(arr, ops, N, 0, arr[0], R);
    ops[0] = '-';
    backtrack(arr, ops, N, 0, -arr[0], R);

    delete[] arr;
    delete[] ops;
    return 0;
}