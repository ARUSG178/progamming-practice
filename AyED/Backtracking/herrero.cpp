#include <iostream>
using namespace std;

int maxEspadas = 0;
void coleccionEspadas(int madera, int hierro, int propMaMax, int propHiMax, int contador){
        bool pudo = false;

        for(int i = 0; i < propMaMax; i++){
            for(int j = 0; j < propHiMax; j++){
                if(madera >= i && hierro >= j){
                    pudo = true;
                }

        }
    }
}



int espadas(int madera, int hierro, int proporcionMa, int proporcionHi){
    maxEspadas = 0;
    coleccionEspadas(madera, hierro, proporcionMa, proporcionHi, 0);
    return maxEspadas;
}

int main(){
    int ma, hi;
    cin >> ma >> hi;
    int propMaMax, propHiMax;
    cin >> ma >> hi;

    espadas(ma, hi, propMaMax, propHiMax);
}