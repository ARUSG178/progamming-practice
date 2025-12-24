///////////////////////////////////////////
//    Hecho con IA (no entendí el hpta)
///////////////////////////////////////////
#include <iostream>
#include <cmath>
using namespace std;

// Función para calcular el máximo común divisor (mcd)
int gcd(int a, int b) {
    while(b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Función para calcular el mínimo común múltiplo (mcm)
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

bool theyAre(int j, int p, int k) {
    int puntoEncuentro = lcm(j, p); // primer punto donde podrían coincidir
    return puntoEncuentro <= j * k; // si ocurre antes de que José dé K saltos
}

int main (){ 
    int jose_j_cm, pedro_p_cm;
    int jose_k_jumps;
    cout << "Ingrese J (salto de José), P (salto de Pedro) y K (saltos max de José): ";
    cin >> jose_j_cm >> pedro_p_cm >> jose_k_jumps;

    bool meets = theyAre(jose_j_cm, pedro_p_cm, jose_k_jumps);

    if(meets)
        cout << "Sí, las ranas coinciden en algún punto antes de K saltos." << endl;
    else
        cout << "No, las ranas no coinciden en ese intervalo." << endl;

    return 0;
}