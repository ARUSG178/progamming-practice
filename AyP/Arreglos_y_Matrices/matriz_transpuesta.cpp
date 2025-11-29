#include <iostream>
#include <ctime>
using namespace std;

int** matrizTraspuesta(int** matriz, int N, int M) {
    int** matrizTrans = new int*[M];
    for (int i = 0; i < M; i++) {
        matrizTrans[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrizTrans[j][i] = matriz[i][j];
        }
    }

    return matrizTrans;
}

int main() {
    srand(time(NULL));
    int N, M;
    cin >> N >> M;

    int** matriz = new int*[N];
    for (int i = 0; i < N; i++) {
        matriz[i] = new int[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matriz[i][j] = rand() % 10 + 1;
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    int** matrizTrans = matrizTraspuesta(matriz, N, M);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrizTrans[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    for (int i = 0; i < M; i++) {
        delete[] matrizTrans[i];
    }
    delete[] matrizTrans;

    return 0;
}