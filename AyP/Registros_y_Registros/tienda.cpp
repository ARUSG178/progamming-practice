#include <iostream>
#include <conio.h>
using namespace std;

struct productos {
    char codigo;
    char descripcion[90];
    char nombre[20];
    double precio;
}productos[10];

void ingresarProductos(){
    for(int i = 0; i < 10; i++){
        cout << "Ingrese el codigo del producto (A, B, C, D, E...): " << endl;
        cin >> productos[i].codigo;
        cin.ignore();
        cout << "Ingrese la descripcion del producto: " << endl;
        cin.getline(productos[i].descripcion, 90, '\n');
        cout << "Ingrese el nombre del producto: " << endl;
        cin.getline(productos[i].nombre, 20, '\n');
        cout << "Ingrese el precio del producto: " << endl;
        cin >> productos[i].precio;
        cout << "Producto agregado con exito" << endl;
        cout << endl;
    }
}

bool buscarProducto(char codigo){
    for(int i = 0; i < 10; i++){
        if(productos[i].codigo == codigo){
            return true;
        }
    }
    return false;
}

int main(){
    char codigoBuscar;
    ingresarProductos();
    
    for(int i = 0; i < 10; i++){
        if(toupper(productos[i].codigo == 'C')){
            productos[i].precio *= 1.10;
            cout << "El producto" << productos[i].nombre << "Su nuevo precio ahora es: " << productos[i].precio << endl;
        }
    }

    cout << "Ingrese el código del producto a buscar: ";
    cin >> codigoBuscar;

    if(buscarProducto(codigoBuscar)) { cout << "El producto existe." << endl;}
    else { cout << "El producto no existe." << endl; }

    return 0;
}