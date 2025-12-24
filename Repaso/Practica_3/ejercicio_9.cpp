#include <iostream>
using namespace std;

void printMonth (int num){
    switch(num){
        case 1: cout << "January" << endl; break;
        case 2: cout << "February" << endl; break;
        case 3: cout << "March" << endl; break;
        case 4: cout << "April" << endl; break;
        case 5: cout << "May" << endl; break;
        case 6: cout << "June" << endl; break;
        case 7: cout << "July" << endl; break;
        case 8: cout << "Agoust" << endl; break;
        case 9: cout << "September" << endl; break;
        case 10: cout << "Octuber" << endl; break;
        case 11: cout << "November" << endl; break;
        case 12: cout << "December" << endl; break;
    }
}

int main() {
    int num;
    cout << "Enter the number of the month [1 - 12]: ";
    cin >> num;

    if (num < 0 || num > 12) {
        cout << "Invalid format"<< endl;
        return 1;
    }
    
    printMonth(num);

    return 0;
}