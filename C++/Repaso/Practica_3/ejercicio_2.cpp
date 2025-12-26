#include <iostream>
#include <string>
using namespace std;

int secondsPassed(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}

int main (){
    int hours, minutes, seconds;
    string wMeridian;
   
    cout << "Enter the time is it [hours, minutes, seconds]: ";
    cin >> hours >> minutes >> seconds;

    cout << "Enter in wich meridian [AM|PM]: ";
    cin >> wMeridian;

    if (hours > 12 || minutes >= 60 || seconds >= 60) {
        cout << "Incorrect format" << endl;
        return 1;
    } 

    // Caso especial
    if(wMeridian == "PM" && hours != 12) hours += 12;
    if(wMeridian == "AM" && hours == 12) hours = 0;

    int timePassed = secondsPassed(hours, minutes, seconds);
    cout << "The time passed in seconds is: " << timePassed << endl;

    return 0;
}