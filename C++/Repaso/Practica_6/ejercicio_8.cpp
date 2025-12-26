#include <iostream>
#include <vector>
using namespace std;

bool sumK(vector<int> A, int K) {
    int firtsComp = 0;
    for(int i = 0; i < A.size(); i++) {
        firtsComp = A[i];
        for(int j = 0; j < A.size(); j++) {
            if ((firtsComp + A[j]) == K) return true;
        }
    }
    return false;
}

int main() {
    vector<int> A;
    int x, quantity, K;

    cout << "Insert quantity: ";
    cin >> quantity;

     for(int i = 0; i < quantity; i++) {
        cin >> x;
        A.push_back(x);
     }

    cout << "Insert target sum K: ";
    cin >> K;

    if (sumK(A, K)) cout << "There exists a pair that sums to " << K << endl;
    else cout << "No pair sums to " << K << endl;
    
    return 0;

}