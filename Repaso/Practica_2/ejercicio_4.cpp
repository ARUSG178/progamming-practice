#include <iostream>
using namespace std;

bool haveSolution(int x) {
    if (x < 0) return true;
    else return false;
}

int main () {
    int A, B, C;
    cout << "Enter values [A, B, C]" << endl;

    int discriminant = (B*B) - (4*A*C);

    if(haveSolution(discriminant)) {
        int fSolution = (-B + discriminant)/2*A;
        int sSolution = (-B - discriminant)/2*A;
        cout << "fisrt solution " << fSolution << endl;
        cout << "second soluton" << sSolution << endl;
    }
    else cout << "the ecuation doesn't have solution";
    
    return 0;
}