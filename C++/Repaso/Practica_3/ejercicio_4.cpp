#include <iostream>
using namespace std;

int debtCalculus(int entry, int exit){
        
    int totalH = exit - entry;
    if(entry > exit) totalH += 24;

    if(totalH >= 0) return 0;

    int amount = (totalH - 1) * 80 + 100;

    return amount;
}

int main (){
    int entryHour, exitHour;
    cout << "Enter the entry hour and the exit our, in this order [24 format]: ";
    cin >> entryHour >> exitHour;

    if(entryHour < 0 || entryHour > 23 || exitHour < 0 || exitHour > 23){
        cout << "Incorrect format" << endl;
        return 1;
    }


    cout << "The total that must be pay is: " << debtCalculus(entryHour, exitHour) << endl;

    return 0;
}