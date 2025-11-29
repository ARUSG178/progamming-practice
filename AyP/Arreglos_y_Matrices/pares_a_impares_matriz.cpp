#include <iostream>
#include <ctime>
using namespace std;

void ParesAImpares(int **matriz, int N, int M){
    int aux;
    for(int i = 0; i <= N - 2; i += 2){
        for(int j = 0; j < M; j++){
            aux = matriz[i][j];
            matriz[i][j] = matriz[i + 1][j];
            matriz[i + 1][j] = aux;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){
    srand((unsigned int)time(NULL));
    int N, M;
    cin >> N >> M;

    int **matriz = new int*[N];
    for (int i = 0; i < N; i++) {
        matriz[i] = new int[M];
        for (int j = 0; j < M; j++) {
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matriz[i][j] = rand() % 20 + 1;
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    ParesAImpares(matriz, N, M);

    system("pause");
    return 0;
}