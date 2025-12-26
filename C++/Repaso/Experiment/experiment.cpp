#include <iostream>
#include <string>
using namespace std;

int main () {

    auto a = string("uwu");
    [&a] () { a = "culo"; } ();

    cout << a << endl;

    return 0;
}