#include <iostream>
using namespace std;

void IMC(double idx){
    if(idx < 16) cout << "delgadez severa";
    else if(idx >= 16 && idx <= 16.9) cout << "infrapeso";
    else if(idx >= 17 && idx <= 18.4) cout << "bajo peso";
    else if(idx >= 18.5 && idx <= 24.9) cout << "peso normal";
    else if(idx >= 25 && idx <= 29.9) cout << "sobrepeso";
    else if(idx >= 30 && idx <= 34.9) cout << "obesidad premórbida";
    else if(idx >= 35 && idx <= 39.9) cout << "obesidad grado II";
    else if(idx >= 40 && idx <= 45) cout << "obesidad mórbida";
    else if(idx > 45) cout << "obesidad hipermórbida";
}

int main (){
    double lbs, cmts;

    cout << "Enter the weight (in pounds) and stature (in centimeters): ";
    cin >> lbs >> cmts;

    double kgs = lbs * 0.453592;
    double mts = cmts / 100.0;
    double index = kgs / (mts * mts);
        
    cout << "IMC = " << index << " -> ";
    IMC(index);

    return 0;
}