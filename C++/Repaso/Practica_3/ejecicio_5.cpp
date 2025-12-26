#include <iostream>
using namespace std;

bool inTheInterval(double V1, double V2, double X){
    return (X >= V1 && X <= V2);
}

int main(){
    double V1, V2, X;

    cout << "Enter the values that limit the interval [and V1 < V2]: ";
    cin >> V1 >> V2;

    cout << "Enter the value of X: ";
    cin >> X;

    if(inTheInterval(V1, V2, X)) cout << "X is in the interval" << endl;
    else cout << "X isn't in the interval" << endl;

    return 0;
}