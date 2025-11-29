#include <iostream>
#include <cmath>
using namespace std;

class EmisoraFM {
    private:
    string nombre;
    double frecuencia;
    public:
    EmisoraFM(string n) {
        this->nombre = n;
        this->frecuencia = 80;
    }

    void setFrecuencia() {
        char manilla;
        cout << "W -> aumentar | S -> disminuir | E -> Salir" << endl;
        bool dejar = true;
        do {
            cin >> manilla;
            switch(manilla){
                case 'w':
                    frecuencia += 0.5;
                    cout << "Frecuencia aumentada " << endl;
                    if(frecuencia >= 108) frecuencia = 80;
                    break;

                case 's':
                    frecuencia -= 0.5;
                    cout << "Frecuencia disminuida " << endl;
                    if(frecuencia <= 80) frecuencia = 108;
                    break;
                
                case 'e':
                    dejar = false;
                    break;
                    return;
                default:
                    cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            }
        } while(dejar);
    }
    
    void display(){
        cout << "Nombre: " << this->nombre << endl;
        cout << "Frecuencia: " << this->frecuencia << endl;
    }
    
};

void menu(EmisoraFM& emisora){
    int opcion;
    cout << "Bienvenido al programa de emisora de radio FM." << endl;
    cout << "1. Mostrar Emisora" << endl;
    cout << "2. Cambiar Frecuencia" << endl;
    cout << "3. Salir" << endl << endl;
    do {
        cin >> opcion;
        switch(opcion){
            case 1:
            emisora.display();
            break;
            case 2:
            emisora.setFrecuencia();
            break;
            case 3:
            cout << "Adiós" << endl;
            break;
            default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
        }
    } while(opcion != 3);
}

int main(){
    EmisoraFM a("Mamame el huevo");
    menu(a);

    return 0;
}