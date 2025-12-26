#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main () {
    ifstream file("archive/letras.txt");
    if(!file.is_open()){
        cerr << "No se pudo abrir el archivo letras.txt\n";
        return 1;           
    }

    map <char, int> frequency; // guarda un arreglo ordenado de pair <const clave, valor>
    char c;

    while(file.get(c)) {
        if(isalpha(c)) {
            c = tolower(c);
            frequency[c]++;
        }
    }

    file.close();

    for(auto &p: frequency) cout << "Letter and its frequency: " << p.first << ": " << p.second << endl;

    return 0;
}
