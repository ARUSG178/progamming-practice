#include <iostream>
#include <cstdlib>
using namespace std;

//INICIALIZACIÓN DE VARIABLES: Contadores de elementos totales de un tipo y contadores de tesoros encontrados y trampas pisadas.
int c_tes = 0, c_trs = 0, c_ms = 0, c_por = 0, c_E = 0, c_S = 0;
int tes_ob = 0, tr_pis = 0;
//INICIALIZACIÓN DE VARIABLES: Cordenadas (X,Y) del uno al diez por cada elemento y su tipo.
//Tesoros.
int teX1 = -1, teY1 = -1, teX2 = -1, teY2 = -1, teX3 = -1, teY3 = -1; 
int teX4 = -1, teY4 = -1, teX5 = -1, teY5 = -1, teX6 = -1, teY6 = -1;
int teX7 = -1, teY7 = -1, teX8 = -1, teY8 = -1, teX9 = -1, teY9 = -1;
int teX10 = -1, teY10 = -1;
//Trampas.
int trX1 = -1, trY1 = -1, trX2 = -1, trY2 = -1, trX3 = -1, trY3 = -1;
int trX4 = -1, trY4 = -1, trX5 = -1, trY5 = -1, trX6 = -1, trY6 = -1;
int trX7 = -1, trY7 = -1, trX8 = -1, trY8 = -1, trX9 = -1, trY9 = -1;
int trX10 = -1, trY10 = -1;
//Muros.
int mX1 = -1, mY1 = -1, mX2 = -1, mY2 = -1, mX3 = -1, mY3 = -1;
int mX4 = -1, mY4 = -1, mX5 = -1, mY5 = -1, mX6 = -1, mY6 = -1;
int mX7 = -1, mY7 = -1, mX8 = -1, mY8 = -1, mX9 = -1, mY9 = -1;
int mX10 = -1, mY10 = -1;
//Portales (Portal 'a' y Portal 'b').
int pAX1 = -1, pAY1 = -1, pBX1 = -1, pBY1 = -1, pAX2 = -1, pAY2 = -1, pBX2 = -1, pBY2 = -1;
int pAX3 = -1, pAY3 = -1, pBX3 = -1, pBY3 = -1, pAX4 = -1, pAY4 = -1, pBX4 = -1, pBY4 = -1;
int pAX5 = -1, pAY5 = -1, pBX5 = -1, pBY5 = -1, pAX6 = -1, pAY6 = -1, pBX6 = -1, pBY6 = -1;
int pAX7 = -1, pAY7 = -1, pBX7 = -1, pBY7 = -1, pAX8 = -1, pAY8 = -1, pBX8 = -1, pBY8 = -1;
int pAX9 = -1, pAY9 = -1, pBX9 = -1, pBY9 = -1, pAX10 = -1, pAY10 = -1, pBX10 = -1, pBY10 = -1;
//Entrada y salida.
int eX = 0, eY = 0, sX = 0, sY = 0;

