#include <iostream>
using namespace std;

double max(double num1, double num2, double num3, double num4, double num5) {
    int max = INT_MIN;
    if(max < num1) max = num1;
    if(max < num2) max = num2;
    if(max < num3) max = num3;
    if(max < num4) max = num4;
    if(max < num5) max = num5;
    return max;
}

int main () {
    double num1, num2, num3, num4, num5;
    cin >> num1 >> num2 >> num3 >> num4 >> num5;
    double biggest = max(num1, num2, num3, num4, num5);
    cout << "The biggest number is: " << biggest << endl;
    return 0;
}