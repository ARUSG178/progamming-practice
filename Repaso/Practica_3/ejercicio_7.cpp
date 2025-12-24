#include <iostream>
using namespace std;

bool isLeapYear(int year){
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int daysCalculus(int day, int month, int year){
    int totalDays = 0;

    switch(month){
        case 12: totalDays += (334 +(isLeapYear(year) ? 1 : 0)) + day; break; 
        case 11: totalDays += (304 +(isLeapYear(year) ? 1 : 0)) + day; break; 
        case 10: totalDays += (273 +(isLeapYear(year) ? 1 : 0)) + day; break; 
        case 9:  totalDays += (243 +(isLeapYear(year) ? 1 : 0)) + day; break; 
        case 8:  totalDays += (212 +(isLeapYear(year) ? 1 : 0)) + day; break;
        case 7:  totalDays += (181 +(isLeapYear(year) ? 1 : 0)) + day; break; 
        case 6:  totalDays += (151 +(isLeapYear(year) ? 1 : 0)) + day; break; 
        case 5:  totalDays += (120 +(isLeapYear(year) ? 1 : 0)) + day; break; 
        case 4:  totalDays += (90 + (isLeapYear(year) ? 1 : 0)) + day; break; 
        case 3:  totalDays += (59 + (isLeapYear(year) ? 1 : 0)) + day; break; 
        case 2:  totalDays += 31 + day; break;
        case 1:  totalDays += day; break; 
    }

    return totalDays;
}

int main (){
    int day, month, year;
    
    cout << "enter the day and the month, in that order: ";
    cin >> day >> month;
    if(day < 0 || (month < 0 || month > 12)) return 1;

    cout << "enter the year: ";
    cin >> year;
    if (year < 0) return 1;

    cout << "Days passed since January 1st: " << daysCalculus(day, month, year) << endl;

    return 0;
}