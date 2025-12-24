#include <iostream>
using namespace std;

bool isCapicua(int number){
   int  numberI = 0;
   int  numberO = number;

    while (number > 0){
       int d = number % 10;
       number /= 10;
       numberI = (number * 10) + d; 
    }

    return numberI == numberO;
}

int main(){
    int number;
    cin >> number;
    if(isCapicua(number)) cout << "The number is Capicua" << endl;
    else cout << "The number isn't Capicua" << endl;
    
    return 0;
}