#include <iostream>
#include <vector>
using namespace std;

template <typename T>

void swapEvenOddRows(vector<vector<T>> &mat) {
    int n = mat.size();
    for(int i = 0; i < n; i += 2) swap(mat[i], mat[i+1]); 
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    swapEvenOddRows(mat);

    cout << "Matriz resultante:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}