#include <iostream>
#include <string>
using namespace std;

void imprimirBool(string palabra, bool existe){
    cout << "La palabra " << palabra << ((existe == true)? " es capicúa" : " no es capicúa") << endl;
}

bool capicua(string palabra){
    bool existe = false;
    string palabraInversa = "";
    for(int i = palabra.length() - 1; i >= 0 ; i--){
        palabraInversa += palabra[i];
    }

    if(palabraInversa == palabra) existe = true;
    else existe = false;
    return existe;
}

int main(){
    string palabra;
    getline(cin,palabra);

    if(palabra.empty()) {
        cout << "La palabra no puede estar vacía." << endl;
        return 1;
    }

    bool existeCapicua = capicua(palabra);
    imprimirBool(palabra, existeCapicua);

    return 0;  
}