//FUNCIÓN: Registrar los elementos y llevar cuenta para no sobrepasar el límite.
void reEle(char tipo, int &contador) {
    switch (tipo) {
        case 'E': //ENTRADA (1)
            cin >> eX >> eY;
            contador--; break;
        case 'S': //SALIDA (1)
            cin >> sX >> sY;
            contador--; break;
        case 'T': //TESOROS (MAX 10)
            if (c_tes < 10) { 
                switch (c_tes) {
                    case 0: cin >> teX1 >> teY1; break;
                    case 1: cin >> teX2 >> teY2; break;
                    case 2: cin >> teX3 >> teY3; break;
                    case 3: cin >> teX4 >> teY4; break;
                    case 4: cin >> teX5 >> teY5; break;
                    case 5: cin >> teX6 >> teY6; break;
                    case 6: cin >> teX7 >> teY7; break;
                    case 7: cin >> teX8 >> teY8; break;
                    case 8: cin >> teX9 >> teY9; break;
                    case 9: cin >> teX10 >> teY10; break;
                }
                contador--; c_tes++;
            } break;
        case 'X': // TRAMPAS (MAX 10)
            if (c_trs < 10) { 
                switch (c_trs) {
                    case 0: cin >> trX1 >> trY1; break;
                    case 1: cin >> trX2 >> trY2; break;
                    case 2: cin >> trX3 >> trY3; break;
                    case 3: cin >> trX4 >> trY4; break;
                    case 4: cin >> trX5 >> trY5; break;
                    case 5: cin >> trX6 >> trY6; break;
                    case 6: cin >> trX7 >> trY7; break;
                    case 7: cin >> trX8 >> trY8; break;
                    case 8: cin >> trX9 >> trY9; break;
                    case 9: cin >> trX10 >> trY10; break;
                }
                contador--; c_trs++;
            } break;
        case '#': // MUROS (MAX 10)
            if (c_ms < 10) {  
                switch (c_ms) {
                    case 0: cin >> mX1 >> mY1; break;
                    case 1: cin >> mX2 >> mY2; break;
                    case 2: cin >> mX3 >> mY3; break;
                    case 3: cin >> mX4 >> mY4; break;
                    case 4: cin >> mX5 >> mY5; break;
                    case 5: cin >> mX6 >> mY6; break;
                    case 6: cin >> mX7 >> mY7; break;
                    case 7: cin >> mX8 >> mY8; break;
                    case 8: cin >> mX9 >> mY9; break;
                    case 9: cin >> mX10 >> mY10; break;
                }
                contador--; c_ms++;
            } break;
        case 'P': // PORTALES (MAX 10)
            if (c_por < 10) { 
                switch (c_por) {
                    case 0: cin >> pAX1 >> pAY1 >> pBX1 >> pBY1; break;
                    case 1: cin >> pAX2 >> pAY2 >> pBX2 >> pBY2; break;
                    case 2: cin >> pAX3 >> pAY3 >> pBX3 >> pBY3; break;
                    case 3: cin >> pAX4 >> pAY4 >> pBX4 >> pBY4; break;
                    case 4: cin >> pAX5 >> pAY5 >> pBX5 >> pBY5; break;
                    case 5: cin >> pAX6 >> pAY6 >> pBX6 >> pBY6; break;
                    case 6: cin >> pAX7 >> pAY7 >> pBX7 >> pBY7; break;
                    case 7: cin >> pAX8 >> pAY8 >> pBX8 >> pBY8; break;
                    case 8: cin >> pAX9 >> pAY9 >> pBX9 >> pBY9; break;
                    case 9: cin >> pAX10 >> pAY10 >> pBX10 >> pBY10; break;
                }
                contador -= 2; c_por++;
            } break;
    }
}
//FUNCIÓN: Evaluar y reposicionar si el jugador a tocado un tesoro [En la posición (-10,-10) el jugador no puede tomarlo].
bool veTes(int X, int Y) {
    if (X == teX1 && Y == teY1) { teX1 = teY1 = -10; return true; }
    if (X == teX2 && Y == teY2) { teX2 = teY2 = -10; return true; }
    if (X == teX3 && Y == teY3) { teX3 = teY3 = -10; return true; }
    if (X == teX4 && Y == teY4) { teX4 = teY4 = -10; return true; }
    if (X == teX5 && Y == teY5) { teX5 = teY5 = -10; return true; }
    if (X == teX6 && Y == teY6) { teX6 = teY6 = -10; return true; }
    if (X == teX7 && Y == teY7) { teX7 = teY7 = -10; return true; }
    if (X == teX8 && Y == teY8) { teX8 = teY8 = -10; return true; }
    if (X == teX9 && Y == teY9) { teX9 = teY9 = -10; return true; }
    if (X == teX10 && Y == teY10) { teX10 = teY10 = -10; return true; }
    return false;
}
//FUNCIÓN: Evaluar si el jugador a tocado una trampa [Las trampas pueden pisarse siempre].
bool veTrs(int X, int Y) {
    if (X == trX1 && Y == trY1) { return true; }
    if (X == trX2 && Y == trY2) { return true; }
    if (X == trX3 && Y == trY3) { return true; }
    if (X == trX4 && Y == trY4) { return true; }
    if (X == trX5 && Y == trY5) { return true; }
    if (X == trX6 && Y == trY6) { return true; }
    if (X == trX7 && Y == trY7) { return true; }
    if (X == trX8 && Y == trY8) { return true; }
    if (X == trX9 && Y == trY9) { return true; }
    if (X == trX10 && Y == trY10) { return true; }
    return false; 
} 
//FUNCIÓN: Verificar que el movimiento del jugador sea válido antes de ejecutarse, es decir, que no haya un muro.
bool veMu(int X, int Y, char movimiento) {

    int predicX = X, predicY = Y; // Variables usadas para "predecir" el movimiento del jugador cuando pulse una tecla.

    if (movimiento == 'w') predicY++;
    if (movimiento == 's') predicY--;
    if (movimiento == 'd') predicX++;
    if (movimiento == 'a') predicX--;

    if (predicX == mX1 && predicY == mY1) { return false; }
    if (predicX == mX2 && predicY == mY2) { return false; }
    if (predicX == mX3 && predicY == mY3) { return false; }
    if (predicX == mX4 && predicY == mY4) { return false; }
    if (predicX == mX5 && predicY == mY5) { return false; }
    if (predicX == mX6 && predicY == mY6) { return false; }
    if (predicX == mX7 && predicY == mY7) { return false; }
    if (predicX == mX8 && predicY == mY8) { return false; }
    if (predicX == mX9 && predicY == mY9) { return false; }
    if (predicX == mX10 && predicY == mY10) { return false; }
    return true;
}
//FUNCIÓN: Verifica que el jugador no se salga de los límites del laberinto N y M.
bool veLi(int X, int Y, char movimiento, int tamN, int tamM) {
    if (movimiento == 'w' && Y + 1 > tamM) { return true; }
    if (movimiento == 's' && Y - 1 < 0) { return true; }
    if (movimiento == 'd' && X + 1 > tamN) { return true; }
    if (movimiento == 'a' && X - 1 < 0) { return true; }
    return false; 
}
//FUNCIÓN: Verifica si el jugador entro en un portal 'X' para salir por el portal 'Y' [Se igualan coordenadas].
void vePor(int &X, int &Y) {
    // Ingresa por el portal A y sale por el portal B.
    if (X == pAX1 && Y == pAY1) { X = pBX1; Y = pBY1; }
    if (X == pAX2 && Y == pAY2) { X = pBX2; Y = pBY2; }
    if (X == pAX3 && Y == pAY3) { X = pBX3; Y = pBY3; }
    if (X == pAX4 && Y == pAY4) { X = pBX4; Y = pBY4; }
    if (X == pAX5 && Y == pAY5) { X = pBX5; Y = pBY5; }
    if (X == pAX6 && Y == pAY6) { X = pBX6; Y = pBY6; }
    if (X == pAX7 && Y == pAY7) { X = pBX7; Y = pBY7; }
    if (X == pAX8 && Y == pAY8) { X = pBX8; Y = pBY8; }
    if (X == pAX9 && Y == pAY9) { X = pBX9; Y = pBY9; }
    if (X == pAX10 && Y == pAY10) { X = pBX10; Y = pBY10; }
    // Ingresa por el portal B y sale por el portal A.
    if (X == pBX1 && Y == pBY1) { X = pAX1; Y = pAY1; }
    if (X == pBX2 && Y == pBY2) { X = pAX2; Y = pAY2; }
    if (X == pBX3 && Y == pBY3) { X = pAX3; Y = pAY3; }
    if (X == pBX4 && Y == pBY4) { X = pAX4; Y = pAY4; }
    if (X == pBX5 && Y == pBY5) { X = pAX5; Y = pAY5; }
    if (X == pBX6 && Y == pBY6) { X = pAX6; Y = pAY6; }
    if (X == pBX7 && Y == pBY7) { X = pAX7; Y = pAY7; }
    if (X == pBX8 && Y == pBY8) { X = pAX8; Y = pAY8; }
    if (X == pBX9 && Y == pBY9) { X = pAX9; Y = pAY9; }
    if (X == pBX10 && Y == pBY10) { X = pAX10; Y = pAY10; }
}
//FUNCIÓN: Si el jugador llega a la salida, se evalua qué tipo de final "bueno" ('SORPRENDENTE' o 'LOGRADO') obtiene. Si se queda sin movimientos antes, se activa el final ´ATRAPADO´.
void finales(int X, int Y, int vida, int movimientoRes) {
    if (X == sX && Y == sY) {
        if (tes_ob == c_tes) cout << "TESOROS: " << tes_ob << "\nTRAMPA: " << tr_pis << "\nVIDA: " << vida << "\nSORPRENDENTE" << endl;
        cout << "TESOROS: " << tes_ob << "\nTRAMPA: " << tr_pis << "\nVIDA: " << vida << "\nLOGRADO" << endl;
        system("pause");
        exit(0);
    }
    if (movimientoRes <= 0) { 
        cout << "TESOROS: " << tes_ob << "\nTRAMPA: " << tr_pis << "\nVIDA: " << vida << "\nATRAPADO" << endl;
        system("pause");
        exit(0); 
    }
}

