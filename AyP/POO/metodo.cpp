#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Fraccion {
    private:
    int N1;
    int N2;
    int calcularMCD(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return calcularMCD(b, a % b);
        }
    }
    public:
    Fraccion(int numerador, int denominador) {
        this->N1 = numerador;
        this->N2 = denominador;
    }
    void sumar(Fraccion& b){
        int tempN1 = this->N1 * b.N2 + this->N2 * b.N1;
        int tempN2 = this->N2 * b.N2;
        this->N1 = tempN1;
        this->N2 = tempN2;
        b.N1 = tempN1;
        b.N2 = tempN2;
        simplificar();
        b.simplificar();
    }
    void multiplicar(Fraccion& b){
        int tempN1 = this->N1 * b.N1;
        int tempN2 = this->N2 * b.N2;
        this->N1 = tempN1;
        this->N2 = tempN2;
        b.N1 = tempN1;
        b.N2 = tempN2;
        simplificar();
        b.simplificar();
    }
    void dividir(Fraccion& b){
        int tempN1 = this->N1 * b.N2;
        int tempN2 = this->N2 * b.N1;
        this->N1 = tempN1;
        this->N2 = tempN2;
        b.N1 = tempN1;
        b.N2 = tempN2;
        simplificar();
        b.simplificar();
    }
    bool comparar(Fraccion b){
        if(N1 == b.N1 && N2 == b.N2) return true;
        return false;
    }
    void simplificar() {
        int mcd = calcularMCD(N1, N2);
        N1 /= mcd;
        N2 /= mcd;
    }
    string astring(){
        return to_string(N1) + "/" + to_string(N2);
    }
};

int main(){
    Fraccion rptm(4,9);
    Fraccion rpsm(3,7);
    rptm.sumar(rpsm);
    cout << "rptm: " << rptm.astring() << endl;
    cout << "rpsm: " << rpsm.astring() << endl;
    return 0;
}