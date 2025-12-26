#include <iostream>
using namespace std;

double calculus(int n){
    int pi = 0;
    bool flag = false;
    for (int i = 1; i <= n; i += 2){
       if(flag) pi = -4/i;
       else pi = 4/i;
       !flag;
    }

    return pi;
}

int main() {
    int n;
    
    cout << "Enter the limits of the secuence: ";
    cin >> n;

    cout << "The result is: " << calculus << endl;

    return 0;
}