#include <iostream>
using namespace std;

double kilosLibras(double libras){
    return libras * 0.453592;
}

double centimetroMetro(double centimetros){
    return centimetros * 0.01;
}

double IMC(double peso, double altura){
    return peso / (altura * altura);
}

void IndiceDeMasaCorporal(double indice, float peso){

    if (indice < 16) cout << "Con un peso de: " << peso << "y un valor de IMC de: " << IMC << " tienes un criterio de ingreso." << endl;
    else if (16 < indice < 16.9) cout << "Con un peso de: " << peso << "y un valor de IMC de: " << IMC << " tienes un infrapeso." << endl;
    else if (17 < indice < 18.4) cout << "Con un peso de: " << peso << "y un valor de IMC de: " << IMC << " tienes un bajo peso." << endl;
    else if (18.5 < indice < 24.9) cout << "Con un peso de: " << peso << "y un valor de IMC de: " << IMC << " peso normal." << endl;
    else if (25 < indice < 29.9) cout << "Con un peso de: " << peso << "y un valor de IMC de: " << IMC << " tienes sobrepeso." << endl;
    else if (30< indice < 39.9) cout << "Con un peso de: " << peso << "y un valor de IMC de: " << IMC << " tienes un obesidad premórbida." << endl;
    else if (40 < indice < 18.4) cout << "Con un peso de: " << peso << "y un valor de IMC de: " << IMC << " tienes un obesidad mórbida." << endl;
    else if (45 < indice) cout << "Con un peso de: " << peso << "y un valor de IMC de: " << IMC << " tienes un obesidad hipermórbida." << endl;

}

int main(){
    double pesoLb, pesoKg = 0, estaturaCm, estaturaM = 0;
    cin >> pesoLb >> estaturaCm; 

    pesoKg = kilosLibras(pesoLb);
    estaturaM = centimetroMetro(estaturaCm);
    double indice = IMC(pesoKg, estaturaM);
    IndiceDeMasaCorporal(indice, pesoKg);


    system("pause");
    return 0;
}