#include <iostream>
using namespace std;

bool Capicua(int num){
    int numO = num, numI = 0;
   
    while (num > 0){
        numI = numI * 10 + num % 10; 
        num /= 10; 
    }

    if(numI == numO) return true;
    else return false;
}

int main(){
    int num;
    cout << "Enter the number: ";
    cin >> num;

    if(Capicua) cout << "Es Capicua" << endl;
    else cout << "No es capicua" << endl;

    return 0;
}