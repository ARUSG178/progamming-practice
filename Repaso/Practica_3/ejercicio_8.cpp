#include <iostream>
using namespace std;

void breaking(int &d1, int &d2, int &d3, int &d4, int num){
    d4 = num % 10; num /= 10;
    d3 = num % 10; num /= 10;
    d2 = num % 10; num /= 10;
    d1 = num;
}

bool isHappy(int d1, int d2, int d3, int d4){
    int d5 = (d1 * 10) + d2, d6 = (d3 * 10) + d4;
    return d5 > d6;
}

bool isGrowing(int d1, int d2, int d3, int d4){
    return (d4 > d3 && d3 > d2 && d2 > d1);
}

int main(){
    int num, d1 = 0, d2 = 0, d3 = 0, d4 = 0;

    cout << "Enter the number: "; cin >> num;
    if (num < 1000 || num > 9999) return 1;

    breaking(d1, d2, d3, d4, num);
    if(isHappy(d1, d2, d3, d4) && isGrowing(d1, d2, d3, d4)) cout << "is very happy" << endl;
    else if(isHappy(d1, d2, d3, d4) && !(isGrowing(d1, d2, d3, d4))) cout << "is happy" << endl;
    else if(!(isHappy(d1, d2, d3, d4)) && isGrowing(d1, d2, d3, d4)) cout << "is growing" << endl;
    else cout << "is unhappy" << endl;
    
    return 0;
}