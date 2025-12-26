#include <iostream>
using namespace std;

double interceptionPoint(double m1, double m2, double b1, double b2){
    return (b2 - b1) / (m1 - m2);
}

int main(){
    double m1, m2, b1, b2, x;

    cout << "Enter the values of the firts ecuation [m,b]: ";
    cin >> m1 >> b1;

    cout << "Enter the values of the firts ecuation [m,b]: ";
    cin >> m2 >> b2;

    double x = interceptionPoint(m1, m2, b1, b2);

    return 0;
}