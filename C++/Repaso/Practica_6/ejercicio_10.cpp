#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(const vector<vector<int>> &M) {
    int n = M.size();
    int m = M[0].size();
    
    vector<vector<int>> T(m, (vector<int>(n, 0)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            T[i][j] = M[j][i] ;
        }
    }

    return T;
}

int main () {
    int n, m;
    cout << "Enter the dimensions (n -> m): ";
    cin >> n >> m;

    vector<vector<int>> M(n, vector<int>(m, 0));

    // llenar la matriz con ejemplo (i+j)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            M[i][j] = i + j;
        }
    }

    // mostrar matriz original
    cout << "Original matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    // obtener traspuesta
    vector<vector<int>> T = transpose(M);

    // mostrar traspuesta
    cout << "Transposed matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
