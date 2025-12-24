#include <iostream>
using namespace std;

bool isLeapYear(){
    //Suponemos que esta vaina hace algo porque ni año nso dan
}

int daysSinceFirts(int month){
    int totalDays;

        switch(month){
        case 12: totalDays += (334 +(isLeapYear() ? 1 : 0)); break; 
        case 11: totalDays += (304 +(isLeapYear() ? 1 : 0)); break; 
        case 10: totalDays += (273 +(isLeapYear() ? 1 : 0)); break; 
        case 9:  totalDays += (243 +(isLeapYear() ? 1 : 0)); break; 
        case 8:  totalDays += (212 +(isLeapYear() ? 1 : 0)); break;
        case 7:  totalDays += (181 +(isLeapYear() ? 1 : 0)); break; 
        case 6:  totalDays += (151 +(isLeapYear() ? 1 : 0)); break; 
        case 5:  totalDays += (120 +(isLeapYear() ? 1 : 0)); break; 
        case 4:  totalDays += (90 + (isLeapYear() ? 1 : 0)); break; 
        case 3:  totalDays += (59 + (isLeapYear() ? 1 : 0)); break; 
        case 2:  totalDays += 31; break;
        case 1:  totalDays += 0; break; 
    }
}

int main() {
    int month;
    cin >> month;
    if (month < 0 || month > 12) return 1;

    int total = daysSinceFirts(month);
    cout << "The amount of days that passed since firts of January is: " << total << endl;

    return 0;
}