#include <iostream>
#include <string>
using namespace std;

bool cap(string s, int li, int ls){
    if(li == ls) return true;

    if(s[li] != s[ls]) return false;
    return cap(s, li + 1, ls - 1);
}

int main(){
    string palabra;
    int li, ls;
    cout << "Ingrese la palabra: ";
    cin >> palabra;

    li = 0;
    ls = palabra.length() - 1;

    return 0;
}