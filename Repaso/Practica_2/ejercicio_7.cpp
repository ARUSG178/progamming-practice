#include <iostream>
using namespace std;

double calculus(int d, int t){
    return d/t;
}

int main(){
    double distance, time;

    double velocity = calculus(distance , time);

    cout << "The velocity is: " << velocity << endl;
    
    return 0;
}