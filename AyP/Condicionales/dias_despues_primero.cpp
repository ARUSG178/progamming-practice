#include <iostream>
using namespace std;

int convertir(int meses, int dias){
    int diasTotales = -1 + dias;
    for(int i = 1; i < meses; i++){
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) diasTotales += 31;
        else if(i == 4 || i == 6 || i == 9 || i == 11) diasTotales += 30;
        else if(i == 2) diasTotales += 28;
    }

    return diasTotales;
   
}

int main(){
    int dia, mes;
    cin >> dia >> mes;
    
    int diasTotales = convertir(mes, dia);
    cout << diasTotales << endl;

    return 0;
}