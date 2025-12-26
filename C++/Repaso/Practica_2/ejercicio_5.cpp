#include <iostream>
#include <cmath>
using namespace std;

int B2D (int d1, int d2, int d3, int d4) {
    return (d1 * pow(2,0) + d2 * pow(2,1) + d3 * pow (2,2) + d4 * pow(2,3));
}

int main(){
    int d1, d2, d3, d4;
   
    cout << "Enter binary number" << endl;
    cin >> d1 >> d2 >> d3 >> d4;

   int decimal = B2D(d1, d2, d3, d4);
   cout << " binary to decimal: " << decimal << endl;

    return 0;
}