#include <iostream>
#include <string>
using namespace std;

class Numero{
    int valor;
    public:
    Numero(int v){ valor = v; }
    int CalcularFactoria(){
        int resultado = 1;
        for (int i = 1; i <= valor; i++) {
            resultado *= i;
        }
        return resultado;
    }
    string print(int factorial){
        string cadena = "";
        cadena = to_string(factorial);
        return "El factorial de " + to_string(this->valor) + " es: " + cadena;
    }
    void printAcumulado(int factorial){
        for(int i = 0; i <= factorial; i++){
            if (i == factorial) cout << i << ".";
            else cout << i << " ";
        }

    }
};

int main(){

    Numero num(5);
    int factorial = num.CalcularFactoria();
    cout << num.print(factorial) << endl;
    num.printAcumulado(factorial);

    return 0;
}