#include <iostream>
#include <string>
using namespace std;

struct Product {
    string code;
    string description;
    string type;
    string name;
    double price;
};

struct Store {
    Product products[10];
};

void insertProducts(Store &s, int count) {
    for (int i = 0; i < count; ++i) {
        cout << "Producto " << i+1 << ":\n";
        cin >> s.products[i].code;
        cin >> s.products[i].description;
        cin >> s.products[i].type;
        cin >> s.products[i].name;
        cin >> s.products[i].price;
    }
}

void changePrices(Store &s, const string &type) {
    for (int i = 0; i < 10; ++i) {
        if(s.products[i].type == type) {
            s.products[i].price *= 1.1; // aumenta 10%
        }
    }
}

bool searchProduct(const Store &s, const string &code) {
    for (int i = 0; i < 10; i++) {
        if (s.products[i].code == code) return true;
    }
    return false;
}

int main (){
    Store store;

    // Insertar 5 productos
    insertProducts(store, 5);

    // Cambiar precios de un tipo
    string type;
    cout << "Ingrese tipo para aumentar precio: ";
    cin >> type;
    changePrices(store, type);

    // Buscar producto por código
    string code;
    cout << "Ingrese código a buscar: ";
    cin >> code;
    if(searchProduct(store, code)) {
        cout << "Producto encontrado.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }

    return 0;
}