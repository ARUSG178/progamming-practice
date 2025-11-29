#include <iostream>
#include <string>
using namespace std;

class Tiempo{
    private:
    int horas, minutos, segundos;
    public:
    Tiempo(int h, int m, int s);
    Tiempo(long int f);
    string print();


};

Tiempo::Tiempo(int h, int m, int s){
    horas = h;
    minutos = m;
    segundos = s;
}
           
Tiempo::Tiempo(long int f){
    horas = f/3600;
    minutos = (f%3600)/60;
    segundos = f%60;
}

string Tiempo::print(){
    return "Las horas: " + to_string(this ->horas) + ", los minutos: " + to_string(this->minutos) + ", los segundos: " + to_string(this->segundos) + "\n";
}

int main(){
    Tiempo s1(54, 24, 25);
    cout << s1.print() << endl;
    Tiempo s2(10000);
    cout << s2.print() << endl;

    return 0;
}