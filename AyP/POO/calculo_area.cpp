#include <iostream>
using namespace std;

class figura{
    
    float base;
    float altura;

    public: 

    float getBase(){
        return base;
    }

    float getAltura(){
        return altura;
    }

     void setBase(float b){
        base = b;
    }

    void setAltura(float a){
        altura = a;
    }

    figura(float b, float a){
        this->base = b;
        this->altura = a;
    }
    
    float area(){
        return this->base * this->altura;
    }

};

int main(){
    float base, altura;
    cout << "Ingrese la base del cuadrado: ";
    cin >> base;
    cout << "Ingrese la altura del cuadrado: ";
    cin >> altura;

    figura cuadrado = figura(base, altura);

    cuadrado.setBase(10);
    cuadrado.setAltura(20);

    cout << cuadrado.getBase() << endl;
    cout << cuadrado.getAltura() << endl;

    cout << "El area es " << cuadrado.area() << endl; 


    return 0;
}