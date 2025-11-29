#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
    static int contadorCodigo;
    int codigo;
    string descripcion;
    double precio;
    int fecha;
    static double iva;

public:
    Producto(string descripcion, double precio, int fecha) {
        this->codigo = contadorCodigo++;
        this->descripcion = descripcion;
        this->precio = precio;
        this->fecha = fecha;
    }

    int getCodigo() {
        return this->codigo;
    }

    string getDescripcion() {
        return this->descripcion;
    }

    double getPrecio() {
        return this->precio;
    }

    int getFecha() {
        return this->fecha;
    }

    void setDescripcion(string descripcion) {
        this->descripcion = descripcion;
    }

    void setPrecio(double precio) {
        this->precio = precio;
    }

    void setFecha(int fecha) {
        this->fecha = fecha;
    }

    double calcularPrecioConIva() {
        return this->precio * (1 + iva / 100);
    }

    static double getIva() {
        return iva;
    }

    static void setIva(double iva) {
        Producto::iva = iva;
    }
};

int Producto::contadorCodigo = 1;
double Producto::iva = 12;

int main() {
    Producto producto("Camisa", 100, 2020);
    cout << "Código: " << producto.getCodigo() << endl;
    cout << "Descripción: " << producto.getDescripcion() << endl;
    cout << "Precio: " << producto.getPrecio() << endl;
    cout << "Fecha: " << producto.getFecha() << endl;
    cout << "Precio con IVA: " << producto.calcularPrecioConIva() << endl;
    return 0;
}