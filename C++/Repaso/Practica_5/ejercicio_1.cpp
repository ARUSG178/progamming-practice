#include <iostream>
#include <string>
using namespace std;

double M2K(double miles) {
    return miles * 1.6;
}

bool final(string a, string b, double miles) {
    return (a == b && miles == 0);
}

void CityInput(string &a, string &b, double &miles) {
    cin >> a >> b >> miles;
}

int main() {
    string city1, city2;
    double miles;

    CityInput(city1, city2, miles);

    while (!final(city1, city2, miles)) {
        double km = M2K(miles);
        cout << city1 << " " << city2 << ": " << km << endl;

        CityInput(city1, city2, miles);
    }

    return 0;
}