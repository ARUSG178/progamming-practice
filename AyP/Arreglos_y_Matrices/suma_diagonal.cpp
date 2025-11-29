#include <iostream>
#include <ctime>
using namespace std;

int sumaDiagonal(int **matriz, int N, int M){
    int sumatoria = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i + j == N - 1 && i < M && j < N) {
                sumatoria += matriz[i][j];
            }
        }
    }
    return sumatoria;
}

int main(){
    srand(time(NULL));
    int N, M;
    cin >> N >> M;

    int **matriz = new int*[N];
    for (int i = 0; i < N; i++) {
        matriz[i] = new int[M];
        for (int j = 0; j < M; j++) {
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            matriz[i][j] = rand() % 8 + 1;
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    int sumaD = sumaDiagonal(matriz, N, M);
    cout << "\n" << sumaD << endl;

    for(int i = 0; i < N; i++){
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}