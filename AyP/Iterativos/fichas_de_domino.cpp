#include <iostream>
using namespace std;

int main(){

    int i, j;

    cout << "\n";

    for(i = 1; i <= 6; i++){
        for(j = 1; j <= 6; j++){
            cout << i << "/" << j;
            (j <= 5) ? cout << ", "  : cout << "." << endl;
        }
    }

    cout << "\n";

    system ("pause");
    return 0;
}