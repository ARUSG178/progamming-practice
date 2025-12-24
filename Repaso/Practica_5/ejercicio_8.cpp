#include <iostream>
using namespace std;

bool insideRectangle(int X, int Y, int base, int height) {
    return (X >= 0 && X <= base && Y >= 0 && Y <= height);
}

int main() {
    int X, Y;
    int base, height;

    cout << "Enter base and height of rectangle: ";
    cin >> base >> height;

    cout << "Enter point coordinates (X Y): ";
    cin >> X >> Y;

    if (insideRectangle(X, Y, base, height))
        cout << "Point is inside the rectangle." << endl;
    else
        cout << "Point is outside the rectangle." << endl;

    return 0;
}