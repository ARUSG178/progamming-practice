#include <iostream>
#include <string>
using namespace std;

class Producto {
    double precioBase;
    double descuento;
    double ivaPercent; 

public:
    Producto(double p, double des = 0.0, double iva = 0.0) : precioBase(p), descuento(des), ivaPercent(iva) {}
    
    // Precio final = precioBase + IVA - descuento
    double getPrecioFinal() const {
        double iva = precioBase * (ivaPercent / 100.0);
        return precioBase + iva - descuento;
    }
};

class Libro : public Producto {
    private:
        string titulo;
        string autor;
        int ano_publicacion;
        string editorial;
        string ISBN;

    public:
        // precio: precio base; por defecto aplica IVA 12%
        Libro(const string &t, const string &a, int ano, const string &e, const string &i, double precio, double desPercent = 20.0, double ivaPercent = 12.0)
            : Producto(precio, desPercent, ivaPercent), titulo(t), autor(a), ano_publicacion(ano), editorial(e), ISBN(i) {}

        double getPrecio() const { return getPrecioFinal(); }
    };

    class CD : public Producto {
        string titulo;
        string interprete;
        int ano_publicacion;

    public:
        CD(const string &t, const string &interp, int ano, double precio, double desPercent = 10.0, double ivaPercent = 12.0)
            : Producto(precio, desPercent, ivaPercent), titulo(t), interprete(interp), ano_publicacion(ano) {}

        double getPrecio() const { return getPrecioFinal(); }
};

int main() {
    Libro libro("El Principito", "Saint-Exupéry", 1943, "Reyero", "ISBN-1234", 100.0);
    CD disco("Thriller", "Michael Jackson", 1982, 50.0, 12.0);

    cout << "Precio final libro (con IVA): " << libro.getPrecio() << "\n";

    cout << "Precio final CD (con IVA): " << disco.getPrecio() << "\n";

    return 0;
}