int main () {
    //INICIALIZACIÓN DE VARIABLES: Dimensiones, vida máxima, elementos y su cantidad.
    int n = 0, m = 0, l = 0;
    int e_T = 0;
    char elemento;
    //INICIALIZACIÓN DE VARIABLE: Coordenadas, movimientos totales y tipo de movimiento (WASD) del jugador.
    int X = 0, Y = 0, M = 0;
    char mov;
    //INICIALIZACIÓN DE VARIABLE: Vida que interactuará será igual a la vida estipulada por el jugador (máxima).
    int l_r = 0;  
    
    cin >> l;
    cin >> n >> m;
    cin >> e_T; 
    
    while (e_T > 0) { //Se registran todos los elementos que albergará el laberinto.
    cin >> elemento;
    if (elemento == '.'); //Es un espacio vacío, no hace nada. Literalmente.
    else reEle(elemento, e_T);
    }

    cin >> M; 
    //Se igualan las coordenadas del jugador a la entrada del laberinto y la vida que interactuará con el ciclo respecto a la máxima.
    X = eX, Y = eY;
    l_r = l; 

    while (l_r > 0){ //Mientras que la vida (que interactua) sea mayor a cero, el jugador continuará moviéndose.
          
        cin >> mov; //Se ingresa el movimiento (WASD).

         M--; //Se resta un movimiento.
         
        if (veLi(X, Y, mov, n, m)) continue; //Si el jugador se sale del límite [(X,-1), (-1,Y), (N,Y), (X,M)], simplemente se omite la iteración actual para ingresar otro movimiento.
        
        switch (mov) { //Se llama a la función: Si retorna FALSE (con la negación TRUE) se ejecuta el movimiento, de lo contrario, el jugador chocó con un muro.
            case 'w': 
                if (veMu(X, Y, mov)) Y++;  // ARRIBA
                else cout << "Movimiento bloqueado." << endl;
                break; 
            case 's': 
                if (veMu(X, Y, mov)) Y--;  // ABAJO
                else cout << "Movimiento bloqueado." << endl;
                break; 
            case 'd': 
                if (veMu(X, Y, mov)) X++;  // DERECHA
                else cout << "Movimiento bloqueado." << endl;
                break; 
            case 'a': 
                if (veMu(X, Y, mov)) X--;  // IZQUIERDA
                else cout << "Movimiento bloqueado." << endl;
                break; 
        }

        vePor(X, Y); // Verificar si el jugador está sobre un portal y actuar en consecuencia.

        if (veTes(X, Y)) {
            l_r += 20; tes_ob++; // Si pisó: suma de vida y tesoros encontrados.
            if (l_r > l) l_r = l; // Se ajusta la vida (que interactua) a la vida máxima si la sobrepasa.
        }   
        if (veTrs(X, Y)) {
            l_r -= 10; tr_pis++; // Si pisó: resta de vida y sumo trampa activada.
        }
        
        finales(X, Y, l_r, M); //Ver si cumple las condiciones para obtener algún final.
    }
    // Si el jugador sale del ciclo, quiere decir que su vida es igual o menor a cero. Por lo tanto está 'MUERTO'.
    cout << "TESOROS: " << tes_ob << "\nTRAMPA: " << tr_pis << "\nVIDA: " << l_r << "\nMUERTO" << endl;
    return 0;
}