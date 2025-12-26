#include <iostream>
#include <vector>
using namespace std;

int mostRepeated(vector<int> A, int q){
    vector<int> repeats(101, 0);

    for(int x : A) repeats[x]++;

    int most = -1;
    int value = -1;

    for(auto &elem: repeats) {
        if(most < elem) {
            most = elem;
            value = elem;
        }
    }
    
    return value;
}

int main() {
    vector<int> A;
    int x, quantity;

    cout << "Insert quantity: ";
    cin >> quantity;

    for(int i = 0; i < quantity; i++) {
        cout << "Enter values between 0 and 100 (inclusive): ";
        cin >> x;
        while(x < 0 || x > 100) {
            cout << "Invalid. Please enter again.\n";
            cin >> x;
        }
        A.push_back(x);
    }

    int mRepeated = mostRepeated(A, quantity);

    cout << "The most repeated number is : " << mRepeated << endl;

    return 0;
}