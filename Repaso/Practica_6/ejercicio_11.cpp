#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T antiDiagonalSum(const vector<vector<T>> &uwu) {
    T sum = 0;
    int n = uwu.size();
    int m = uwu[0].size();

    for(int i = 0; i < n; i++){
        int j = m - 1 - i;  
        sum += uwu[i][j];
    }
    return sum;
}

int main () {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> uwu(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> uwu[i][j];
        }
    }

    int sum = antiDiagonalSum(uwu);
    cout << sum << endl;

    return 0;
}