#include <iostream>
using namespace std;

double triangle (double base, double height){
    return base * height;
}

int main(){

    double base, height;
    cin >> base >> height;
    
    double area = triangle(base, height);
    cout << area << endl;

    return 0;
}