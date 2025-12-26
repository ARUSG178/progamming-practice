#include <iostream> 
using namespace std;

void capicuaSomewhere(int num){

    int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0; 
    d6 = num % 10; num /= 10;
    d5 = num % 10; num /= 10;
    d4 = num % 10; num /= 10;
    d3 = num % 10; num /= 10;
    d2 = num % 10; num /= 10;
    d1 = num;

    if(d1 == d3) cout << "Capicua found: " << d1 << d2 << d3 << endl;
    else if(d2 == d4) cout << "Capicua found: " << d2 << d3 << d4 << endl;
    else if(d3 == d5) cout << "Capicua found: " << d3 << d4 << d5 << endl;
    else if(d4 == d6) cout << "Capicua found: " << d4 << d5 << d6 << endl;
    else cout << "Capicua not found." << endl;

}

void capicuaSomewhereIterative(int num){
    for (int i = 0; i < 6; i++) {
            int seccion = num % 1000;
            int d1 = seccion & 10; 
            int d2 = (seccion / 10) % 10;
            int d3 = seccion / 100;

            if(d1 == d3) cout << "Capicua found: " << d1 << d2 << d3 << endl; return;

             num /= 10;
        }
    cout << "Capicua not found." << endl;
}

int main () {
    int num;
    cin >> num;
    if(num < 100000 || num > 999999) return 1;

    return 0;
}