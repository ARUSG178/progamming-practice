#include <iostream>
using namespace std;

void printDomino() {
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            cout << i << "/" << j << endl;
        }
    }
}

int main() {
    printDomino();

    return 0;
}